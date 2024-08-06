// IO
#include <stdio.h>
// Standard types
#include <stdint.h>
// Basic functionality
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
      printf("%f", mat->dat[(i)*mat->cols + j]);
    }
    printf("\n");
  }
}
int main() {
  
  Mat *t = createMat(10, 10);

  printMat(t);

  freeMat(t);
  return 0;
}
