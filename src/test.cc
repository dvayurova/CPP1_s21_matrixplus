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

  return 0;
}
