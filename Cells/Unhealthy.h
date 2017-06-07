/**
 * filename: Unhealthy.h
 *
 * @author: Alberto Serrano
 *
 * purpose: Contains all declarations, macros and most documentation
 */

#ifndef COCULTURE_UNHEALTHY_H
#define COCULTURE_UNHEALTHY_H


#include "Cell.h"

class Unhealthy: public Cell {

public:

    //Constructor
    Unhealthy(double x, double y, double radius);

    void computeForce(class Cell neighbor);

    void move();

    void computeAngle();

    bool type();
};


#endif //COCULTURE_UNHEALTHY_H
