#pragma once

#include "Mat.h"
#include "lorenz.h"

Mat *rkStep(Mat *xk, float h) {
  double b1 = 1.0 / 6.0;
  double b2 = 1.0 / 3.0;
  double b3 = 1.0 / 3.0;
  double b4 = 1.0 / 6.0;
  double a21 = 1.0 / 2.0;
  double a32 = 1.0 / 2.0;
  double a43 = 1.0;

  Mat *k1 = lorenz(xk);

  Mat *k2Shift = scaleMat(k1, h * a21);
  Mat *k2In = addMat(xk, k2Shift);
  Mat *k2 = lorenz(k2In);
  freeMat(k2Shift);
  freeMat(k2In);

  Mat *k3Shift = scaleMat(k2, h * a32);
  Mat *k3In = addMat(xk, k3Shift);
  Mat *k3 = lorenz(k3In);
  freeMat(k3Shift);
  freeMat(k3In);

  Mat *k4Shift = scaleMat(k3, h * a43);
  Mat *k4In = addMat(xk, k4Shift);
  Mat *k4 = lorenz(k4In);
  freeMat(k4Shift);
  freeMat(k4In);

  Mat *k1S = scaleMat(k1, h * b1);
  Mat *k2S = scaleMat(k2, h * b2);
  Mat *k3S = scaleMat(k3, h * b3);
  Mat *k4S = scaleMat(k4, h * b4);

  freeMat(k1);
  freeMat(k2);
  freeMat(k3);
  freeMat(k4);

  Mat* t1 = addMat(k1S, k2S);
  Mat* t2 = addMat(k3S, k4S);
  Mat* t3 = addMat(t1, t2);
  freeMat(t1);
  freeMat(t2);
  
  Mat* xkp1 = addMat(xk, t3);
  freeMat(t3);

  return xkp1;
}
