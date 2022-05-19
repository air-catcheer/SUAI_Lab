#pragma once

#include <vector>
#include <iostream>
using namespace std;

unsigned int get_size(vector <vector <double>> arr); 

class Matrix {
  private:
    vector <vector <double>> arr;

  public:
  
    Matrix(unsigned int size = 1, double def = 0); 
    Matrix(vector <vector <double>> temp); 

    
    Matrix& set(unsigned int x, unsigned int y, double value);
    Matrix& set(vector <vector <double>> temp);
    Matrix& set(Matrix& m); 


    double get(unsigned int x, unsigned int y);
    const unsigned int size();
    const double determinant(); 
    void print();

   
    Matrix transpose();
    Matrix inverse();
    Matrix minor(int i, int j);
    Matrix minor_matrix();
    Matrix algebraic_additions();

    
    Matrix& operator+=(const Matrix& x); 
    Matrix& operator-=(const Matrix& x); 
    Matrix& operator*=(const Matrix& x); 
    Matrix& operator*=(const double& x); 
    Matrix& operator/=(const Matrix& x); 
    Matrix& operator/=(const double& x); 
    
    friend Matrix operator-(const Matrix &m); 
    friend Matrix operator+(Matrix a, const Matrix &b);
    friend Matrix operator-(Matrix a, const Matrix &b);
    friend Matrix operator*(Matrix a, const Matrix &b);
    friend Matrix operator*(Matrix a, const double &b);
    friend Matrix operator/(Matrix a, const Matrix &b);
    friend Matrix operator/(Matrix a, const double &b);
};