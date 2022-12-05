#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  matrix_eq result = SUCCESS;
  if (not_eq (A, B)) {
    result = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > S21_EPS) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}
