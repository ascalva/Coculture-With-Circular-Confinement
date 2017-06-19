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

#ifndef CMD_OUT
    FILE * fp1 = fopen("1.out","w");
#else
    FILE * fp1 = nullptr;
#endif

    Simulation coCulture(fp1);
    coCulture.populate();
    coCulture.run();

#ifndef CMD_OUT
    fclose(fp1);
#endif

    return 0;
}
