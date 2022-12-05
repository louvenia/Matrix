#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  matrix_oper operations = OK;
  if (rows <= 0 || columns <= 0) {
    operations = INCOR_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    } else {
      operations = CALC_ERROR;
    }
  }
  return operations;
}
