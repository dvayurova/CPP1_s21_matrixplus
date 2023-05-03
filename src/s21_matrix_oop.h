#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <algorithm>
#include <utility>

class S21Matrix {
private:
  // Attributes
  int rows_, cols_; // Rows and columns
  double **matrix_; // Pointer to the memory where the matrix is allocated

public:
  S21Matrix();
  explicit S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;

  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other) noexcept;

  ~S21Matrix();

  void SumMatrix(const S21Matrix &other);
  // Other methods..
  int getRows();
  int getCols();
  void setRows(int rows);
  void setCols(int cols);

  // sub funcs
  void NewMatrix(int rows, int cols);
  void CopyMatrix(double **matrix);
  void DeleteMatrix();
  int EqualSize(const S21Matrix &other);

  double getElem(int i, int j); //  временная функция
  void setElem(int i, int j, double value); // временная функция
  void printMatrix();
};

#endif // SRC_S21_MATRIX_OOP_H_