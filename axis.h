#ifndef AXIS_H
#define AXIS_H

#include "label.h"
#include "linestyle.h"
//#include "font.h"
#include <QFont>
#include <QPixmap>
#include <QFontMetrics>

enum Position{
    top,
    bottom,
    left,
    right
};

enum Direction{
    inside,
    outside,
    middle
};

class Axis
{
public:
    Axis();
    void setLabel(Label label);
    Label getLabel();
    void setLineStyle(LineStyle style);
    LineStyle getLineStyle();
    void setTick(double tick);
    double getTick();
    void setAutoscale(bool autoscale);
    bool getAutoscale();
    void setMin(double min);
    double getMin();
    void setMax(double max);
    double getMax();
    void setTickSize(int size);
    int getTickSize();
    void setTickDirection(Direction direction);
    Direction getTickDirection();
    void setUnitVisibility(bool visible);
    bool getUnitVisibility();
    void setFont(QFont font);
    QFont getFont();
    void setPosition(Position position);
    Position getPosition();
    void setUnit(QString unit);
    QString getUnit();
    void setGeometry(Geometry geometry);
    Geometry getGeometry();
    QPixmap draw();
private:
    Label label;
    LineStyle lineStyle;
    double tick;
    bool autoscale;
    double min;
    double max;
    int tickSize;
    Direction tickDirection;
    bool showUnit;
    QFont font;
    Position position;
    QString unit;
    Geometry geometry;
};

#endif // AXIS_H
