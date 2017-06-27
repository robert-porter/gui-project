#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QtOpenGL>


enum SHAPE_TYPE {
    POINT = 0,
    LINE = 1,
    TRIANGLE = 2,
    HEXAGON = 3,
    QUAD = 4,
    CUBE = 5,
    NUM_SHAPES = 6
};

struct MorphShape {
    SHAPE_TYPE type;
    float morphBegin;
    float morphEnd;
    float transition;
};

class GraphicsView : public QGLWidget
{
public:
    GraphicsView(QWidget *parent);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
private:
    QTimer animationTimer;
    QTime time;
    MorphShape shape;
};

#endif // GRAPHICSVIEW_H
