/**
 * filename: defaults.h
 *
 * @author: Alberto Serrano
 *
 * purpose: Define all global variables
 */

#ifndef COCULTURE_DEFAULTS_H
#define COCULTURE_DEFAULTS_H

/**
 * The radius of the confined area in which the cells live
 */
extern int confinementRadius;

/**
 * Radius of all cells (cancer and healthy)
 */
extern float cellRadius;

/**
 * Max amount of time for which the simulation will be running
 */
extern double TMAX;

/**
 * Time step in simulation
 */
extern double DT;

/**
 * Interval by which program outputs data
 */
extern int TGAP;

/**
 * Packing fraction
 */
extern double PHI;

/**
 * Ratio between healthy and cancer cells
 */
extern float RATIO;

/**
 * Minimum spacing needed between two cells when populating the simulation
 */
extern double INIT_MIN_SPACING;

/**
 * Self-propulsion constant
 */
extern double V0;

extern double RC;

/**
 * Angular diffusion coefficient
 */
extern double DCOEF_ANG;

/**
 * Use for the randomGen class to compute random numbers
 */
extern long SEED1;

/**
 * Use for the randomGen class to compute random numbers
 */
extern long SEED2;

#endif //COCULTURE_DEFAULTS_H
