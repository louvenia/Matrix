#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  matrix_oper operations = OK;
  if (negative_sign(A, B)) {
    operations = INCOR_MATRIX;
  } else if (not_eq (A, B)) {
    operations = CALC_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
      operations = INCOR_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = 0;
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return operations;
}
