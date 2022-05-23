#pragma once

#include <vector>
#include <iostream>
using namespace std;

unsigned int get_size(vector <vector <double>> arr); //получает размер двумерного вектора

class Matrix {
  private:
    vector <vector <double>> arr;

  public:
    // конструкторы
    Matrix(unsigned int size = 1, double def = 0); // конструктор по умолчанию (размер и значение по умолчанию)
    Matrix(vector <vector <double>> temp); //конструктор матрицы от двумернго вектора

    // сеттеры - функции которые изменяют состояние объекта класса
    Matrix& set(unsigned int x, unsigned int y, double value);// координаты и задаваемое значение
    Matrix& set(vector <vector <double>> temp);
    Matrix& set(Matrix& m); 

    // геттеры -  функции которые получают значения приватных переменных
    double get(unsigned int x, unsigned int y);
    const unsigned int size();
    const double determinant(); // определитель
    void print();

    // преобразования
    Matrix transpose();
    Matrix inverse();
    Matrix minor(int i, int j);
    Matrix minor_matrix();
    Matrix algebraic_additions();

    // операторы
    Matrix& operator+=(const Matrix& x); // сложение с матрицей
    Matrix& operator-=(const Matrix& x); // вычитание матрицы
    Matrix& operator*=(const Matrix& x); // умножение на матрицу
    Matrix& operator*=(const double& x); // умножение на скаляр
    Matrix& operator/=(const Matrix& x); // деление на матрицу
    Matrix& operator/=(const double& x); // деление на скаляр
    
    friend Matrix operator-(const Matrix &m); // унарный минус (смена знаков всех элементов матрицы)
    friend Matrix operator+(Matrix a, const Matrix &b);
    friend Matrix operator-(Matrix a, const Matrix &b);
    friend Matrix operator*(Matrix a, const Matrix &b);
    friend Matrix operator*(Matrix a, const double &b);
    friend Matrix operator/(Matrix a, const Matrix &b);
    friend Matrix operator/(Matrix a, const double &b);
};