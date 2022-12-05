#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  matrix_oper operations = OK;
  if (incor_matrix(A)) {
    operations = INCOR_MATRIX;
  } else {
    if (s21_create_matrix(A->columns, A->rows, result) != OK) {
      operations = INCOR_MATRIX;
    } else {
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->rows; j++) {
          result->matrix[i][j] = 0;
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  }
  return operations;
}
