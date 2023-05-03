#include "s21_matrix_oop.h"
#include <cstdio>

int S21Matrix::getRows() { return this->rows_; }
int S21Matrix::getCols() { return this->cols_; }
void S21Matrix::setRows(int rows) {
  if (rows <= 0) {
    throw "rows should be more than zero";
  }
  S21Matrix tmp(rows, this->cols_);
  for (int i = 0; i < (rows <= this->rows_ ? rows : this->rows_); i++) {
    for (int j = 0; j < this->cols_; j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
}
void S21Matrix::setCols(int cols) {
  if (cols <= 0) {
    throw "rows should be more than zero";
  }
  S21Matrix tmp(this->rows_, cols);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < (cols <= this->cols_ ? cols : this->cols_); j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
}

//    ВРЕМЕННЫЕ функции: начало
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
void S21Matrix::printMatrix() {
  printf("\n matrix:\n");
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      printf("%f ", this->matrix_[i][j]);
    }
    printf("\n");
  }
}
// конец временных функций

void S21Matrix::NewMatrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;
  this->matrix_ = new double *[rows_] {};
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[this->cols_]{};
  }
}

void S21Matrix::CopyMatrix(double **matrix) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = matrix[i][j];
    }
  }
}

void S21Matrix::DeleteMatrix() {
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
  }
  delete[] this->matrix_;
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
  NewMatrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  NewMatrix(other.rows_, other.cols_);
  CopyMatrix(other.matrix_);
  printf("\n it's copy constructor"); // УДАЛИИИИТЬ
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    printf("\n it's copy operator"); // УДАЛИИИИТЬ
    DeleteMatrix();
    NewMatrix(other.rows_, other.cols_);
    CopyMatrix(other.matrix_);
  }
  return *this;
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
  printf("\n it's move constructor"); // УДАЛИИИИТЬ
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (this != &other) {
    printf("\n it's moved operator"); // УДАЛИИИИТЬ
    DeleteMatrix();
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix::~S21Matrix() {
  printf("\n it's destructor. cols = %d, rows = %d", cols_,
         rows_); // УДАЛИИИИТЬ
  DeleteMatrix();
  this->matrix_ = nullptr;
  this->cols_ = 0;
  this->rows_ = 0;
}
