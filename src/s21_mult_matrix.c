#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  matrix_oper operations = OK;
  if (incor_matrix(A) || incor_matrix(B)) {
    operations = INCOR_MATRIX;
  } else if (A->columns != B->rows) {
    operations = CALC_ERROR;
  } else {
    if (s21_create_matrix(A->rows, B->columns, result) != OK) {
      operations = INCOR_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return operations;
}
