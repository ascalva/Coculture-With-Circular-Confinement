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

double Cell::computeDistance(class Cell neighbor, double * dx, double * dy) {

    *dx = this->positionX - neighbor.positionX;
    *dy = this->positionY - neighbor.positionY;

    return ((*dx) * (*dx)) + ((*dy) * (*dy));
}

double Cell::computeJKRPotential(double h, int type) {

    double h34 = pow(h, 0.75);
    double h32 = h34 * h34;

    return (A[type] * h32) - (B[type] * h34);
}

void Cell::computeForce(class Cell neighbor) {

    double cost = cos(this->angle);
    double sint = sin(this->angle);

    this->forceX = V0 * cost;
    this->forceY = V0 * sint;

    double * dx = (double *) 0;
    double * dy = (double *) 0;
    double drsq = computeDistance(neighbor, dx, dy);

    if( drsq >= 0 && drsq < (rc * rc) ) {
        double dr = sqrt(drsq);
        double fval = computeJKRPotential(1.0 - dr, this->type() + neighbor.type()) / dr;

        double fxtmp = fval * (*dx);
        double fytmp = fval * (*dy);

        this->forceX += fxtmp;
        this->forceY += fytmp;

        neighbor.forceX += -fxtmp;
        neighbor.forceY += -fytmp;
    }
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
