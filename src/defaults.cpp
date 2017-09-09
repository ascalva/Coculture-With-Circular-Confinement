/**
 * filename: defaults.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Assigns all globals their constant values, may be altered using program arguments
 */

#include "../include/defaults.h"

int confinementRadius = 9;

float cellRadius = 0.5;

double DT = 0.001;

double TMAX = 100000.0;

int TGAP = 100;

double PHI = 1.05;

float RATIO = 1.0;

double INIT_MIN_SPACING = 0.721; //Original: 0.77

double V0 = 0.4;

double RC = 1.0;

double DCOEF_ANG = 0.05; //0.005

int startMSD = 0;

long SEED1 = -8838317;

long SEED2 = -1872371;
