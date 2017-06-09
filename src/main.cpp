/**
 * filename: main.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Simulate the interactions between two different types of cells
 *          (cancerous vs healthy)
 */

#include <iostream>

#include "Simulation.h"

using namespace std;

int main( void ) {
    FILE * fp1 = fopen("out1","w");
    Simulation coCulture(fp1);

    coCulture.populate();
    coCulture.grow();

    coCulture.run();

    fclose(fp1);
    return 0;
}
