#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  matrix_oper operations = OK;
  if (incor_matrix(A)) {
    operations = INCOR_MATRIX;
  } else if (not_eq_col_row(A)) {
    operations = CALC_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    matrix_t minor_matrix;
    double minor = 0.0;
    double res_det = 0.0;
    for (int j = 0; j < A->columns; j++) {
      if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix) != OK) {
        operations = INCOR_MATRIX;
      } else {
        matrix_minor(A, &minor_matrix, 0, j);
        if (s21_determinant(&minor_matrix, &minor) != 0) {
          operations = INCOR_MATRIX;
        } else {
          int sign = pow((-1), j + 2);
          res_det += sign * A->matrix[0][j] * minor;
        }
        s21_remove_matrix(&minor_matrix);
      }
    }
    *result = res_det;
  }
  return operations;
}
