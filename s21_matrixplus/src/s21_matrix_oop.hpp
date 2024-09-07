#ifndef __S21MATRIX_OOP_H__
#define __S21MATRIX_OOP_H__

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  // Constructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(int rows, int cols, std::initializer_list<double> list);
  S21Matrix(const S21Matrix& other) noexcept;  // Copy constructor
  S21Matrix(S21Matrix&& other) noexcept;       // Move constructor
  ~S21Matrix();

  // Accessors and Mutators
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int row);
  void SetCols(int col);

  // Methods
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Operators overloads
  double& operator()(int row, int col);
  double operator()(int row, int col) const;
  S21Matrix operator=(S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);

  bool operator==(const S21Matrix& other) noexcept;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);

  friend S21Matrix operator*(const S21Matrix& other, const double num);
  friend S21Matrix operator*(const double num, const S21Matrix& other);
  friend S21Matrix operator*=(S21Matrix& other, const double num);

 private:
  int rows_;
  int cols_;
  double* matrix_;

  const double Accuracy = 1.0E-7;

  double CalcMinor(int row, int col);
  int ColumnWithMaxElement(int column);
  int Triangulation();

  void InitializeMatrix(std::initializer_list<double> list) noexcept;
};

#endif
// __S21MATRIX_OOP_H__
