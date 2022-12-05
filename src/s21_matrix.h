#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_EPS 1e-6
// #define SUCCESS 1
// #define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK = 0, INCOR_MATRIX = 1, CALC_ERROR = 2 } matrix_oper;

typedef enum { SUCCESS = 1, FAILURE = 0 } matrix_eq;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// ---------------helpers----------------
void matrix_minor(matrix_t *A, matrix_t *minor, int row, int column);
int negative_sign(matrix_t *A, matrix_t *B);
int incor_matrix(matrix_t *A);
int not_eq (matrix_t * A, matrix_t *B);
int not_eq_col_row(matrix_t *A);

#endif // SRC_S21_MATRIX_H_