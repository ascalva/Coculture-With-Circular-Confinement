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
    this->angle = 2.0 * M_PI * (0.5 - ran2(&seed)); //Random angle

    this->forceX = 0.0;
    this->forceY = 0.0;
}

///TODO: Finish function
double Cell::computeDistance(class Cell neighbor) {

    double dx, dy, dr, h, drsq;

    dx = this->positionX - neighbor.positionX;
    dy = this->positionY - neighbor.positionY;
    drsq = (dx * dx) + (dy * dy);

    return drsq;
}

void Cell::move(double dt) {

    this->positionX = this->positionX + (this->forceX * dt);
    this->positionY = this->positionY + (this->forceY * dt);

    this->angle = this->angle; //not yet finished

    ///TODO: Circular, elastic confinement
}

void Cell::modGrowth(double rate) {
    this->radius += rate;
}
