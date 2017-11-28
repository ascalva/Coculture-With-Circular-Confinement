/**
 * filename: defaults.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Assigns all globals their constant values, may be altered using program arguments
 */

#include "../include/defaults.h"

int confinementRadius = 18;

float cellRadius = 0.5;

double DT = 0.001;

double TMAX = 2001.0;

int TGAP = 100;

double PHI = 0.2;

float RATIO = 1.0;

double INIT_MIN_SPACING = 0.721; //Original: 0.77

double V0 = 0.1;

double RC = 1.0;

double actCellSize = 20.0;

double healthyReproduction = 720000.0;

double unhealthyReproduction = 1080000.0;

double DCOEF_ANG = 0.1; //0.005

int maxHealthyDivides = 3;

int maxUnhealthyDivides = 3;

int startMSD = 0;

long SEED1 = -8838317;

long SEED2 = -1872371;
