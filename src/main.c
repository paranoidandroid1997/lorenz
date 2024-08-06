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
  size_t timeSteps = 100000;
  float dt = 10E-4;
  Mat *t = createMat(timeSteps + 1, 1);

  // Init conditions
  float currTime = 0.0f;
  size_t currStep = 0;

  Mat *xk = createMat(3, 1);
  matSet(xk, 0, 0, 1.0);
  matSet(xk, 1, 0, 1.0);
  matSet(xk, 2, 0, 1.0);

  Mat *xkp1;

  // Store results
  Mat *Res = createMat(3, timeSteps + 1);

  while (currStep <= timeSteps) {
    matColSet(Res, currStep, xk);
    matSet(t, currStep, 0, currTime);
    xkp1 = rkStep(xk, dt);
    freeMat(xk);
    xk = xkp1;
    currStep++;
    currTime += dt;
  }

  writeMat(Res, "./output/state.txt");
  writeMat(t, "./output/time.txt");

  freeMat(xkp1);
  freeMat(t);
  freeMat(Res);
  return 0;
}
