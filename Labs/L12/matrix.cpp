#include "matrix.h"


Matrix::Matrix(unsigned int size, double def) {
    if (size > 0) {
      arr.resize(size);
      for (int i = 0; i < size; i++) {
        arr[i].resize(size);
        if (def) {
          fill(arr[i].begin(), arr[i].end(), def); 
        }
      }
    } else {
      cerr << "Error in class constructor: Matrix is not square" << endl;
    }
}

Matrix::Matrix(vector <vector <double>> temp):
  Matrix (get_size(temp)) {
    arr = temp;
}

const unsigned int Matrix::size() {
  return arr.size();
}

Matrix& Matrix::set(unsigned int x, unsigned int y, double value) {
    if (x < arr.size() && y < arr.size()) {
      arr[y][x] = value;
    } else {
    cerr << "Error in 'set' operator: Invalid index" << endl;
  }
  return *this;
}

Matrix& Matrix::set(vector <vector <double>> temp) {
  if (get_size(temp) == arr.size()) {
    arr = temp;
  } else {
    cerr << "Error in 'set' operator: Target matrix has different size" << endl;
  }
  return *this;
}

Matrix& Matrix::set(Matrix& m) {
  arr = m.arr;
  return *this;
}


double Matrix::get(unsigned int x, unsigned int y) {
    if (x < arr.size() && y < arr.size()) {
      return arr[y][x];
    } else {
    cerr << "Error in 'get' operator: Invalid index" << endl;
  }
}

unsigned int get_size(vector <vector <double>> arr) {
  unsigned int size = arr.size();
  for (int i = 0; i < size; i++) {
    if (arr[i].size() != size) {
      return 0;
    }
  }
  return size;
}

void Matrix::print() {
  for (int y = 0; y < arr.size(); y++, cout << endl)
    for (int x = 0; x < arr[y].size(); x++)
      cout << arr[y][x] << " ";
  cout << endl;
}


Matrix operator-(const Matrix &m) {
  Matrix temp(m);
  for (int x = 0; x < temp.arr.size(); x++)
    for (int y = 0; y < temp.arr.size(); y++)
      temp.arr[y][x] *= -1;
	return temp;
}

void swap(double *d1, double *d2) { 
  double temp = *d1;
  *d1 = *d2;
  *d2 = temp;
}

Matrix Matrix::transpose() {
  Matrix temp(*this);
  for (int y = 0; y < this->size() - 1; y++) {
    for (int x = y + 1; x < this->size(); x++) {
      swap(&temp.arr[y][x], &temp.arr[x][y]);
    }
  }
  return temp;
}

Matrix Matrix::minor(int _y, int _x) {
  Matrix temp(arr.size() - 1);
  bool skip_x, skip_y = 0;
  for (int y = 0; y < temp.arr.size(); y++) {
    if (y == _y) skip_y = 1;
    skip_x = 0;
    for (int x = 0; x < temp.arr.size(); x++) {
      if (x == _x) skip_x = 1;
      temp.set(x, y, arr[y + skip_y][x + skip_x]);
    }
  }
  return temp;
}

const double Matrix::determinant() {
  switch (arr.size()) {
    case 1:
      return arr[0][0];

    case 2:
      return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];

    default:
      double det = 0;
      for (int i = 0; i < arr.size(); i++)
        det += (i % 2 ? -1 : 1) * arr[i][0] * this->minor(i, 0).determinant();
      return det;
  }
}

Matrix Matrix::minor_matrix() {
  Matrix temp(arr.size());
  for (int y = 0; y < arr.size(); y ++) {
    for (int x = 0; x < arr.size(); x++) {
      temp.set(x, y, this->minor(y, x).determinant());
    }
  }
  return temp;
}

Matrix Matrix::algebraic_additions() {
  Matrix temp = this->minor_matrix();
  for (int x = 0; x < arr.size(); x++) {
    for (int y = 0; y < arr.size(); y++) {
      if ((x + y) % 2) temp.arr[y][x] *= -1;
    }
  }
  return temp;
}

Matrix Matrix::inverse() {
  Matrix alg_add_T = this->algebraic_additions().transpose();
  alg_add_T /= this->determinant();
  return alg_add_T;
}


Matrix& Matrix::operator+=(const Matrix& m) {
    if (arr.size() == m.arr.size()) {
      for (int x = 0; x < m.arr.size(); x++) {
        for (int y = 0; y < m.arr.size(); y++) {
          arr[y][x] += m.arr[y][x];
        }
      }
    } else {
      cerr << "Error in + operator: Matrices have different sizes" << endl;
    }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
    if (arr.size() == m.arr.size()) {
      *this += -m;
    } else {
      cerr << "Error in - operator: Matrices have different sizes" << endl;
    }
  return *this;
}

Matrix operator+(Matrix a, const Matrix& b) {
  a += b;
  return a;
}

Matrix operator-(Matrix a, const Matrix& b) {
  a -= b;
  return a;
}

Matrix& Matrix::operator*=(const Matrix& right) {
  if (right.arr.size() == arr.size()) {
    unsigned int size = this->size();
    Matrix result(size, 0);
    for (int result_x = 0; result_x < arr.size(); result_x++) {
      for (int result_y = 0; result_y < arr.size(); result_y++) {
        double summ = 0;
        for (int i = 0; i < size; i++)
          summ += arr[result_y][i] * right.arr[i][result_x];
        result.arr[result_y][result_x] = summ;
      }
    }
    *this = result;
  } else {
    cerr << "Error in * operator: Matrices have different sizes" << endl;
  }
  return *this;
}

Matrix operator*(Matrix a, const Matrix& b) {
  a *= b;
  return a;
}

Matrix& Matrix::operator*=(const double& n) {
  for (int x = 0; x < arr.size(); x++) {
    for (int y = 0; y < arr.size(); y++) {
      arr[y][x] *= n;
    }
  }
  return *this;
}

Matrix operator*(Matrix a, const double &b) {
  a *= b;
  return a;
}


Matrix& Matrix::operator/=(const Matrix &b) {
  *this *= Matrix(b).inverse();
  return *this;
}

Matrix operator/(Matrix a, const Matrix &b) {
    a /= b;
    return a;
}

Matrix& Matrix::operator/=(const double& n) {
  for (int x = 0; x < arr.size(); x++) {
    for (int y = 0; y < arr.size(); y++) {
      arr[y][x] /= n;
    }
  }
  return *this;
}

Matrix operator/(Matrix a, const double &b) {
  a /= b;
  return a;
}