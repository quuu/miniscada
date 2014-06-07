#ifndef LEGEND_H
#define LEGEND_H

#include <vector>
#include <QPixmap>
#include "label.h"
#include "orientation.h"
#include "geometry.h"

class Legend
{
public:
    //Legend();
    Legend(Orientation orientation = vertical);
    void addLabel(Label label);
    void removeLabel(int id);
    Label& getLabel(int id);
    void setOrientation(Orientation orientation);
    Orientation getOrientation();
    void setGeometry(Geometry geometry);
    Geometry& getGeometry();
    int getLabelsCount();
    QPixmap draw();
    void refresh();
private:
    std::vector<Label> labels;
    Orientation orientation;
    Geometry geometry;
    QPixmap pixmap;
};

#endif // LEGEND_H
