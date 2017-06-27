#include "graphicsview.h"
#include <iostream>

struct Vector3 {
    Vector3() { }
    Vector3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
    operator const float *() const { return &x; }
    const Vector3& operator+(const Vector3 &rhs) const { return Vector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z); }
    const Vector3& operator-(const Vector3 &rhs) const { return Vector3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z); }
    float x, y, z;
};

const Vector3 &operator*(float s, const Vector3 &v) {
    return Vector3(s*v.x, s*v.y, s*v.z);
}

template<class T>
T lerp(const T &a, const T &b, float t) {
    return a + (t * (b - a));
}

Vector3 hexagonVertices[6];
Vector3 shapeColors[6];

MorphShape transition(MorphShape shape, float t) {
    if(t > shape.transition) {
        MorphShape newShape;
        newShape.type = SHAPE_TYPE((shape.type + 1) % NUM_SHAPES);
        newShape.morphBegin = t;
        newShape.morphEnd = t + 3.0f;
        newShape.transition = t + 3.5f;
        return newShape;
    }
    return shape;
}

void drawPoint(const Vector3 &p) {
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex3f(p.x, p.y, p.z);
    glEnd();
}

void drawSegment(const Vector3& a, const Vector3 &b, float w) {
    glLineWidth(w);
    glBegin(GL_LINES);
    glVertex3f(a.x, a.y, a.z);
    glVertex3f(b.x, b.y, b.z);
    glEnd();
}

void initHexagonVertices(float r) {
    for(int i = 0; i < 6; i++) {
        float theta = 1.0f * M_PI / 6.0f + float(i)*2.0f*M_PI / 6.0f;
        hexagonVertices[i] = Vector3(r * cos(theta), r * sin(theta), 0);
    }
}

void initColors() {
    shapeColors[0] = Vector3(1.0f, 0.0f, 0.0f);
    shapeColors[1] = Vector3(0.0f, 1.0f, 0.0f);
    shapeColors[2] = Vector3(0.0f, 0.0f, 1.0f);
    shapeColors[3] = Vector3(1.0f, 0.0f, 1.0f);
    shapeColors[4] = Vector3(1.0f, 1.0f, 0.0f);
    shapeColors[5] = Vector3(0.0f, 1.0f, 1.0f);
}

void drawPolygon(Vector3 *vertices, int n) {
    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++) {
        glVertex3fv(vertices[i]);
    }
    glEnd();
}


void drawCube(const Vector3 &a,
              const Vector3 &b,
              const Vector3 &c,
              const Vector3 &d,
              float depth,
              float t = 0.0f) {
    const Vector3 aa = a + Vector3(0, 0, depth);
    const Vector3 bb = b + Vector3(0, 0, depth);
    const Vector3 cc = c + Vector3(0, 0, depth);
    const Vector3 dd = d + Vector3(0, 0, depth);


    glBegin(GL_QUADS);
    glColor3fv(lerp(shapeColors[4], shapeColors[0], t));
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glVertex3fv(d);
    glColor3fv(lerp(shapeColors[1], shapeColors[0], t));
    glVertex3fv(aa);
    glVertex3fv(bb);
    glVertex3fv(cc);
    glVertex3fv(dd);
    glColor3fv(lerp(shapeColors[3], shapeColors[0], t));
    glVertex3fv(a);
    glVertex3fv(aa);
    glVertex3fv(bb);
    glVertex3fv(b);
    glColor3fv(lerp(shapeColors[2], shapeColors[0], t));
    glVertex3fv(b);
    glVertex3fv(bb);
    glVertex3fv(cc);
    glVertex3fv(c);
    glColor3fv(shapeColors[0]);
    glVertex3fv(c);
    glVertex3fv(cc);
    glVertex3fv(dd);
    glVertex3fv(d);
    glColor3fv(lerp(shapeColors[5], shapeColors[0], t));
    glVertex3fv(d);
    glVertex3fv(dd);
    glVertex3fv(aa);
    glVertex3fv(a);

    glEnd();

}

float clamp(float t, float a, float b) {
    if(t < a) return a;
    if(t > b) return b;
    return t;
}

void draw(MorphShape shape, float t) {

    float tl = clamp((t - shape.morphBegin) / (shape.morphEnd - shape.morphBegin), 0, 1);

    Vector3 p0 = hexagonVertices[3] + 0.5f * (hexagonVertices[5] - hexagonVertices[3]);
    Vector3 color0 = shapeColors[(shape.type - 1) % NUM_SHAPES];
    Vector3 color1 = shapeColors[shape.type];
    glColor3fv(lerp(color0, color1, tl));

    switch(shape.type) {
    case POINT:
        if(tl < 1.0f) {
            glPushMatrix();
            float s = lerp(1.0f, 0.02f, tl);
            Vector3 center(s * (0.5f * hexagonVertices[2] - hexagonVertices[0]).x,
                    s * (0.5f * hexagonVertices[3] - hexagonVertices[2]).y, s * 50);
            glTranslatef((p0.x-center.x) * tl, (p0.y-center.y) * tl, (p0.z-center.z)*tl);
            glScalef(s, s, s);

            drawCube(hexagonVertices[0],
                     hexagonVertices[2],
                     hexagonVertices[3],
                     hexagonVertices[5], -100, tl);
            glPopMatrix();
        }
        else
            drawPoint(p0);
        break;
    case LINE:
        drawSegment(lerp(p0, hexagonVertices[3], tl), lerp(p0, hexagonVertices[5], tl), lerp(4.0f, 2.0f, tl));
        break;
    case TRIANGLE: {
        Vector3 verts[] = {hexagonVertices[3],  hexagonVertices[5], lerp(p0, hexagonVertices[4], tl)};
        drawPolygon(verts, 3);
        break;
    }
    case HEXAGON: {
        Vector3 verts[] = {hexagonVertices[3],
                           hexagonVertices[4],
                           hexagonVertices[5],
                           lerp(hexagonVertices[5], hexagonVertices[0], tl),
                           lerp(p0, hexagonVertices[1], tl),
                           lerp(hexagonVertices[3], hexagonVertices[2], tl)};
        drawPolygon(verts,  6);
    }
        break;
    case QUAD: {
        Vector3 verts[] = {hexagonVertices[3],
                           lerp(hexagonVertices[4], p0, tl),
                           hexagonVertices[5],
                           hexagonVertices[0],
                           lerp(hexagonVertices[1], lerp(hexagonVertices[0], hexagonVertices[2], 0.5f), tl),
                           hexagonVertices[2]};
        drawPolygon(verts,  6);
    }
        break;
    case CUBE:
        drawCube(hexagonVertices[0],
                 hexagonVertices[2],
                 hexagonVertices[3],
                 hexagonVertices[5], lerp(0.0f, -100.0f, tl));
    }
}

GraphicsView::GraphicsView(QWidget *parent) : QGLWidget(parent)
{
    this->setFixedSize(800, 800);

    animationTimer.setSingleShot(false);
    connect(&animationTimer, SIGNAL(timeout()), this, SLOT(update()));
    animationTimer.start(25);
    time.start();
    initHexagonVertices(100);
    initColors();

}

void GraphicsView::initializeGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void GraphicsView::paintGL() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float ftime = time.elapsed() * 0.001f;
    glRotatef(ftime * 30, 0.4, 0, 0.5);
    shape = transition(shape, ftime);
    draw(shape, ftime);

    glFlush ();
}

void GraphicsView::resizeGL(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -200, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
