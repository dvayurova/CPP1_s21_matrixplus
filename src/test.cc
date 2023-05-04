#include "s21_matrix_oop.h"
#include <cstdio>

S21Matrix createMatrix(int rows, int cols, double elem) {
  S21Matrix tmp(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      tmp.setElem(i, j, elem);
    }
  }
  return tmp;
}

S21Matrix createMatrix2(int rows, int cols, double elem) {
  S21Matrix tmp(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      tmp.setElem(i, j, elem);
      elem++;
    }
  }
  return tmp;
}

int main() {
  S21Matrix orig_matrix(5, 6);
  printf("\n orig_matrix cols = %d", orig_matrix.getCols());
  orig_matrix.setElem(1, 2, 5.75);
  printf("\n orig_matrix elem = %f\n", orig_matrix.getElem(1, 2));

  S21Matrix copy_matrix(orig_matrix);
  printf("\n\n copy_matrix cols = %d", copy_matrix.getCols());
  printf("\n orig_matrix cols = %d", orig_matrix.getCols());
  printf("\n copy_matrix elem = %f", copy_matrix.getElem(1, 2));
  printf("\n orig_matrix elem = %f\n", orig_matrix.getElem(1, 2));

  S21Matrix copy_matrix_operatr(5, 6);
  copy_matrix_operatr = orig_matrix;
  printf("\n\n copy_matrix_operatr cols = %d", copy_matrix_operatr.getCols());
  printf("\n orig_matrix cols = %d", orig_matrix.getCols());
  printf("\n copy_matrix_operatr elem = %f", copy_matrix_operatr.getElem(1, 2));
  printf("\n orig_matrix elem = %f\n", orig_matrix.getElem(1, 2));

  S21Matrix move_matrix = std::move(orig_matrix);
  printf("\n\n move_matrix cols = %d", move_matrix.getCols());
  printf("\n orig_matrix cols = %d", orig_matrix.getCols());
  printf("\n move_matrix elem = %f", move_matrix.getElem(1, 2));
  printf("\n orig_matrix elem = %f\n", orig_matrix.getElem(1, 2));

  S21Matrix move_matrix_operatr(2, 3);
  move_matrix_operatr = createMatrix(2, 3, 9.577);
  printf("\n\n move_matrix_operatr cols = %d", move_matrix_operatr.getCols());
  printf("\n move_matrix_operatr elem = %f", move_matrix_operatr.getElem(1, 2));

  move_matrix_operatr.printMatrix();
  printf("\n\n\n move_matrix_operatr rows = %d", move_matrix_operatr.getRows());
  move_matrix_operatr.setRows(4);
  printf("\nSET ROWS\n move_matrix_operatr rows = %d",
         move_matrix_operatr.getRows());
  move_matrix_operatr.printMatrix();

  printf("\n\n\n move_matrix_operatr cols = %d", move_matrix_operatr.getCols());
  move_matrix_operatr.setCols(8);
  printf("\nSET COLS\n move_matrix_operatr cols = %d",
         move_matrix_operatr.getCols());
  move_matrix_operatr.printMatrix();

  printf("\n SUM \n");
  try {
    move_matrix_operatr.SumMatrix(move_matrix);
    move_matrix_operatr.printMatrix();
  } catch (const char *exception) {
    printf("\n error: %s\n", exception);
  }

  copy_matrix.SumMatrix(move_matrix);
  copy_matrix.printMatrix();

  printf("\n SUB \n");
  copy_matrix.SubMatrix(move_matrix);
  copy_matrix.printMatrix();

  printf("\n MULT matrix\n");
  S21Matrix matrix_a = createMatrix2(2, 3, 1.1234567);
  S21Matrix matrix_b = createMatrix2(3, 2, 56.987654321);
  matrix_a.MulMatrix(matrix_b);
  matrix_a.printMatrix();

  printf("\n MULT num\n");
  S21Matrix matrix_c = createMatrix2(4, 4, 1.1234567);
  matrix_c.MulNumber(1.12345670);
  matrix_c.printMatrix();

  printf("\n Equal matrix \n");
  S21Matrix matrix_d = createMatrix2(2, 3, 1.1234567);
  S21Matrix matrix_e = createMatrix2(2, 3, 1.1234567);
  if (matrix_d.EqMatrix(matrix_e) == true) {
    printf("\n matrices are equal \n");
  } else {
    printf("\n matrices are not equal \n");
  }

  printf("\n Transpose matrix \n");
  printf("\n matrix e:\n");
  matrix_e.printMatrix();
  S21Matrix matrix_f = matrix_e.Transpose();
  printf("\n matrix f (transpose):\n");
  matrix_f.printMatrix();

  try {
    printf("\n Transpose matrix \n");
    S21Matrix matrix_g;
    matrix_g.setCols(2);
    matrix_g.setRows(3);
    S21Matrix matrix_h = matrix_g.Transpose();
    printf("\n matrix f (transpose):\n");
    matrix_h.printMatrix();
  } catch (const char *exception) {
    printf("\n error: %s\n", exception);
  }

  matrix_f.setCols(3);
  matrix_f.printMatrix();
  double det = matrix_f.Determinant();
  printf("\n determinant = %f", det);

  printf("\n matrix c:\n");
  matrix_c.printMatrix();
  double det_c = matrix_c.Determinant();
  printf("\n determinant = %f", det_c);

  S21Matrix matrix_i(3, 3);
  matrix_i.setElem(0, 0, 1);
  matrix_i.setElem(0, 1, 2);
  matrix_i.setElem(0, 2, -4);
  matrix_i.setElem(1, 0, 2);
  matrix_i.setElem(1, 1, 3);
  matrix_i.setElem(1, 2, 1);
  matrix_i.setElem(2, 0, 3);
  matrix_i.setElem(2, 1, -1);
  matrix_i.setElem(2, 2, 2);
  matrix_i.printMatrix();
  double det_i = matrix_i.Determinant();
  printf("\n determinant = %f", det_i);

  printf("\n cal complements\n");
  S21Matrix matrix_k(3, 3);
  matrix_k.setElem(0, 0, 1);
  matrix_k.setElem(0, 1, 2);
  matrix_k.setElem(0, 2, 3);
  matrix_k.setElem(1, 0, 0);
  matrix_k.setElem(1, 1, 4);
  matrix_k.setElem(1, 2, 2);
  matrix_k.setElem(2, 0, 5);
  matrix_k.setElem(2, 1, 2);
  matrix_k.setElem(2, 2, 1);
  matrix_k.printMatrix();
  S21Matrix matrix_compl = matrix_k.CalcComplements();
  matrix_compl.printMatrix();

  printf("\n inverse matrix \n");
  S21Matrix matrix_l(3, 3);
  matrix_l.setElem(0, 0, 2);
  matrix_l.setElem(0, 1, 5);
  matrix_l.setElem(0, 2, 7);
  matrix_l.setElem(1, 0, 6);
  matrix_l.setElem(1, 1, 3);
  matrix_l.setElem(1, 2, 4);
  matrix_l.setElem(2, 0, 5);
  matrix_l.setElem(2, 1, -2);
  matrix_l.setElem(2, 2, -3);
  matrix_l.printMatrix();
  S21Matrix matrix_inverse = matrix_l.InverseMatrix();
  matrix_inverse.printMatrix();

  printf("\n + operator \n");
  matrix_k.printMatrix();
  matrix_l.printMatrix();
  S21Matrix sum_oper_matrix = matrix_k + matrix_l;
  printf("\n sum_oper_matrix: \n");
  sum_oper_matrix.printMatrix();
  printf("\n matrix k \n");
  matrix_k.printMatrix();
  printf("\n matrix l \n");
  matrix_l.printMatrix();

  printf("\n - operator \n");
  matrix_k.printMatrix();
  matrix_l.printMatrix();
  S21Matrix sub_oper_matrix = matrix_k - matrix_l;
  printf("\n sub_oper_matrix: \n");
  sub_oper_matrix.printMatrix();
  printf("\n matrix k \n");
  matrix_k.printMatrix();
  printf("\n matrix l \n");
  matrix_l.printMatrix();

  printf("\n * matrices operator \n");
  matrix_k.printMatrix();
  matrix_l.printMatrix();
  S21Matrix mult_oper_matrix = matrix_k * matrix_l;
  printf("\n mult_oper_matrix: \n");
  mult_oper_matrix.printMatrix();
  printf("\n matrix k \n");
  matrix_k.printMatrix();
  printf("\n matrix l \n");
  matrix_l.printMatrix();

  printf("\n * num operator \n");
  matrix_l.printMatrix();
  S21Matrix mult_num_oper_matrix = matrix_l * 1.5;
  printf("\n mult_num_oper_matrix: \n");
  mult_num_oper_matrix.printMatrix();
  printf("\n matrix l \n");
  matrix_l.printMatrix();

  printf("\n Equal matrix operator \n");
  S21Matrix matrix_m = createMatrix2(2, 3, 1.1234567);
  S21Matrix matrix_n = createMatrix2(2, 3, 1.1234567);
  if (matrix_m == matrix_n) {
    printf("\n matrices are equal \n");
  } else {
    printf("\n matrices are not equal \n");
  }

  printf("\n +=  operator \n");
  matrix_k.printMatrix();
  matrix_l.printMatrix();
  matrix_k += matrix_l;
  printf("\n += operator: \n");
  printf("\n matrix k (res) \n");
  matrix_k.printMatrix();

  printf("\n -=  operator \n");
  matrix_k.printMatrix();
  matrix_l.printMatrix();
  matrix_k -= matrix_l;
  printf("\n matrix k (res): ");
  matrix_k.printMatrix();

  printf("\n *= matrices operator \n");
  matrix_k.printMatrix();
  matrix_l.printMatrix();
  matrix_k *= matrix_l;
  printf("\n matrix k (res): ");
  matrix_k.printMatrix();

  printf("\n *= num operator \n");
  matrix_k.printMatrix();
  matrix_k *= 1.5;
  printf("\n matrix k (res): ");
  matrix_k.printMatrix();

  printf("\n () index \n");
  matrix_k.printMatrix();
  printf("\n matrix k[0][0]: %f", matrix_k(0, 0));
  printf("\n matrix k[1][1]: %f", matrix_k(1, 1));
  printf("\n matrix k[2][2]: %f", matrix_k(2, 2));

  return 0;
}
