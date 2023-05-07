#include <gtest/gtest.h>

#include <cstdio>

#include "s21_matrix_oop.h"

S21Matrix FillWithStep(int rows, int cols, double elem) {
  S21Matrix tmp(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      tmp(i, j) = elem;
      elem++;
    }
  }
  return tmp;
}

S21Matrix FillMatrix(int rows, int cols, double elem) {
  S21Matrix tmp(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      tmp(i, j) = elem;
    }
  }
  return tmp;
}

TEST(TestGetRows, Test_1) {
  S21Matrix matrix_a(3, 2);
  ASSERT_EQ(3, matrix_a.GetRows());
}

TEST(TestGetCols, Test_1) {
  S21Matrix matrix_a(3, 2);
  ASSERT_EQ(2, matrix_a.GetCols());
}

TEST(TestSetRows, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  matrix_a.SetRows(4);
  ASSERT_EQ(4, matrix_a.GetRows());
}

TEST(TestSetCols, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  matrix_a.SetCols(5);
  ASSERT_EQ(5, matrix_a.GetCols());
}

TEST(TestEqual, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillWithStep(2, 3, 1.1234567);
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_b));
}

TEST(TestEqual, Test_2) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillWithStep(2, 3, 56.987654321);
  ASSERT_FALSE(matrix_a.EqMatrix(matrix_b));
}

TEST(TestEqual, Test_3) {
  S21Matrix matrix_a(3, 2);
  S21Matrix matrix_b(4, 2);
  ASSERT_FALSE(matrix_a.EqMatrix(matrix_b));
}

TEST(TestSum, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillMatrix(2, 3, 1);
  matrix_a.SumMatrix(matrix_b);
  S21Matrix matrix_correct = FillWithStep(2, 3, 2.1234567);
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestSub, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 2.1234567);
  S21Matrix matrix_b = FillMatrix(2, 3, 1);
  matrix_a.SubMatrix(matrix_b);
  S21Matrix matrix_correct = FillWithStep(2, 3, 1.1234567);
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestMultMatrix, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillWithStep(3, 2, 56.987654321);
  matrix_a.MulMatrix(matrix_b);
  S21Matrix matrix_correct(2, 2);
  matrix_correct(0, 0) = 379.773189;
  matrix_correct(0, 1) = 386.143559;
  matrix_correct(1, 0) = 910.662078;
  matrix_correct(1, 1) = 926.032448;
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestMultNum, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  matrix_a.MulNumber(1.12345670);
  S21Matrix matrix_correct(2, 3);
  matrix_correct(0, 0) = 1.262155;
  matrix_correct(0, 1) = 2.385612;
  matrix_correct(0, 2) = 3.509068;
  matrix_correct(1, 0) = 4.632525;
  matrix_correct(1, 1) = 5.755982;
  matrix_correct(1, 2) = 6.879438;
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestTranspose, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = matrix_a.Transpose();
  S21Matrix matrix_correct(3, 2);
  matrix_correct(0, 0) = 1.123457;
  matrix_correct(1, 0) = 2.123457;
  matrix_correct(2, 0) = 3.123457;
  matrix_correct(0, 1) = 4.123457;
  matrix_correct(1, 1) = 5.123457;
  matrix_correct(2, 1) = 6.123457;
  ASSERT_TRUE(matrix_b.EqMatrix(matrix_correct));
}

TEST(TestCalcComp, Test_1) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 4;
  matrix_a(1, 2) = 2;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = 2;
  matrix_a(2, 2) = 1;
  S21Matrix matrix_correct(3, 3);
  matrix_correct(0, 0) = 0;
  matrix_correct(0, 1) = 10;
  matrix_correct(0, 2) = -20;
  matrix_correct(1, 0) = 4;
  matrix_correct(1, 1) = -14;
  matrix_correct(1, 2) = 8;
  matrix_correct(2, 0) = -8;
  matrix_correct(2, 1) = -2;
  matrix_correct(2, 2) = 4;
  S21Matrix matrix_b = matrix_a.CalcComplements();
  ASSERT_TRUE(matrix_b.EqMatrix(matrix_correct));
}

TEST(TestDeterminant, Test_1) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = -4;
  matrix_a(1, 0) = 2;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 1;
  matrix_a(2, 0) = 3;
  matrix_a(2, 1) = -1;
  matrix_a(2, 2) = 2;
  ASSERT_DOUBLE_EQ(49, matrix_a.Determinant());
}

TEST(TestDeterminant, Test_2) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 1.56;
  ASSERT_DOUBLE_EQ(1.56, matrix_a.Determinant());
}

TEST(TestInverse, Test_1) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = -2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 4;
  matrix_a(1, 2) = -1;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = 0;
  matrix_a(2, 2) = 0;
  S21Matrix matrix_correct(3, 3);
  matrix_correct(0, 0) = 0;
  matrix_correct(0, 1) = 0;
  matrix_correct(0, 2) = 0.2;
  matrix_correct(1, 0) = 0.1;
  matrix_correct(1, 1) = 0.3;
  matrix_correct(1, 2) = -0.02;
  matrix_correct(2, 0) = 0.4;
  matrix_correct(2, 1) = 0.2;
  matrix_correct(2, 2) = -0.08;
  S21Matrix matrix_b = matrix_a.InverseMatrix();
  ASSERT_TRUE(matrix_b.EqMatrix(matrix_correct));
}

TEST(TestInverse, Test_2) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 1.56;
  S21Matrix matrix_b = matrix_a.InverseMatrix();
  ASSERT_DOUBLE_EQ(1.0 / 1.56, matrix_b(0, 0));
}

TEST(TestSumOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillMatrix(2, 3, 1);
  S21Matrix matrix_c = matrix_a + matrix_b;
  S21Matrix matrix_correct = FillWithStep(2, 3, 2.1234567);
  ASSERT_TRUE(matrix_c.EqMatrix(matrix_correct));
}

TEST(TestSubOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 2.1234567);
  S21Matrix matrix_b = FillMatrix(2, 3, 1);
  S21Matrix matrix_c = matrix_a - matrix_b;
  S21Matrix matrix_correct = FillWithStep(2, 3, 1.1234567);
  ASSERT_TRUE(matrix_c.EqMatrix(matrix_correct));
}

TEST(TestMultMatrixOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillWithStep(3, 2, 56.987654321);
  S21Matrix matrix_c = matrix_a * matrix_b;
  S21Matrix matrix_correct(2, 2);
  matrix_correct(0, 0) = 379.773189;
  matrix_correct(0, 1) = 386.143559;
  matrix_correct(1, 0) = 910.662078;
  matrix_correct(1, 1) = 926.032448;
  ASSERT_TRUE(matrix_c.EqMatrix(matrix_correct));
}

TEST(TestMultNumOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_c = matrix_a * 1.12345670;
  S21Matrix matrix_correct(2, 3);
  matrix_correct(0, 0) = 1.262155;
  matrix_correct(0, 1) = 2.385612;
  matrix_correct(0, 2) = 3.509068;
  matrix_correct(1, 0) = 4.632525;
  matrix_correct(1, 1) = 5.755982;
  matrix_correct(1, 2) = 6.879438;
  ASSERT_TRUE(matrix_c.EqMatrix(matrix_correct));
}

TEST(TestEqualOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillWithStep(2, 3, 1.1234567);
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(TestSumEqOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillMatrix(2, 3, 1);
  matrix_a += matrix_b;
  S21Matrix matrix_correct = FillWithStep(2, 3, 2.1234567);
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestSubEqOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 2.1234567);
  S21Matrix matrix_b = FillMatrix(2, 3, 1);
  matrix_a -= matrix_b;
  S21Matrix matrix_correct = FillWithStep(2, 3, 1.1234567);
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestMultEqMatrixOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = FillWithStep(3, 2, 56.987654321);
  matrix_a *= matrix_b;
  S21Matrix matrix_correct(2, 2);
  matrix_correct(0, 0) = 379.773189;
  matrix_correct(0, 1) = 386.143559;
  matrix_correct(1, 0) = 910.662078;
  matrix_correct(1, 1) = 926.032448;
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestMultEqNumOperator, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  matrix_a *= 1.12345670;
  S21Matrix matrix_correct(2, 3);
  matrix_correct(0, 0) = 1.262155;
  matrix_correct(0, 1) = 2.385612;
  matrix_correct(0, 2) = 3.509068;
  matrix_correct(1, 0) = 4.632525;
  matrix_correct(1, 1) = 5.755982;
  matrix_correct(1, 2) = 6.879438;
  ASSERT_TRUE(matrix_a.EqMatrix(matrix_correct));
}

TEST(TestMoveAssignment, Test_1) {
  S21Matrix matrix_a = FillWithStep(2, 3, 1.1234567);
  S21Matrix matrix_b = std::move(matrix_a);
  S21Matrix matrix_correct = FillWithStep(2, 3, 1.1234567);
  ASSERT_TRUE(matrix_b.EqMatrix(matrix_correct));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}