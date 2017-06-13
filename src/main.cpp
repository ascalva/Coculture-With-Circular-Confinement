/**
 * filename: main.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Simulate the interactions between two different types of cells
 *          (cancerous vs healthy)
 */

#include <iostream>

#include "../include/Simulation.h"

using namespace std;

int main( void ) {
    FILE * fp1 = fopen("out1","w");
    Simulation coCulture(fp1);

#ifndef GROW
    coCulture.populate();
    coCulture.grow();
#else
    //other way to populate
#endif
    coCulture.run();

    fclose(fp1);
    return 0;
}
