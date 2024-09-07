#include "test_matrix_oop.hpp"

TEST(Constructors, test_01) {
  EXPECT_THROW(S21Matrix(0, 1), std::invalid_argument);
  EXPECT_THROW(S21Matrix(1, 0), std::invalid_argument);
  EXPECT_THROW(S21Matrix(-1, 1), std::invalid_argument);
  EXPECT_THROW(S21Matrix(1, -1), std::invalid_argument);
  EXPECT_THROW(S21Matrix(2, -2, {1, 2, 3, 4}), std::invalid_argument);
}

TEST(Constructors, test_02) {
  S21Matrix A;
  EXPECT_TRUE(A.GetRows() == 1);
  EXPECT_TRUE(A.GetCols() == 1);

  S21Matrix B(21, 12);
  EXPECT_TRUE(B.GetRows() == 21);
  EXPECT_TRUE(B.GetCols() == 12);

  S21Matrix B_copied(B);
  EXPECT_TRUE(B_copied.GetRows() == 21);
  EXPECT_TRUE(B_copied.GetCols() == 12);

  S21Matrix D(21, 12);
  S21Matrix D_moved = std::move(D);
  EXPECT_TRUE(D_moved.GetRows() == 21);
  EXPECT_TRUE(D_moved.GetCols() == 12);
  EXPECT_TRUE(D.GetRows() == 0);
  EXPECT_TRUE(D.GetCols() == 0);
}

TEST(SetRowCol, test_01) {
  S21Matrix A(1, 1);
  A.SetRows(21);
  EXPECT_TRUE(A.GetRows() == 21);

  S21Matrix B(1, 1);
  B.SetCols(12);
  EXPECT_TRUE(B.GetCols() == 12);

  S21Matrix C(1, 1);
  C.SetRows(3);
  C.SetCols(5);
  EXPECT_TRUE(C.GetRows() == 3);
  EXPECT_TRUE(C.GetCols() == 5);
}

TEST(SetRowCol, test_02) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A.SetRows(-9), std::invalid_argument);

  S21Matrix B(2, 2);
  EXPECT_THROW(B.SetCols(-9), std::invalid_argument);

  S21Matrix C(2, 2);
  EXPECT_THROW(C.SetRows(0), std::invalid_argument);

  S21Matrix D(2, 2);
  EXPECT_THROW(D.SetCols(0), std::invalid_argument);
}

TEST(EqMatrix, test_01) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B(2, 2, {4, 3, 2, 1});
  EXPECT_FALSE(A.EqMatrix(B));

  S21Matrix C(1, 2);
  S21Matrix D(2, 3);
  EXPECT_FALSE(C.EqMatrix(D));

  S21Matrix E(2, 3, {1, 2, 3, 4, 5, 6});
  S21Matrix F(2, 3, {1, 4, 2, 5, 3, -6});
  EXPECT_FALSE(E.EqMatrix(F));
  EXPECT_FALSE(E == F);
}

TEST(EqMatrix, test_02) {
  S21Matrix A(2, 3, {1, 2, 3, 4, 5, 6});
  S21Matrix B(2, 3, {1, 2, 3, 4, 5, 6});
  EXPECT_TRUE(A.EqMatrix(B));
  EXPECT_TRUE(A == B);
}

TEST(SumMatrix, test_01) {
  S21Matrix A(2, 3, {1, 2, 3, 3, 2, 1});
  S21Matrix B(2, 3, {1, 2, 3, 3, 2, 1});
  A.SumMatrix(B);
  S21Matrix res_1(2, 3, {2, 4, 6, 6, 4, 2});
  EXPECT_TRUE(A.EqMatrix(res_1));

  S21Matrix C(2, 2, {0, 1, 1, 0});
  EXPECT_THROW(A.SumMatrix(C), std::out_of_range);

  S21Matrix D(3, 2, {0, 1, 1, 0, 2, 2});
  EXPECT_THROW(A.SumMatrix(D), std::out_of_range);

  S21Matrix X(2, 3, {1, 2, 3, 3, 2, 1});
  S21Matrix Y(2, 3, {1, 2, 3, 3, 2, 1});
  S21Matrix res_2(2, 3, {2, 4, 6, 6, 4, 2});
  EXPECT_TRUE(res_2.EqMatrix(X + Y));

  EXPECT_THROW(A + C, std::out_of_range);

  S21Matrix K(2, 3, {1, 2, 3, 3, 2, 1});
  S21Matrix M(2, 3, {1, 2, 3, 3, 2, 1});
  S21Matrix res_3(2, 3, {2, 4, 6, 6, 4, 2});
  K += M;
  EXPECT_TRUE(res_3.EqMatrix(K));

  EXPECT_THROW(M += D, std::out_of_range);
}

TEST(SubMatrix, test_01) {
  S21Matrix A(2, 3, {9, 8, 7, 7, 8, 9});
  S21Matrix B(2, 3, {1, 2, 3, 1, 2, 3});
  A.SubMatrix(B);
  S21Matrix res_1(2, 3, {8, 6, 4, 6, 6, 6});
  EXPECT_TRUE(A.EqMatrix(res_1));

  S21Matrix C(2, 2, {0, 1, 1, 0});
  EXPECT_THROW(A.SubMatrix(C), std::out_of_range);

  S21Matrix D(3, 2, {0, 1, 1, 0, 2, 2});
  EXPECT_THROW(A.SubMatrix(D), std::out_of_range);

  S21Matrix X(2, 3, {9, 8, 7, 7, 8, 9});
  S21Matrix Y(2, 3, {1, 2, 3, 1, 2, 3});
  S21Matrix res_2(2, 3, {8, 6, 4, 6, 6, 6});
  EXPECT_TRUE(res_2.EqMatrix(X - Y));

  EXPECT_THROW(A - C, std::out_of_range);

  S21Matrix K(2, 3, {1, 2, 3, 3, 2, 1});
  S21Matrix M(2, 3, {1, 2, 3, 3, 2, 1});
  S21Matrix res_3(2, 3, {0, 0, 0, 0, 0, 0});
  K -= M;
  EXPECT_TRUE(res_3.EqMatrix(K));

  EXPECT_THROW(M -= D, std::out_of_range);
}

TEST(MulNumber, test_01) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  A.MulNumber(-1);
  S21Matrix res_1(2, 2, {-1, -2, -3, -4});
  EXPECT_TRUE(A.EqMatrix(res_1));

  S21Matrix B(2, 5, {1, 2, 3, 4, 5});
  B.MulNumber(0);
  S21Matrix res_2(2, 5);
  EXPECT_TRUE(B.EqMatrix(res_2));

  S21Matrix C(2, 3, {1, 2, 3, 4, 5, 6});
  S21Matrix res_3(2, 3, {-1, -2, -3, -4, -5, -6});
  EXPECT_TRUE(res_3.EqMatrix((C) * (-1)));

  S21Matrix D(2, 3, {1, 2, 3, 4, 5, 6});
  S21Matrix res_4(2, 3);
  EXPECT_TRUE(res_4.EqMatrix((D)*0));

  S21Matrix E(2, 3, {1, 2, 3, 4, 5, 6});
  S21Matrix res_5(2, 3, {-1, -2, -3, -4, -5, -6});
  EXPECT_TRUE(res_5.EqMatrix((-1) * E));

  S21Matrix F(2, 3, {1, 2, 3, 4, 5, 6});
  S21Matrix res_6(2, 3);
  EXPECT_TRUE(res_6.EqMatrix((0 * E)));

  S21Matrix res_7(2, 2, {1, 2, 3, 4});
  A *= -1;
  EXPECT_TRUE(res_7.EqMatrix(A));

  S21Matrix res_8(2, 2);
  A *= 0;
  EXPECT_TRUE(res_8.EqMatrix(A));
}

TEST(MulMatrix, test_01) {
  S21Matrix A(2, 3, {1, 0, 0, 1, 0, 0});
  S21Matrix B(3, 2, {2, 3, 0, 0, 0, 0});
  A.MulMatrix(B);
  S21Matrix res_1(2, 2, {2, 3, 2, 3});
  EXPECT_TRUE(A.GetRows() == 2);
  EXPECT_TRUE(A.GetCols() == 2);
  EXPECT_TRUE(A.EqMatrix(res_1));

  S21Matrix C(5, 2);
  EXPECT_THROW(A.MulMatrix(C), std::out_of_range);

  S21Matrix D(1, 1, {1});
  S21Matrix E(1, 1, {2});
  D.MulMatrix(E);
  S21Matrix res_2(1, 1, {2});
  EXPECT_TRUE(D.GetRows() == 1);
  EXPECT_TRUE(D.GetCols() == 1);
  EXPECT_TRUE(res_2.EqMatrix(D));

  S21Matrix K(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});
  S21Matrix M(3, 3, {1, 1, 1, 1, 1, 1, 1, 1, 1});
  K.MulMatrix(M);
  S21Matrix res_3(3, 3, {1, 1, 1, 1, 1, 1, 1, 1, 1});
  EXPECT_TRUE(K.GetRows() == 3);
  EXPECT_TRUE(K.GetCols() == 3);
  EXPECT_TRUE(res_3.EqMatrix(K));

  S21Matrix X(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});
  S21Matrix Y(3, 3, {1, 1, 1, 1, 1, 1, 1, 1, 1});
  X *= Y;
  S21Matrix res_4(3, 3, {1, 1, 1, 1, 1, 1, 1, 1, 1});
  EXPECT_TRUE(res_4.EqMatrix(X));

  S21Matrix W(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});
  S21Matrix Z(3, 3, {1, 1, 1, 1, 1, 1, 1, 1, 1});
  S21Matrix res_5(3, 3, {1, 1, 1, 1, 1, 1, 1, 1, 1});
  EXPECT_TRUE(res_5.EqMatrix(W * Z));
}

TEST(Transpose, test_01) {
  S21Matrix A(2, 3, {1, 2, 3, 4, 5, 6});
  S21Matrix T = A.Transpose();
  S21Matrix res(3, 2, {1, 4, 2, 5, 3, 6});
  EXPECT_TRUE(T.EqMatrix(res));
}

TEST(Transpose, test_02) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix T = A.Transpose();
  S21Matrix res(2, 2, {1, 2, 3, 4});
  EXPECT_FALSE(T.EqMatrix(res));
}

TEST(CalcComplements, test_01) {
  S21Matrix A(2, 3, {1, 0, 0, 1, 0, 0});
  EXPECT_THROW(A.CalcComplements(), std::out_of_range);

  S21Matrix B(1, 1, {8});
  S21Matrix res_1(1, 1, {1});
  S21Matrix Complements_1 = B.CalcComplements();
  EXPECT_TRUE(Complements_1.EqMatrix(res_1));

  S21Matrix C(2, 2, {8, 0, 0, 1});
  S21Matrix res_2(2, 2, {1, 0, 0, 8});
  S21Matrix Complements_2 = C.CalcComplements();
  EXPECT_TRUE(Complements_2.EqMatrix(res_2));

  S21Matrix D(3, 3, {8, 0, 0, 0, 1, 0, 0, 0, 1});
  S21Matrix res_3(3, 3, {1, 0, 0, 0, 8, 0, 0, 0, 8});
  S21Matrix Complements_3 = D.CalcComplements();
  EXPECT_TRUE(Complements_3.EqMatrix(res_3));

  S21Matrix E(3, 3, {2, 3, 1, 7, 4, 1, 9, -2, 1});
  S21Matrix res_4(3, 3, {6, 2, -50, -5, -7, 31, -1, 5, -13});
  S21Matrix Complements_4 = E.CalcComplements();
  EXPECT_TRUE(Complements_4.EqMatrix(res_4));

  S21Matrix F(5, 5, {0, 6, -2, -1, 5,   0,  0, 0,  -9, -7, 0, 15, 35,
                     0, 0, 0,  -1, -11, -2, 1, -2, -2, 3,  0, -2});
  S21Matrix res_5(5, 5,
                  {305,  -1610, 690,   -1820, 2340, 335,   -630,  270,  -820,
                   700,  -398,  1052,  -380,  952,  -1224, -1660, 3640, -1560,
                   3360, -4320, -1240, 0,     0,    0,     0});
  S21Matrix Complements_5 = F.CalcComplements();
  EXPECT_TRUE(Complements_5.EqMatrix(res_5));

  S21Matrix G(7, 7);
  S21Matrix res_6(7, 7);
  S21Matrix Complements_6 = G.CalcComplements();
  EXPECT_TRUE(Complements_6.EqMatrix(res_6));
}

TEST(Determinant, test_01) {
  S21Matrix A(2, 3, {1, 0, 0, 1, 0, 0});
  EXPECT_THROW(A.Determinant(), std::out_of_range);

  S21Matrix B(1, 1, {8});
  double det_B = B.Determinant();
  EXPECT_EQ(det_B, 8);

  S21Matrix C(2, 2, {8, 0, 0, 1});
  double det_C = C.Determinant();
  EXPECT_EQ(det_C, 8);

  S21Matrix D(2, 2, {-5, -4, -2, -3});
  double det_D = D.Determinant();
  EXPECT_EQ(det_D, 7);

  S21Matrix E(3, 3, {2, 3, 1, 7, 4, 1, 9, -2, 1});
  double det_E = E.Determinant();
  EXPECT_EQ(det_E, -32);

  S21Matrix F(4, 4, {9, 6, -2, -1, 5, 3, 0, 0, -9, -7, 0, 15, 35, 1, 2, 0});
  double det_F = F.Determinant();
  EXPECT_LE(abs(det_F + 2926.0), ACCURACY);
}

TEST(InverseMatrix, test_01) {
  S21Matrix A(2, 3, {1, 0, 0, 1, 0, 0});
  EXPECT_THROW(A.InverseMatrix(), std::out_of_range);

  S21Matrix B(1, 1, {0});
  EXPECT_THROW(B.InverseMatrix(), std::logic_error);

  S21Matrix C(7, 7);
  EXPECT_THROW(C.InverseMatrix(), std::logic_error);

  S21Matrix D(1, 1, {8});
  S21Matrix res_1(1, 1, {0.125});
  S21Matrix InverseMatrix_1 = D.InverseMatrix();
  EXPECT_TRUE(InverseMatrix_1.EqMatrix(res_1));

  S21Matrix F(4, 4, {8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
  S21Matrix res_3(4, 4, {0.125, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
  S21Matrix InverseMatrix_3 = F.InverseMatrix();
  EXPECT_TRUE(InverseMatrix_3.EqMatrix(res_3));

  S21Matrix K(3, 3, {2, 5, 7, 6, 3, 4, 5, -2, -3});
  S21Matrix res_4(3, 3, {1, -1, 1, -38, 41, -34, 27, -29, 24});
  S21Matrix InverseMatrix_4 = K.InverseMatrix();
  EXPECT_TRUE(InverseMatrix_4.EqMatrix(res_4));
}

TEST(Group, test_01) {
  S21Matrix A(5, 5);
  S21Matrix B(3, 3);
  A = B;
  EXPECT_EQ(A.GetRows(), B.GetRows());
  EXPECT_EQ(A.GetCols(), B.GetCols());

  S21Matrix C(2, 6);
  S21Matrix D(1, 4);
  D = C;
  EXPECT_EQ(C.GetRows(), D.GetRows());
  EXPECT_EQ(C.GetCols(), D.GetCols());
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  if (RUN_ALL_TESTS())
    std::cout << "Some tests was failed. You have to fix it." << std::endl;
  return 0;
}