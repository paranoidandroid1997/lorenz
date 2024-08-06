#pragma once

#include "Mat.h"

Mat *lorenz(Mat *xk) {
  // Params
  double sigma = 10.0;
  double beta = 8.0 / 3.0;
  double rho = 28.0;

  // Easier to use but probably inefficient
  double x0 = matGet(xk, 0, 0);
  double x1 = matGet(xk, 1, 0);
  double x2 = matGet(xk, 2, 0);

  // Lorenz ODE system
  double dx0 = sigma * (x1 - x0);
  double dx1 = x0 * (rho - x2) - x1;
  double dx2 = x0 * x1 - beta * x2;

  Mat *dxdt = createMat(3, 1);
  matSet(dxdt, 0, 0, dx0);
  matSet(dxdt, 1, 0, dx1);
  matSet(dxdt, 2, 0, dx2);

  return dxdt;
}
