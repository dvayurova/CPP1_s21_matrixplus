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
  S21Matrix();                            // Default constructor
  explicit S21Matrix(int rows, int cols); // Parameterized constructor
  S21Matrix(const S21Matrix &other);      // copy constructor
  S21Matrix(S21Matrix &&other) noexcept;  // Move constructor

  ~S21Matrix(); // Destructor

  // void SumMatrix(const S21Matrix &other);
  // Other methods..
  int getRows();
  int getCols();
  // void setRows(int rows);
  // void setCols(int cols);

  void newMatrix(int rows, int cols);
  double getElem(int i, int j); //  временная функция
  void setElem(int i, int j, double value); // временная функция
};

#endif // SRC_S21_MATRIX_OOP_H_