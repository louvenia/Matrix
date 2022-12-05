/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "tests.check" instead.
 */

#include <check.h>

#include "../s21_matrix.h"

START_TEST(create_matrix_1) {
  matrix_t a;
  int rows_a = 2, columns_a = 2;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 0;
  ck_assert_int_eq(res, res_num);

  if (res_num == 0) {
    s21_remove_matrix(&a);
  }
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t a;
  int rows_a = 0, columns_a = 0;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 1;
  ck_assert_int_eq(res, res_num);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t a;
  int rows_a = 2, columns_a = -4;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 1;
  ck_assert_int_eq(res, res_num);
}
END_TEST

START_TEST(create_matrix_4) {
  matrix_t a;
  int rows_a = -3, columns_a = 5;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 1;
  ck_assert_int_eq(res, res_num);
}
END_TEST

START_TEST(create_matrix_5) {
  matrix_t a;
  int rows_a = 2, columns_a = 0;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 1;
  ck_assert_int_eq(res, res_num);
}
END_TEST

START_TEST(create_matrix_6) {
  matrix_t a;
  int rows_a = 0, columns_a = 7;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 1;
  ck_assert_int_eq(res, res_num);
}
END_TEST

START_TEST(create_matrix_7) {
  matrix_t a;
  int rows_a = 40, columns_a = 54;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 0;
  ck_assert_int_eq(res, res_num);

  if (res_num == 0) {
    s21_remove_matrix(&a);
  }
}
END_TEST

START_TEST(create_matrix_8) {
  matrix_t a;
  int rows_a = 0, columns_a = 4;
  int res = s21_create_matrix(rows_a, columns_a, &a);
  int res_num = 1;
  ck_assert_int_eq(res, res_num);
}
END_TEST

START_TEST(sum_matrix_1) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  int rows_a = 2, columns_a = 1;
  int rows_b = 2, columns_b = 1;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);
  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);
  a.matrix[0][0] = 10;
  a.matrix[1][0] = 11;
  b.matrix[0][0] = 5;
  b.matrix[1][0] = 7;
  int error = s21_sum_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq_tol(result.matrix[0][0], 15.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[1][0], 18.0, S21_EPS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  int rows_a = 2, columns_a = 2;
  int rows_b = 2, columns_b = 1;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);
  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);
  s21_create_matrix(rows_a, columns_a, &result);
  int error = s21_sum_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  int rows_a = 2, columns_a = 1;
  int rows_b = 3, columns_b = 1;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);
  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);
  s21_create_matrix(rows_a, columns_a, &result);
  int error = s21_sum_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  a.rows = -2;
  a.columns = 3;
  b.rows = 2;
  b.columns = 3;

  int error = s21_sum_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  int rows_a = 3, columns_a = 3;
  int rows_b = 3, columns_b = 2;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);
  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);
  s21_create_matrix(rows_a, columns_a, &result);
  int error = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  int rows_a = 2, columns_a = 2;
  int rows_b = 2, columns_b = 2;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);
  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);
  a.matrix[0][0] = 10;
  a.matrix[0][1] = 29;
  a.matrix[1][0] = -32;
  a.matrix[1][1] = 1;
  b.matrix[0][0] = -13;
  b.matrix[0][1] = 43;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 5;
  int error = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq_tol(result.matrix[0][0], 23.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[1][0], -34.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[0][1], -14.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[1][1], -4.0, S21_EPS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  int rows_a = 3, columns_a = 3;
  int rows_b = 3, columns_b = 3;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);
  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);
  a.matrix[0][0] = 10;
  a.matrix[0][1] = 19;
  a.matrix[0][2] = 25;
  a.matrix[1][0] = 23;
  a.matrix[1][1] = -1;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 4;
  a.matrix[2][1] = 85;
  a.matrix[2][2] = 12;

  b.matrix[0][0] = -10;
  b.matrix[0][1] = 9;
  b.matrix[0][2] = 45;
  b.matrix[1][0] = 6;
  b.matrix[1][1] = -2;
  b.matrix[1][2] = 10;
  b.matrix[2][0] = 100;
  b.matrix[2][1] = -29;
  b.matrix[2][2] = 6;

  int error = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq_tol(result.matrix[0][0], 20.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[0][1], 10.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[0][2], -20.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[1][0], 17.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[1][1], 1.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[1][2], -7.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[2][0], -96.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[2][1], 114.0, S21_EPS);
  ck_assert_double_eq_tol(result.matrix[2][2], 6.0, S21_EPS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  int rows_a = 2, columns_a = 3;
  int rows_b = 3, columns_b = 1;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);
  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);
  s21_create_matrix(rows_a, columns_a, &result);
  int error = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  a.rows = -2;
  a.columns = 2;
  b.columns = 2;
  b.rows = 2;
  int error = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(determinant_matrix_1) {
  matrix_t a;
  double result = 0.0;

  int rows_a = 3, columns_a = 3;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  ck_assert_int_eq(res_a_cr, 0);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;

  int error = s21_determinant(&a, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 0, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_matrix_2) {
  matrix_t a;
  double result = 0.0;

  int rows_a = 2, columns_a = 2;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  ck_assert_int_eq(res_a_cr, 0);

  a.matrix[0][0] = 198;
  a.matrix[0][1] = 68;
  a.matrix[1][0] = -45;
  a.matrix[1][1] = 3;

  int error = s21_determinant(&a, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 3654, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_matrix_3) {
  matrix_t a;
  double result = 0.0;
  int rows_a = 1, columns_a = 1;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  ck_assert_int_eq(res_a_cr, 0);

  a.matrix[0][0] = 19823;

  int error = s21_determinant(&a, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 19823, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_matrix_4_err) {
  matrix_t a;
  double result = 0.0;
  a.columns = -2;
  a.rows = 1;

  int res_a_cr = s21_determinant(&a, &result);
  ck_assert_int_eq(res_a_cr, 1);
}
END_TEST

START_TEST(determinant_matrix_5_err) {
  matrix_t a;
  int rows_a = 2, columns_a = 3;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  ck_assert_int_eq(res_a_cr, 0);
  double result = 0.0;

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;

  int error = s21_determinant(&a, &result);
  ck_assert_int_eq(error, 2);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_matrix_6) {
  matrix_t A;
  double result = 0.0;

  int rows_a = 4, columns_a = 4;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &A);
  ck_assert_int_eq(res_a_cr, 0);
  A.matrix[0][0] = -4;
  A.matrix[0][1] = -2;
  A.matrix[0][2] = -7;
  A.matrix[0][3] = 8;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 9;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  A.matrix[2][3] = -3;
  A.matrix[3][0] = 6;
  A.matrix[3][1] = 4;
  A.matrix[3][2] = -10;
  A.matrix[3][3] = -4;

  int error = s21_determinant(&A, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, -1926.0, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_7) {
  matrix_t A;
  double result = 0.0;

  int rows_a = 5, columns_a = 5;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &A);
  ck_assert_int_eq(res_a_cr, 0);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = -2;
  A.matrix[0][2] = -7;
  A.matrix[0][3] = 8;
  A.matrix[0][4] = 124;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 111;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 12;
  A.matrix[1][4] = 0;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  A.matrix[2][3] = -3;
  A.matrix[2][4] = 23;

  A.matrix[3][0] = 6;
  A.matrix[3][1] = 4;
  A.matrix[3][2] = -10;
  A.matrix[3][3] = -4;
  A.matrix[3][4] = 176;

  A.matrix[4][0] = 1;
  A.matrix[4][1] = -44;
  A.matrix[4][2] = -13;
  A.matrix[4][3] = 0;
  A.matrix[4][4] = 90;

  int error = s21_determinant(&A, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, -195808.0, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_1) {
  matrix_t a;
  matrix_t b;

  int rows_a = 3, columns_a = 3;
  int rows_b = 3, columns_b = 3;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);

  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 3;
  b.matrix[1][0] = 4;
  b.matrix[1][1] = 5;
  b.matrix[1][2] = 6;
  b.matrix[2][0] = 7;
  b.matrix[2][1] = 8;
  b.matrix[2][2] = 9;

  int error = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(error, 1);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t a;
  matrix_t b;

  int rows_a = 3, columns_a = 3;
  int rows_b = 3, columns_b = 3;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);

  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 3;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 3;
  b.matrix[1][0] = 4;
  b.matrix[1][1] = 5;
  b.matrix[1][2] = 6;
  b.matrix[2][0] = 7;
  b.matrix[2][1] = 8;
  b.matrix[2][2] = 9;

  int error = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(error, 0);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t a;
  matrix_t b;

  int rows_a = 3, columns_a = 2;
  int rows_b = 3, columns_b = 3;
  int res_a_cr = s21_create_matrix(rows_a, columns_a, &a);
  int res_b_cr = s21_create_matrix(rows_b, columns_b, &b);

  ck_assert_int_eq(res_a_cr, 0);
  ck_assert_int_eq(res_b_cr, 0);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[1][0] = 3;
  a.matrix[1][1] = 5;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 3;
  b.matrix[1][0] = 4;
  b.matrix[1][1] = 5;
  b.matrix[1][2] = 6;
  b.matrix[2][0] = 7;
  b.matrix[2][1] = 8;
  b.matrix[2][2] = 9;

  int error = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(error, 0);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(mul_matrix_1) {
  int row1 = 2;
  int col1 = 3;
  int row2 = 3;
  int col2 = 5;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  int s21_error_code_b = s21_create_matrix(row2, col2, &B);
  ck_assert_int_eq(s21_error_code_a, 0);
  ck_assert_int_eq(s21_error_code_b, 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 3;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 7.567;
    }
  }
  int s21_error_code_res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 68.103000, 1e-06);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_matrix_2) {
  int row1 = 2;
  int col1 = 1;
  int row2 = 1;
  int col2 = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  int s21_error_code_b = s21_create_matrix(row2, col2, &B);
  ck_assert_int_eq(s21_error_code_a, 0);
  ck_assert_int_eq(s21_error_code_b, 0);
  A.matrix[0][0] = 3;
  A.matrix[1][0] = 10;
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[0][2] = -6.8;
  int s21_error_code_res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 15.0, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], 18.0, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][2], -20.4, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], 50.0, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], 60.0, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][2], -68.0, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_matrix_3) {
  int row1 = 2;
  int col1 = 3;
  int row2 = 3;
  int col2 = 5;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  int s21_error_code_b = s21_create_matrix(row2, col2, &B);
  ck_assert_int_eq(s21_error_code_a, 0);
  ck_assert_int_eq(s21_error_code_b, 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 3;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = -7.567;
    }
  }
  int s21_error_code_res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], -68.103000, 1e-06);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_matrix_4) {
  int row1 = 0;
  int col1 = 3;
  int row2 = 3;
  int col2 = 5;
  matrix_t A;
  matrix_t B;

  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  int s21_error_code_b = s21_create_matrix(row2, col2, &B);
  s21_remove_matrix(&B);

  ck_assert_int_eq(s21_error_code_a, 1);
  ck_assert_int_eq(s21_error_code_b, 0);
}
END_TEST

START_TEST(mul_matrix_5) {
  int row1 = 2;
  int col1 = 1;
  int row2 = 2;
  int col2 = 2;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  int s21_error_code_b = s21_create_matrix(row2, col2, &B);
  ck_assert_int_eq(s21_error_code_a, 0);
  ck_assert_int_eq(s21_error_code_b, 0);
  A.matrix[0][0] = 3;
  A.matrix[1][0] = 10;
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -5;
  int s21_error_code_res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(s21_error_code_res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mul_matrix_6) {
  matrix_t a;
  matrix_t b;
  matrix_t result;
  b.rows = 3;
  b.columns = -2;
  a.rows = 2;
  a.columns = 3;
  int s21_error_code_res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_error_code_res, 1);
}
END_TEST

START_TEST(mul_num_1) {
  int row1 = 10;
  int col1 = 11;
  double number = 6;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 3;
    }
  }
  A.matrix[9][10] = 4;
  int s21_error_code_res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  for (int i = 0; i < result.rows - 1; i++) {
    for (int j = 0; j < result.columns - 1; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 18, 1e-06);
    }
  }
  ck_assert_double_eq_tol(result.matrix[9][10], 24, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_2) {
  int row1 = 10;
  int col1 = 11;
  double number = 6;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 0;
    }
  }
  A.matrix[9][10] = 4;
  int s21_error_code_res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  for (int i = 0; i < result.rows - 1; i++) {
    for (int j = 0; j < result.columns - 1; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 0, 1e-06);
    }
  }
  ck_assert_double_eq_tol(result.matrix[9][10], 24, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_3) {
  int row1 = 10;
  int col1 = 11;
  double number = 0.0;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 6.84656;
    }
  }
  int s21_error_code_res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 0, 1e-06);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_4) {
  int row1 = 10;
  int col1 = -11;
  double number = 6;
  matrix_t A;
  A.rows = row1;
  A.columns = col1;
  matrix_t result;
  int s21_error_code_res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(s21_error_code_res, 1);
}
END_TEST

START_TEST(transpose_1) {
  int row1 = 2;
  int col1 = 2;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 10;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  int s21_error_code_res = s21_transpose(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 5, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], 2, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], 10, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], 3, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  int row1 = 2;
  int col1 = 3;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 10;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 9;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 21;
  int s21_error_code_res = s21_transpose(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 5, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], 9, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], 10, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], 3, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][0], 2, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][1], 21, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  int row1 = 1;
  int col1 = 3;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 10;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 3;
  int s21_error_code_res = s21_transpose(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 10, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], 4, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][0], 3, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_4) {
  int row1 = 2;
  int col1 = -3;
  matrix_t A;
  A.rows = row1;
  A.columns = col1;
  matrix_t result;
  int s21_error_code_res = s21_transpose(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 1);
}
END_TEST

START_TEST(inverse_1) {
  int row1 = 3;
  int col1 = 3;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  int s21_error_code_res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], -1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][2], 1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], -38, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], 41, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][2], -34, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][0], 27, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][1], -29, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][2], 24, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_2) {
  int row1 = 3;
  int col1 = 2;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;

  int s21_error_code_res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t A;
  A.rows = 10;
  A.columns = -11;
  matrix_t result;
  int s21_error_code_res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 1);
}
END_TEST

START_TEST(inverse_4) {
  int row1 = 3;
  int col1 = 3;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int s21_error_code_res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_5) {
  int row1 = 5;
  int col1 = 5;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 5;
  A.matrix[0][3] = 6;
  A.matrix[0][4] = 6;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 8;
  A.matrix[1][4] = 6;
  A.matrix[2][0] = -8;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 12;
  A.matrix[2][3] = 9;
  A.matrix[2][4] = 6;
  A.matrix[3][0] = 5;
  A.matrix[3][1] = 6;
  A.matrix[3][2] = 4;
  A.matrix[3][3] = 9;
  A.matrix[3][4] = 6;
  A.matrix[4][0] = 5;
  A.matrix[4][1] = 3;
  A.matrix[4][2] = 0;
  A.matrix[4][3] = -5;
  A.matrix[4][4] = 6;
  int s21_error_code_res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], -0.105727, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], 0.399413, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][2], -0.089574, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][3], -0.198238, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][4], -0.005874, 1e-06);

  ck_assert_double_eq_tol(result.matrix[1][0], -0.281938, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], -0.490455, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][2], 0.205580, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][3], 0.471366, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][4], 0.095448, 1e-06);

  ck_assert_double_eq_tol(result.matrix[2][0], -0.312775, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][1], 0.403818, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][2], 0.082232, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][3], -0.211454, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][4], 0.038179, 1e-06);

  ck_assert_double_eq_tol(result.matrix[3][0], 0.149780, 1e-06);
  ck_assert_double_eq_tol(result.matrix[3][1], -0.010279, 1e-06);
  ck_assert_double_eq_tol(result.matrix[3][2], -0.067548, 1e-06);
  ck_assert_double_eq_tol(result.matrix[3][3], 0.030837, 1e-06);
  ck_assert_double_eq_tol(result.matrix[3][4], -0.102790, 1e-06);

  ck_assert_double_eq_tol(result.matrix[4][0], 0.353891, 1e-06);
  ck_assert_double_eq_tol(result.matrix[4][1], -0.096182, 1e-06);
  ck_assert_double_eq_tol(result.matrix[4][2], -0.084435, 1e-06);
  ck_assert_double_eq_tol(result.matrix[4][3], -0.044787, 1e-06);
  ck_assert_double_eq_tol(result.matrix[4][4], 0.038179, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_6) {
  matrix_t A;
  A.columns = -2;
  A.rows = -2;
  matrix_t result;

  int s21_error_code_res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 1);
}
END_TEST

START_TEST(inverse_7) {
  int row1 = 2;
  int col1 = 3;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 0;
    }
  }
  int s21_error_code_res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_1) {
  matrix_t A;
  A.rows = -4;
  A.columns = 3;
  matrix_t result;
  int s21_error_code_res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 2);
}
END_TEST

START_TEST(calc_2) {
  matrix_t A;
  A.rows = 2;
  A.columns = 3;
  matrix_t result;
  int s21_error_code_res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 2);
}
END_TEST

START_TEST(calc_3) {
  int row1 = 3;
  int col1 = 3;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int s21_error_code_res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_4) {
  matrix_t A;
  int row1 = 1;
  int col1 = 1;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);

  A.matrix[0][0] = 1;
  ck_assert_int_eq(s21_error_code_a, 0);
  matrix_t result;
  int s21_error_code_res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_5) {
  int row1 = 3;
  int col1 = 3;
  matrix_t A;
  matrix_t result;
  int s21_error_code_a = s21_create_matrix(row1, col1, &A);
  ck_assert_int_eq(s21_error_code_a, 0);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  int s21_error_code_res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_6) {
  matrix_t A;
  A.rows = -2;
  A.columns = -2;
  matrix_t result;
  int s21_error_code_res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_error_code_res, 1);
}

END_TEST
int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_matrix_1);
  tcase_add_test(tc1_1, create_matrix_2);
  tcase_add_test(tc1_1, create_matrix_3);
  tcase_add_test(tc1_1, create_matrix_4);
  tcase_add_test(tc1_1, create_matrix_5);
  tcase_add_test(tc1_1, create_matrix_6);
  tcase_add_test(tc1_1, create_matrix_7);
  tcase_add_test(tc1_1, create_matrix_8);
  tcase_add_test(tc1_1, sum_matrix_1);
  tcase_add_test(tc1_1, sum_matrix_2);
  tcase_add_test(tc1_1, sum_matrix_3);
  tcase_add_test(tc1_1, sum_matrix_4);
  tcase_add_test(tc1_1, sub_matrix_1);
  tcase_add_test(tc1_1, sub_matrix_2);
  tcase_add_test(tc1_1, sub_matrix_3);
  tcase_add_test(tc1_1, sub_matrix_4);
  tcase_add_test(tc1_1, sub_matrix_5);
  tcase_add_test(tc1_1, determinant_matrix_1);
  tcase_add_test(tc1_1, determinant_matrix_2);
  tcase_add_test(tc1_1, determinant_matrix_3);
  tcase_add_test(tc1_1, determinant_matrix_4_err);
  tcase_add_test(tc1_1, determinant_matrix_5_err);
  tcase_add_test(tc1_1, determinant_matrix_6);
  tcase_add_test(tc1_1, determinant_matrix_7);
  tcase_add_test(tc1_1, eq_matrix_1);
  tcase_add_test(tc1_1, eq_matrix_2);
  tcase_add_test(tc1_1, eq_matrix_3);
  tcase_add_test(tc1_1, mul_matrix_1);
  tcase_add_test(tc1_1, mul_matrix_2);
  tcase_add_test(tc1_1, mul_matrix_3);
  tcase_add_test(tc1_1, mul_matrix_4);
  tcase_add_test(tc1_1, mul_matrix_5);
  tcase_add_test(tc1_1, mul_matrix_6);
  tcase_add_test(tc1_1, mul_num_1);
  tcase_add_test(tc1_1, mul_num_2);
  tcase_add_test(tc1_1, mul_num_3);
  tcase_add_test(tc1_1, mul_num_4);
  tcase_add_test(tc1_1, transpose_1);
  tcase_add_test(tc1_1, transpose_2);
  tcase_add_test(tc1_1, transpose_3);
  tcase_add_test(tc1_1, transpose_4);
  tcase_add_test(tc1_1, inverse_1);
  tcase_add_test(tc1_1, inverse_2);
  tcase_add_test(tc1_1, inverse_3);
  tcase_add_test(tc1_1, inverse_4);
  tcase_add_test(tc1_1, inverse_5);
  tcase_add_test(tc1_1, inverse_6);
  tcase_add_test(tc1_1, inverse_7);
  tcase_add_test(tc1_1, calc_1);
  tcase_add_test(tc1_1, calc_2);
  tcase_add_test(tc1_1, calc_3);
  tcase_add_test(tc1_1, calc_4);
  tcase_add_test(tc1_1, calc_5);
  tcase_add_test(tc1_1, calc_6);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}