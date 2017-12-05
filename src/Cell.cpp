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
          radius(radius),
          randomGen(ran),
          cellType(cellType)
{
    this->angle = 2.0 * M_PI * (0.5 - this->randomGen->use(0x0000)); //Random initial angle

    this->forceX = 0.0;
    this->forceY = 0.0;

    initParams();
}

void Cell::initParams() {
    double Ehh = 1.0 / computeIEeff(Eh, Eh, nu_h, nu_h);
    double Ehc = 1.0 / computeIEeff(Eh, Ec, nu_h, nu_c);
    double Ecc = 1.0 / computeIEeff(Ec, Ec, nu_c, nu_c);
    double Rhh = 1.0 / computeIReff(cellRadius, cellRadius);
    double Rhc = Rhh;
    double Rcc = Rhh;

    this->A[0] = (4.0 / 3.0) * Ehh * sqrt(Rhh) / F0;
    this->A[1] = (4.0 / 3.0) * Ehc * sqrt(Rhc) / F0;
    this->A[2] = (4.0 / 3.0) * Ecc * sqrt(Rcc) / F0;
    this->B[0] = sqrt(8 * M_PI * Ehh * sigma_hh) * pow(Rhh, 0.75) / F0;
    this->B[1] = sqrt(8 * M_PI * Ehc * sigma_hc) * pow(Rhc, 0.75) / F0;
    this->B[2] = sqrt(8 * M_PI * Ecc * sigma_cc) * pow(Rcc, 0.75) / F0;
}

double Cell::computeIEeff(double E1, double E2, double v1, double v2) {
    return ((1.0 - pow(v1, 2)) / E1) + ((1.0 - pow(v2, 2)) / E2);
}

double Cell::computeIReff(double R1, double R2) {
    return (1.0 / R1) + (1.0 / R2);
}

double Cell::computeJKRPotential(double h, int type) {

    /* contact types (3): 0 -> HH, 1 -> HU, 2 -> UU */
//    double A[3] = {30.0, 15.0, 20.0}; //v1.0
//    double B[3] = {11.0, 4.5, 7.0}; //v1.0

//    double A[3] = {26.6667, 15.2381, 10.6667}; //v2.0
//    double B[3] = {14.1796, 3.38958, 4.91197}; //v2.0

    double h34 = pow(h, 0.75);
    double h32 = h34 * h34;

    return (this->A[type] * h32) - (this->B[type] * h34);
}

void Cell::computeForce(class Cell * neighbor) {

    if( (this->positionX + this->positionY) == (neighbor->positionX + neighbor->positionY) )
        return;

    double cost = cos(this->angle);
    double sint = sin(this->angle);

    this->forceX = V0 * cost;
    this->forceY = V0 * sint;

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

///TODO: finish implementation
Cell * Cell::divide() {

    double distX = 0.7;
    double distY = 0.7;

    switch( (int) this->angle ) {
        case 0 ... 89:
            distX *= -1;
            distY *= -1;
            break;

        case 90 ... 179:
            distY *= -1;
            break;

        case 270 ... 359:
            distX *= -1;
            break;

        default:
            break;
    }
    auto * nCell = new Cell(this->positionX + distX, this->positionY + distY,
                            this->radius, this->cellType, this->randomGen);
    nCell->angle = M_PI + this->angle;

    return nCell;
}

short Cell::type() {
    return this->cellType;
}

void Cell::initMSD() {
    this->initX = this->positionX;
    this->initY = this->positionY;
}

double Cell::computeSquaredDisplacement() {
    return (this->positionX - this->initX) * (this->positionX - this->initX)
           + (this->positionY - this->initY) * (this->positionY - this->initY);
}
