#include "rngExp.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h> 
#include <math.h>

rngExp::rngExp(double vseed) {
	seed=vseed;
}

double rngExp::rngExp::myrand() {
	return rand_r(&seed);
}

double rngExp::exp(double lambda) {
  double r = ((double)myrand() / (RAND_MAX));
   return  (-lambda * (log(1 - r)));

}
