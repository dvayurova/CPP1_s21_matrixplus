#include "s21_matrix_oop.h"
#include <cstdio>

int S21Matrix::getRows() { return this->rows_; }
int S21Matrix::getCols() { return this->cols_; }
// void S21Matrix::setRows(int rows) { rows_ = rows; }
// void S21Matrix::setCols(int cols) { cols_ = cols; }

//    ВРЕМЕННЫЕ функции
double S21Matrix::getElem(int i, int j) {
  if (this->matrix_ == nullptr)
    return 0;
  return this->matrix_[i][j];
}
void S21Matrix::setElem(int i, int j, double value) {
  if (i < this->rows_ && j < this->cols_ && this->matrix_ != nullptr) {
    this->matrix_[i][j] = value;
  }
}

void S21Matrix::newMatrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;
  this->matrix_ = new double *[rows_] {};
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[this->cols_]{};
  }
}

S21Matrix::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 && cols <= 0) {
    throw "rows/columns should be more than zero";
  }
  newMatrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  newMatrix(other.rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
  printf("\n it's copy constructor"); // УДАЛИИИИТЬ
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
  printf("\n it's move constructor"); // УДАЛИИИИТЬ
}

S21Matrix::~S21Matrix() {
  printf("\n it's destructor. cols = %d", cols_); // УДАЛИИИИТЬ
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
  }
  delete[] this->matrix_;
  this->matrix_ = nullptr;
  this->cols_ = 0;
  this->rows_ = 0;
}
