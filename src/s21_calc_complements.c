#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  matrix_oper operations = OK;
  if (not_eq_col_row(A)) {
    operations = CALC_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
      operations = INCOR_MATRIX;
    } else {
      if (A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        matrix_t minor;
        double min_res = 0.0;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor) != OK) {
              operations = INCOR_MATRIX;
            } else {
              matrix_minor(A, &minor, i, j);
              if (s21_determinant(&minor, &min_res) != 0) {
                operations = INCOR_MATRIX;
              } else {
                result->matrix[i][j] = pow(-1, j + i) * min_res;
              }
            }
            s21_remove_matrix(&minor);
          }
        }
      }
    }
  }
  return operations;
}
