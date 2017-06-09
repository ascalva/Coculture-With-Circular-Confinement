/**
 * filename: Cell.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Abstract superclass for different types of cells (subclasses)
 */

#include "Cell.h"

Cell::Cell(double x, double y, double radius, short cellType)
        : positionX(x),
          positionY(y),
          radius(radius),
          cellType(cellType)
{
    this->angle = 2.0 * M_PI * (0.5 - ran2(&seed)); //Random initial angle

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

    double * dx = nullptr;
    double * dy = nullptr;
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

void Cell::move(double dt, float R) {

    double dxt = this->forceX * dt;
    double dyt = this->forceY * dt;
    this->positionX = this->positionX + dxt;
    this->positionY = this->positionY + dyt;

    this->angle += facang * computeAngle(&seed);

    bool xSign = this->positionX >= 0;
    bool ySign = this->positionY >= 0;

    //Elastic walls
    if( (this->positionX * this->positionX) > (R * R) ) {
        this->angle += M_PI;
        if( xSign && ySign ) {
            this->positionX -= dxt;
            this->positionY -= dyt;
        } if( xSign && !ySign ) {
            this->positionX -= dxt;
            this->positionY += dyt;
        } if( !xSign && ySign ) {
            this->positionX += dxt;
            this->positionX -= dyt;
        } if( !xSign && !ySign ) {
            this->positionX += dxt;
            this->positionY += dyt;
        }
    }
}

void Cell::modGrowth(double rate) {
    this->radius += rate;
}

///Note to later me: Maybe implement cells with a specific ID, better track particular cells
std::tuple<double, double, double>Cell::getValues() {

    return std::make_tuple(this->positionX, this->positionY, this->angle);
}

double Cell::computeAngle(long *idum) {
    static int iset = 0;
    static double gset;
    double fac,rsq,v1,v2;

    if(iset == 0) {
        do {
            v1 = 2.0 * ran2(idum) - 1.0;
            v2 = 2.0 * ran2(idum) - 1.0;
            rsq=v1*v1+v2*v2;
        } while( rsq >= 1.0 || rsq == 0.0 );

        fac = sqrt(-2.0*log(rsq)/rsq);
        gset = v1 * fac;
        iset = 1;
        return v2 * fac;
    } else {
        iset = 0;
        return gset;
    }
}

short Cell::type() {
    return this->cellType;
}