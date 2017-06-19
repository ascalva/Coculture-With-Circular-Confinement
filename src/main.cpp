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

    Simulation coCulture;
    coCulture.populate();
    coCulture.run();

    return 0;
}
