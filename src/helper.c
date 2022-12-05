#include "s21_matrix.h"

void matrix_minor(matrix_t *A, matrix_t *minor, int row, int column) {
  int columns_minor = 0, rows_minor = 0, flag = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i != row && j != column) {
        minor->matrix[rows_minor][columns_minor] = A->matrix[i][j];
        columns_minor++;
        flag = 1;
      }
    }
    if (flag == 1) {
      rows_minor++;
      columns_minor = 0;
      flag = 0;
    }
  }
}

int negative_sign(matrix_t *A, matrix_t *B) {
  return A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0;
}

int incor_matrix(matrix_t *A) {
  return A->matrix == NULL || A->rows <= 0 || A->columns <= 0;
}

int not_eq (matrix_t * A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

int not_eq_col_row(matrix_t *A) { return A->rows != A->columns; }
