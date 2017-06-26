#include "graphicsview.h"
#include <iostream>

struct Vector3 {
    Vector3() { }
    Vector3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
    operator const float *() const { return &x; }
    float x, y, z;
};

void drawPoint(const Vector3 &p) {
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex3f(p.x, p.y, p.z);
    glEnd();
}

void drawSegment(const Vector3& a, const Vector3 &b) {
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(a.x, a.y, a.z);
    glVertex3f(b.x, b.y, b.z);
    glEnd();
}

void drawTriangle(const Vector3& a, const Vector3 &b, const Vector3 &c) {
    glLineWidth(2);
    glBegin(GL_TRIANGLES);
    glVertex3f(a.x, a.y, a.z);
    glVertex3f(b.x, b.y, b.z);
    glVertex3f(c.x, c.y, c.z);
    glEnd();
}

void drawQuad(const Vector3 &p, float w, float h) {
    float hw = 0.5f * w;
    float hh = 0.5f * h;

    glBegin(GL_QUADS);
    glVertex3f(p.x + hw, p.y + hh, p.z);
    glVertex3f(p.x - hw, p.y + hh, p.z);
    glVertex3f(p.x - hw, p.y - hh, p.z);
    glVertex3f(p.x + hw, p.y - hh, p.z);
    glEnd();
}

void drawHexagon(const Vector3 &p, float r) {
    glBegin(GL_POLYGON);
    for(int i = 0; i < 6; i++) {
        float theta = 2.0f * M_PI / 6.0f + float(i)*2.0f*M_PI / 6.0f;
        glVertex3f(p.x + r * cos(theta), p.y + r * sin(theta), p.z);
    }
    glEnd();
}

void drawCube(const Vector3 &p, float w, float h, float d) {
    float hw = 0.5f * w;
    float hh = 0.5f * h;
    float hd = 0.5f * d;
    const Vector3 LBF(-hw, -hh,  hd);
    const Vector3 RBF(hw,  -hh,  hd);
    const Vector3 RTF(hw,  hh,   hd);
    const Vector3 LTF(-hw, hh,   hd);
    const Vector3 LBB(-hw, -hh,  -hd);
    const Vector3 RBB(hw,  -hh,  -hd);
    const Vector3 RTB(hw,  hh,   -hd);
    const Vector3 LTB(-hw, hh,   -hd);

    glBegin(GL_QUADS);
    glVertex3fv(LBF);
    glVertex3fv(RBF);
    glVertex3fv(RTF);
    glVertex3fv(LTF);

    glVertex3fv(LBB);
    glVertex3fv(RBB);
    glVertex3fv(RTB);
    glVertex3fv(LTB);

    glVertex3fv(LBF);
    glVertex3fv(LTF);
    glVertex3fv(LTB);
    glVertex3fv(LBB);

    glVertex3fv(RBF);
    glVertex3fv(RTF);
    glVertex3fv(RTB);
    glVertex3fv(RBB);

    glVertex3fv(RTF);
    glVertex3fv(LTF);
    glVertex3fv(LTB);
    glVertex3fv(RTB);

    glVertex3fv(RBF);
    glVertex3fv(LBF);
    glVertex3fv(LBB);
    glVertex3fv(RBB);

    glEnd();

}

GraphicsView::GraphicsView(QWidget *parent) : QGLWidget(parent)
{
    this->setFixedSize(800, 800);
}


void GraphicsView::initializeGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void GraphicsView::paintGL() {

    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );


    //drawPoint(Vector3(0.8, 0.7, 1));
    //drawSegment(Vector3(0, 0, 0), Vector3(1, 1, 1));
    //drawTriangle(Vector3(0, 0, 0), Vector3(0.4, 0.4, 0.4), Vector3(0, 1, -1));
    //drawQuad(Vector3(0, 0, 0), 0.3, 0.2);
    //drawHexagon(Vector3(0, 0, 1), 1.0f);
    glRotatef(QTime::currentTime().msec() * 0.001f, 0.3, 0.1, 0.3);
    drawCube(Vector3(0, 0, 0), 0.3, 0.2, 0.6);

    glFlush ();

    update();
}

void GraphicsView::resizeGL(int w, int h) {
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}
