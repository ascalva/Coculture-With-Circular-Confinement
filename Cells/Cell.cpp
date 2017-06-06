/**
 * filename: Cell.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Abstract superclass for different types of cells (subclasses)
 */

#include "Cell.h"

Cell::Cell(double x, double y, float radius = 1)
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

double Cell::ran2(long *idum) {
    int j;
    long k;
    static long idum2=123456789;
    static long iy=0;
    static long iv[NTAB];
    double temp;

    if (*idum <= 0) {
        if (-(*idum) < 1) *idum=1;
        else *idum = -(*idum);
        idum2=(*idum);
        for (j=NTAB+7;j>=0;j--) {
            k=(*idum)/IQ1;
            *idum=IA1*(*idum-k*IQ1)-k*IR1;
            if (*idum < 0) *idum += IM1;
            if (j < NTAB) iv[j] = *idum;
        }
        iy=iv[0];
    }
    k=(*idum)/IQ1;
    *idum=IA1*(*idum-k*IQ1)-k*IR1;
    if (*idum < 0) *idum += IM1;
    k=idum2/IQ2;
    idum2=IA2*(idum2-k*IQ2)-k*IR2;
    if (idum2 < 0) idum2 += IM2;
    j=iy/NDIV;
    iy=iv[j]-idum2;
    iv[j] = *idum;
    if (iy < 1) iy += IMM1;
    if ((temp=AM*iy) > RNMX) return RNMX;
    else return temp;
}