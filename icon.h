#ifndef ICON_H
#define ICON_H

#include "geometry.h"
//#include "color.h"
#include <QColor>

class Icon
{
public:
    Icon();
    Icon(QColor color, Geometry geometry = Geometry(0, 0, 10, 10));
    //Icon(Geometry geometry, QColor color);
    void setGeometry(Geometry geometry);
    Geometry &getGeometry();
    void setColor(QColor color);
    QColor getColor();
private:
    Geometry geometry;
    QColor color;
};

#endif // ICON_H
