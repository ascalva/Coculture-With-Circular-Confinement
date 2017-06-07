/**
 * filename: Cell.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Abstract superclass for different types of cells (subclasses)
 */

#include "Cell.h"

Cell::Cell(double x, double y, double radius)
        : positionX(x),
          positionY(y),
          radius(radius)
{
    this->angle = ran2(&seed);
}

double Cell::computeDistance(class Cell neighbor) {

    double dx, dy, dr, h, drsq;

    dx = this->positionX - neighbor.positionX;
    dy = this->positionY - neighbor.positionY;
    drsq = (dx * dx) + (dy * dy);


}
