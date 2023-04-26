// #include <cstdio>

// int main() {
//   printf("Hello World");
//   return 0;
// }

#include "s21_matrix_oop.h"

int S21Matrix::getRows() { return rows_; }
int S21Matrix::getCols() { return cols_; }
void S21Matrix::setRows(int rows) { rows_ = rows; }
void S21Matrix::setCols(int cols) { cols_ = cols; }

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows > 0 && cols > 0) {
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double *[rows_] {};
    if (matrix_ != nullptr) {
      for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]{};
      }
    }
  }
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete matrix_;
  }
  cols_ = 0;
  rows_ = 0;
}
