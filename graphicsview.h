#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QtOpenGL>

class GraphicsView : public QGLWidget
{
public:
    GraphicsView(QWidget *parent);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // GRAPHICSVIEW_H
