#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// A matrix struct
typedef struct {
  size_t rows;
  size_t cols;
  double *dat;
} Mat;

Mat *createMat(size_t rows, size_t cols) {
  Mat *newMat = calloc(1, sizeof(Mat));
  newMat->rows = rows;
  newMat->cols = cols;
  newMat->dat = calloc(rows * cols, sizeof(double));

  return newMat;
}

void freeMat(Mat *mat) {
  free(mat->dat);
  free(mat);
}

void printMat(Mat *mat) {
  for (size_t i = 0; i < mat->rows; i++) {
    for (size_t j = 0; j < mat->cols; j++) {
      printf("%f ", mat->dat[(i)*mat->cols + j]);
    }
    printf("\n");
  }
}

void matSet(Mat *mat, size_t row, size_t col, double val) {
  mat->dat[mat->cols * (row) + col] = val;
}

double matGet(Mat *mat, size_t row, size_t col) {
  return mat->dat[mat->cols * (row) + col];
}

void matColSet(Mat *mat, size_t col, Mat *vec) {
  for (size_t i = 0; i < mat->rows; i++) {
    matSet(mat, i, col, matGet(vec, i, 0));
  }
}

Mat *addMat(Mat *m1, Mat *m2) {
  Mat *sumMat = createMat(m1->rows, m1->cols);

  // Could parallel
  for (size_t i = 0; i < m1->rows; i++) {
    for (size_t j = 0; j < m2->cols; j++) {
      double sum = matGet(m1, i, j) + matGet(m2, i, j);
      matSet(sumMat, i, j, sum);
    }
  }

  return sumMat;
}

Mat *scaleMat(Mat *mat, double a) {
  Mat *scaledMat = createMat(mat->rows, mat->cols);

  // Could parallel
  for (size_t i = 0; i < mat->rows; i++) {
    for (size_t j = 0; j < mat->cols; j++) {
      double scaledValue = a * matGet(mat, i, j);
      matSet(scaledMat, i, j, scaledValue);
    }
  }
  return scaledMat;
}

void writeMat(Mat *mat, char *fName) {
  FILE *f = fopen(fName, "w");
  for (size_t i = 0; i < mat->rows; i++) {
    for (size_t j = 0; j < mat->cols; j++) {
      fprintf(f, "%f ", matGet(mat, i, j));
    }
    fprintf(f, "\n");
  }
}
