#include "s21_matrix_oop.hpp"

// Default constructor
S21Matrix::S21Matrix() : rows_(1), cols_(1) {
  matrix_ = new double[rows_ * cols_]();
}

// Parametrized constructor
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("Matrix size must be greater than 0.\n");
  }
  matrix_ = new double[rows_ * cols_]();
}

S21Matrix::S21Matrix(int rows, int cols, std::initializer_list<double> list)
    : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("Matrix size must be greater than 0.\n");
  }
  matrix_ = new double[rows_ * cols_]();
  InitializeMatrix(list);
}

// Copy
S21Matrix::S21Matrix(const S21Matrix& other) noexcept
    : rows_(other.rows_),
      cols_(other.cols_),
      matrix_(new double[rows_ * cols_]) {
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

// Move
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

// Destructor
S21Matrix::~S21Matrix() {
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

// Accessors and Mutators
int S21Matrix::GetRows() const noexcept { return rows_; }
int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int row) {
  if (row < 1) {
    throw std::invalid_argument("Value must be greater or equal then 0.\n");
  }
  rows_ = row;
}

void S21Matrix::SetCols(int col) {
  if (col < 1) {
    throw std::invalid_argument("Value must be greater or equal then 0.\n");
  }
  cols_ = col;
}

// Equal
bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    return false;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::abs((*this)(i, j) - (other)(i, j)) > Accuracy) {
        return false;
      }
    }
  }
  return true;
}

// Sum
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    throw std::out_of_range("The matrices sizes is different.\n");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) += other(i, j);
    }
  }
}

// Sub
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    throw std::out_of_range("The matrices sizes is different.\n");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

// MulNumber
void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) *= num;
    }
  }
}

// MulMatrix
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.GetRows()) {
    throw std::out_of_range(
        "The columns of first matrix is not equal to second matrix rows.\n");
  }

  S21Matrix result(rows_, other.GetCols());

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      for (int k = 0; k < cols_; ++k) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  *this = std::move(result);
}

// Transpose
S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(j, i) = (*this)(i, j);
    }
  }

  return result;
}

// CalcComplements
S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(rows_, cols_);
  if (rows_ != cols_) {
    throw std::out_of_range("Rows and columns is not equal.\n");
  }

  if (rows_ == 1) {
    result(0, 0) = 1;
  } else {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        result(i, j) = CalcMinor(i, j) * pow(-1, (i + j));
      }
    }
  }

  return result;
}

double S21Matrix::CalcMinor(int row, int col) {
  double result = 0.0;
  S21Matrix Temp(rows_ - 1, cols_ - 1);
  for (int i = 0, k = 0; i < rows_; ++i, ++k) {
    if (i == row) {
      ++i;
    }
    for (int j = 0, m = 0; j < cols_; ++j, ++m) {
      if (j == col) {
        ++j;
      }
      if (i < rows_ && j < cols_) {
        Temp(k, m) = (*this)(i, j);
      }
    }
  }
  result = Temp.Determinant();
  return result;
}

// Determinant
double S21Matrix::Determinant() {
  double det = 0;
  if (rows_ != cols_) {
    throw std::out_of_range("Rows and columns is not equal.\n");
  }

  if (rows_ == 1) {
    det = (*this)(0, 0);
  } else if (rows_ == 2) {
    det = (*this)(0, 0) * (*this)(1, 1);
    det -= (*this)(0, 1) * (*this)(1, 0);
  } else {
    det = 1.0;
    int swap_count = Triangulation();
    for (int i = 0; i < rows_; ++i) {
      det *= (*this)(i, i);
    }
    if (swap_count % 2 == 1) {
      det *= -1;
    }
  }
  return det;
}

int S21Matrix::ColumnWithMaxElement(int column) {
  double max = std::abs((*this)(column, column));
  int max_position = column;
  for (int i = column + 1; i < rows_; ++i) {
    double element = std::abs((*this)(i, column));
    if (element > max) {
      max = element;
      max_position = i;
    }
  }
  return max_position;
}

int S21Matrix::Triangulation() {
  int swap_count = 0;
  for (int i = 0; i < cols_ - 1; ++i) {
    int i_max = ColumnWithMaxElement(i);
    if (i != i_max) {
      for (int j = 0; j < cols_; ++j) {
        std::swap((*this)(i, j), (*this)(i_max, j));
      }
      swap_count++;
    }
    if ((*this)(i, i) != 0) {
      for (int j = i + 1; j < rows_; ++j) {
        double multiplicator = -(*this)(j, i) / (*this)(i, i);

        for (int k = i; k < cols_; ++k) {
          (*this)(j, k) += (*this)(i, k) * multiplicator;
        }
      }
    }
  }
  return swap_count;
}

// InverseMatrix
S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::out_of_range("Rows and columns is not equal.\n");
  }
  S21Matrix Copy = Transpose().CalcComplements();
  if (std::abs(Determinant()) < Accuracy) {
    throw std::logic_error("Determinant is equal to 0.\n");
  }
  return Copy * (1.0 / Determinant());
}

// Operators overloads
double& S21Matrix::operator()(int row, int col) {
  return matrix_[row * cols_ + col];
}

double S21Matrix::operator()(int row, int col) const {
  return matrix_[row * cols_ + col];
}

S21Matrix S21Matrix::operator=(S21Matrix& other) {
  S21Matrix copy(other);
  (*this) = std::move(copy);
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;

    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return (*this);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result += other;
  return result;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return (*this);
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result -= other;
  return result;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return (*this);
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result *= other;
  return result;
}

S21Matrix operator*(const double num, const S21Matrix& other) {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

S21Matrix operator*(const S21Matrix& other, const double num) {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

S21Matrix operator*=(S21Matrix& other, const double num) {
  other.MulNumber(num);
  return other;
}

void S21Matrix::InitializeMatrix(std::initializer_list<double> list) noexcept {
  int size = rows_ * cols_;
  int i = 0;
  for (double elem : list) {
    if (i >= size) break;
    matrix_[i] = elem;
    i++;
  }
  while (i < size) {
    *(matrix_ + i) = 0;
    i++;
  }
}