#include "s21_matrix_oop.h"

int S21Matrix::getRows() { return rows_; }
int S21Matrix::getCols() { return cols_; }
// void S21Matrix::setRows(int rows) { rows_ = rows; }  
// void S21Matrix::setCols(int cols) { cols_ = cols; }

// возможно временная функция
double S21Matrix::getElem(int i, int j) {return matrix_[i][j];}

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double* [rows_]{};
  for(int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
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
  } else {
    throw "rows/columns should be more than zero";
  }
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  matrix_ = nullptr;
  cols_ = 0;
  rows_ = 0;
}
