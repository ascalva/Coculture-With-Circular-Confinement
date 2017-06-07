/**
 * filename: randomGen.h
 *
 * @author: Alberto Serrano
 *
 */

#ifndef COCULTURE_RANDOMGEN_H
#define COCULTURE_RANDOMGEN_H

#define IM1 2147483563
#define IM2 2147483399
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

long seed = -8838317;  //use large negative integers for seeds
long seed1 = -1872371;

/**
 * Compute a 'random' between 0 and 1
 *
 * (C) Copr. 1986-92 Numerical Recipes Software
 *
 * @param idum is the address of the seed used
 */
double ran2(long *idum);


#undef IM1
#undef IM2
#undef AM
#undef IMM1
#undef IA1
#undef IA2
#undef IQ1
#undef IQ2
#undef IR1
#undef IR2
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
#endif //COCULTURE_RANDOMGEN_H
