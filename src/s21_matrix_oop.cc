#include "s21_matrix_oop.h"

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }
void S21Matrix::SetRows(int rows) {
  if (rows <= 0) {
    throw std::invalid_argument("rows should be more than zero");
  }
  S21Matrix tmp(rows, cols_);
  int min_rows = rows <= rows_ ? rows : rows_;
  for (int i = 0; i < min_rows; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = tmp;
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) {
    throw std::invalid_argument("columns should be more than zero");
  }
  S21Matrix tmp(rows_, cols);
  int min_cols = cols <= cols_ ? cols : cols_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < min_cols; j++) {
      tmp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = tmp;
}

void S21Matrix::NewMatrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_] {};
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

void S21Matrix::CopyMatrix(double **matrix) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix[i][j];
    }
  }
}

void S21Matrix::DeleteMatrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

void S21Matrix::ZeroMatrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix() { ZeroMatrix(); }

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("rows/columns should be more than zero");
  }
  NewMatrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  NewMatrix(other.rows_, other.cols_);
  CopyMatrix(other.matrix_);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    DeleteMatrix();
    NewMatrix(other.rows_, other.cols_);
    CopyMatrix(other.matrix_);
  }
  return *this;
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.ZeroMatrix();
  ;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.ZeroMatrix();
  }
  return *this;
}

S21Matrix::~S21Matrix() {
  DeleteMatrix();
  ZeroMatrix();
}
bool S21Matrix::EqualSize(const S21Matrix &other) {
  return rows_ == other.rows_ && cols_ == other.cols_;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;
  if (!EqualSize(other)) {
    result = false;
  }
  for (int i = 0; i < rows_ && result; i++) {
    for (int j = 0; (j < cols_) && result; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-6) {
        result = false;
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!EqualSize(other)) {
    throw std::length_error("different size of matrices");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (!EqualSize(other)) {
    throw std::length_error("different size of matrices");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::length_error(
        "the number of columns of the first matrix is not equal to the "
        "number of rows of the second matrix");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_ || cols_ <= 1) {
    throw std::length_error("matrix is not square");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = MinorMatrix(i, j).Determinant() * pow(-1, i + j);
    }
  }
  return result;
}

double S21Matrix::DeterminantOfTwoByTwoMatrix() {
  return matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
}

S21Matrix S21Matrix::MinorMatrix(int x, int y) {
  S21Matrix minor_matrix(rows_ - 1, cols_ - 1);
  for (int i = 0, m = 0; i < rows_; i++, m++) {
    for (int j = 0, n = 0; j < cols_; j++, n++) {
      if (i != x && j != y)
        minor_matrix.matrix_[m][n] = matrix_[i][j];
      if (j == y)
        n--;
    }
    if (i == x)
      m--;
  }
  return minor_matrix;
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw std::logic_error("matrix is not square");
  }
  double result = 0, temp_det = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = DeterminantOfTwoByTwoMatrix();
  } else {
    for (int i = 0; i < rows_; i++) {
      temp_det = MinorMatrix(i, 0).Determinant();
      result = result + matrix_[i][0] * temp_det * (i % 2 == 0 ? 1 : -1);
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (fabs(det) < 1e-7) {
    throw std::logic_error("determinant is zero");
  }
  S21Matrix result(1, 1);
  if (cols_ == 1) {
    result.matrix_[0][0] = 1.0 / det;

  } else {
    result = CalcComplements().Transpose();
    result.MulNumber(1.0 / det);
  }
  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

void S21Matrix::operator+=(const S21Matrix &other) { return SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix &other) { return SubMatrix(other); }

void S21Matrix::operator*=(const S21Matrix &other) { return MulMatrix(other); }

void S21Matrix::operator*=(const double num) { return MulNumber(num); }

double &S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[i][j];
}

const double &S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[i][j];
}