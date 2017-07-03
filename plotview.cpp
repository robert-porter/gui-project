#include "plotview.h"

PlotView::PlotView(QWidget *parent) : QGLWidget(parent)
{
    widgetWidth = 400;
    widgetHeight = 400;
    this->setFixedSize(widgetWidth, widgetHeight);
    a = 0;
    b = 0;
    c = 0;
    t = 0;
    numDivisions = 6;
    marginsFactor = 1.0f / float(numDivisions);
    ticFactor = 0.03f;
}

void PlotView::value(int a, int b, int c, int t) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->t = t;
    makeCurrent();
    resizeGL(0, 0);
    updateGL();
}

void PlotView::initializeGL() {

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void PlotView::drawGrid() {
    //TODO: draw outline...

    glColor3f(0.8f, 0.8f, 0.8f);
    glLineWidth(1.5f);

    float stepy = (plotY1 - plotY0) / float(numDivisions);
    float stepx = (plotX1 - plotX0) / float(numDivisions);

    for(float y = 0; y <= plotY1; y+=stepy) {
        glBegin(GL_LINES);
        glVertex3f(plotX0, y, 0);
        glVertex3f(plotX1, y, 0);
        glEnd();
    }

    for(float x = 0; x <= plotX1; x+=stepx) {
        glBegin(GL_LINES);
        glVertex3f(x, plotY0, 0);
        glVertex3f(x, plotY1, 0);
        glEnd();
    }
}

void PlotView::drawLabelsAndTics() {


    float stepy = (plotY1 - plotY0) / float(numDivisions);
    float stepx = (plotX1 - plotX0) / float(numDivisions);

    for(float y = stepy; y < plotY1; y+=stepy) {
        QString labelText = QString::number(y, 'f', 1);
        QFontMetrics fontMetrics(this->font());
        int pixelWidth = fontMetrics.width(labelText);
        int pixelHeight = fontMetrics.height();
        float width = plotWidth() * float(pixelWidth) / float(widgetWidth);
        float height = plotHeight() * float(pixelHeight) / float(widgetHeight);
        renderText(1.1f * -width, y - 0.25f * height, 0, labelText, font());

        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex3f(0, y, 0);
        glVertex3f(ticFactor * plotWidth(), y, 0);
        glEnd();
    }

    for(float x = stepx; x < plotX1; x+=stepx) {
        QString labelText = QString::number(x, 'f', 1);
        QFontMetrics fontMetrics(this->font());
        int pixelWidth = fontMetrics.width(labelText);
        int pixelHeight = fontMetrics.height();
        float width = plotWidth()* float(pixelWidth) / float(widgetWidth);
        float height = plotHeight() * float(pixelHeight) / float(widgetHeight);
        renderText(x - 0.5f * width, -0.7f * height, 0, labelText, font());

        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex3f(x, 0, 0);
        glVertex3f(x, ticFactor * plotHeight(), 0);
        glEnd();
    }
}

void PlotView::drawAxes() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINES);
    glVertex3f(plotX0, 0, 0);
    glVertex3f(plotX1, 0, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, plotY0, 0);
    glVertex3f(0, plotY1, 0);
    glEnd();

    float w = plotX1 - plotX0;
    float h = plotY1 - plotY0;
    glBegin(GL_TRIANGLES);
    glVertex3f(0, plotY1, 0);
    glVertex3f(0.015*w, plotY1-0.05*h, 0);
    glVertex3f(-0.015*w, plotY1-0.05*h, 0);

    glVertex3f(0, plotY0, 0);
    glVertex3f(0.015*w, plotY0+0.05*h, 0);
    glVertex3f(-0.015*w, plotY0+0.05*h, 0);

    glVertex3f(plotX1, 0, 0);
    glVertex3f( plotX1-0.05*w, 0.015*h, 0);
    glVertex3f(plotX1-0.05*w, -0.015*h, 0);

    glVertex3f(plotX0, 0, 0);
    glVertex3f( plotX0+0.05*w, 0.015*h, 0);
    glVertex3f(plotX0+0.05*w, -0.015*h, 0);
    glEnd();
}

void PlotView::drawGraph() {
    float step = 0.1f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(3.5f);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);

    glBegin(GL_LINE_STRIP);
    for(float x = 0.0f; x <= float(t); x+=step) {
        glVertex3f(x, f(x), 0.0f);
    }
    glVertex3f(t, f(t), 0.0f); // no gaps for fp error
    glEnd();


    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH, GL_NICEST);
    glPointSize(8.0f);
    glBegin(GL_POINTS);
        glVertex3f(0, f(0), 0.0f);
        glVertex3f(t, f(t), 0.0f);
    glEnd();
}

void PlotView::paintGL() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawGrid();
    drawAxes();
    drawLabelsAndTics();
    if(t != 0)
        drawGraph();

    glFlush ();
}


void PlotView::resizeGL(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    plotX0 = -marginsFactor*std::max(float(t), 1.0f);
    plotX1 = (1.0f + marginsFactor) * std::max(float(t), 1.0f);
    plotY0 = -marginsFactor*std::max(ymax(), 1.0f);
    plotY1 = (1.0f + marginsFactor) * std::max(ymax(), 1.0f);
    glOrtho(plotX0, plotX1, plotY0, plotY1, -200, 200);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
