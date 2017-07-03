#ifndef PLOTVIEW_H
#define PLOTVIEW_H

#include <QGLWidget>
#include <algorithm>
#include <limits>

class PlotView : public QGLWidget
{
    Q_OBJECT
public:
    PlotView(QWidget *parent);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void value(int a, int b, int c, int t);
protected:
    int a, b, c, t;
    float marginsFactor;
    float ticFactor;
    float plotX0;
    float plotX1;
    float plotY0;
    float plotY1;
    int numDivisions;
    int widgetWidth;
    int widgetHeight;

    void drawGrid();
    void drawAxes();
    void drawLabelsAndTics();
    void drawGraph();

    float plotWidth() const { return plotX1 - plotX0; }
    float plotHeight() const { return plotY1 - plotY0; }
    float f(float x) const { return a + b*x + c*x*x; }

    float ymin() const {
        if(c != 0) {
            float x = float(-b) / float(2 * c);
            if(x > 0 && x < t)
                return std::min(f(x), std::min(f(0), f(t)));
        }
        // really just need this since a, b, c > 0...
        return std::min(f(0), f(t));
    }
    float ymax() const {
        if(c != 0) {
            float x = float(-b) / float(2 * c);
            if(x > 0 && x < t)
                return std::max(f(x), std::max(f(0), f(t)));
        }
        return std::max(f(0), f(t));
    }

};

#endif // PLOTVIEW_H
