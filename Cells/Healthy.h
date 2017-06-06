/**
 * filename: Healthy.h
 *
 * @author: Alberto Serrano
 *
 * purpose: Contains all declarations, macros and most documentation
 */

#ifndef COCULTURE_HEALTHY_H
#define COCULTURE_HEALTHY_H


#include "Cell.h"

class Healthy: public Cell {
public:

    //Constructor
    Healthy(double x, double y, float radius);

    void computeForce(class Cell neighbor);

    void move();

    void computeAngle();

    bool type();
};


#endif //COCULTURE_HEALTHY_H