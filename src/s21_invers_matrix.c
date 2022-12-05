#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  matrix_oper operations = OK;
  if (incor_matrix(A)) {
    operations = INCOR_MATRIX;
  } else if (not_eq_col_row(A)) {
    operations = CALC_ERROR;
  } else {
    double d_res = 0.0;
    if (s21_determinant(A, &d_res) != OK) {
      operations = CALC_ERROR;
    } else if (fabs(d_res) <= S21_EPS) {
      operations = CALC_ERROR;
    } else {
      s21_determinant(A, &d_res);
      matrix_t inv_of, inv_to;
      s21_calc_complements(A, &inv_of);
      s21_transpose(&inv_of, &inv_to);
      int err = s21_mult_number(&inv_to, (1.0 / d_res), result);
      if (err != 0) {
        operations = INCOR_MATRIX;
      }
      s21_remove_matrix(&inv_to);
      s21_remove_matrix(&inv_of);
    }
  }
  return operations;
}
