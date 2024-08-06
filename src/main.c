// IO
#include <stdio.h>
// Standard types
#include <stdint.h>
// Basic functionality
#include <stdlib.h>
// Matrix struct
#include "Mat.h"
// Time stepper
#include "rk.h"

int main() {
  // Create time array
  size_t timeSteps = 10;
  float dt = 1.0f / timeSteps;
  Mat *t = createMat(timeSteps, 1);

  // Init conditions
  float currTime = 0.0f;
  size_t currStep = 0;

  Mat *xk = createMat(3, 1);
  matSet(xk, 0, 0, 1.0);
  matSet(xk, 1, 0, 1.0);
  matSet(xk, 2, 0, 1.0);

  Mat *xkp1;

  // Store results
  Mat* Res = createMat(3,timeSteps + 1);

  printMat(xk);
  printf("\n");

  while (currStep <= timeSteps) {
    matColSet(Res, currStep, xk);
    matSet(t, currStep, 0, currTime);
    xkp1 = rkStep(xk, dt);
    freeMat(xk);
    xk = xkp1;
    currStep++;
    currTime += dt;
  }


  freeMat(xkp1);
  freeMat(t);
  freeMat(Res);
  return 0;
}
