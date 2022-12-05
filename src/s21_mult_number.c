#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  matrix_oper operations = OK;
  if (incor_matrix(A)) {
    operations = INCOR_MATRIX;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
      operations = INCOR_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = 0;
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return operations;
}
