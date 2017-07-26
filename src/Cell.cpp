/**
 * filename: Cell.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Stores all relevant information for a given cell within the simulation
 */

#include "../include/Cell.h"

Cell::Cell(double x, double y, double radius, short cellType, class randomGen * ran)
        : positionX(x),
          positionY(y),
          initX(x),
          initY(y),
          radius(radius),
          randomGen(ran),
          cellType(cellType)
{
    this->angle = 2.0 * M_PI * (0.5 - this->randomGen->use(0x0000)); //Random initial angle

    this->forceX = 0.0;
    this->forceY = 0.0;
}

double Cell::computeJKRPotential(double h, int type) {

    /* contact types (3): 0 -> HH, 1 -> HU, 2 -> UU */
    double A[3] = {30.0, 15.0, 20.0}; //Original
    double B[3] = {11.0, 4.5, 7.0}; //Original

//    double A[3] = {40.0, 25.0, 30.0};

    double h34 = pow(h, 0.75);
    double h32 = h34 * h34;

    return (A[type] * h32) - (B[type] * h34);
}

void Cell::computeForce(class Cell * neighbor) {

    if( (this->positionX + this->positionY) == (neighbor->positionX + neighbor->positionY) )
        return;

    double cost = cos(this->angle);
    double sint = sin(this->angle);

    this->forceX = V0 * cost;
    this->forceY = V0 * sint;

#ifndef NO_FORCE
    double dx = this->positionX - neighbor->positionX;
    double dy = this->positionY - neighbor->positionY;
    double drsq = (dx * dx) + (dy * dy);

    double rc = RC;
    if( drsq < (rc * rc) ) {
        double dr = sqrt(drsq);
        double fval = computeJKRPotential((this->radius * 2) - dr, this->type() + neighbor->type()) / dr;

        double fxtmp = fval * dx;
        double fytmp = fval * dy;

        this->forceX += fxtmp;
        this->forceY += fytmp;

        neighbor->forceX += -fxtmp;
        neighbor->forceY += -fytmp;
    }
#endif
}

void Cell::move(double dt, float R) {

    double dxt = this->forceX * dt;
    double dyt = this->forceY * dt;

    double lastx = this->positionX;
    double lasty = this->positionY;

    this->positionX += dxt;
    this->positionY += dyt;

    double dcoefAngle = DCOEF_ANG;
    this->angle += sqrt(2 * dcoefAngle * dt) * computeAngle(0x0000); //facang * random noise

    //Elastic Walls
#ifdef PADDING
    double radsq = (this->positionX * this->positionX) + (this->positionY * this->positionY);
    if( radsq > ((R - this->radius) * (R - this->radius)) ) {
        double exitx = ((lastx + this->positionX) / 2) - this->radius;
        double exity = ((lasty + this->positionY) / 2) - this->radius;

        double exitRad = sqrt((exitx * exitx) + (exity * exity));
        exitx *= (R - this->radius) / exitRad;
        exity *= (R - this->radius) / exitRad;
        this->positionX = exitx;
        this->positionY = exity;

        double twiceProjFactor = 2.0 * ((exitx * this->forceX) + (exity * this->forceY)) / ((R - this->radius)*(R - this->radius));
        this->forceX -= (twiceProjFactor * exitx);
        this->forceY -= (twiceProjFactor * exity);

        this->positionX += this->forceX * dt;
        this->positionY += this->forceY * dt;
        this->angle -= atan(this->forceY/this->forceX);
    }
#else
    double radsq = (this->positionX * this->positionX) + (this->positionY * this->positionY);
    if( radsq > ((R) * (R)) ) {
        double exitx = (lastx + this->positionX) / 2;
        double exity = (lasty + this->positionY) / 2;

        double exitRad = sqrt((exitx * exitx) + (exity * exity));
        exitx *= (R) / exitRad;
        exity *= (R) / exitRad;
        this->positionX = exitx;
        this->positionY = exity;

        double twiceProjFactor = 2.0 * ((exitx * this->forceX) + (exity * this->forceY)) / ((R) * (R));
        this->forceX -= (twiceProjFactor * exitx);
        this->forceY -= (twiceProjFactor * exity);

        this->positionX += this->forceX * dt;
        this->positionY += this->forceY * dt;
        this->angle -= atan(this->forceY/this->forceX);
    }
#endif
}

std::tuple<double, double, double>Cell::getValues() {

    return std::make_tuple(this->positionX, this->positionY, this->angle);
}

double Cell::computeAngle(uint16_t idum) {
    static int iset = 0;
    static double gset;
    double fac,rsq,v1,v2;

    if(iset == 0) {
        do {
            v1 = 2.0 * this->randomGen->use(idum) - 1.0;
            v2 = 2.0 * this->randomGen->use(idum) - 1.0;
            rsq= (v1 * v1) + (v2 * v2);
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

double Cell::computeSquaredDisplacement() {
    return (this->positionX - this->initX) * (this->positionX - this->initX)
           + (this->positionY - this->initY) * (this->positionY - this->initY);

}
