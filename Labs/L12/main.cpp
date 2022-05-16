// Создайте класс SqrMatrix
// (квадратная матрица с элементами типа double)
// с операциями + - * /, умножения на скаляр
// Размерность матрицы задать в конструкторе

// TODO:
// Используйте приватные поля для данных
// Реализуйте конструктор, который должен устанавливать значения по умолчанию, 
// Реализуйте методы для чтения и записи значений полей (set, get), а также ввода и вывода (перегрузка operator<< и operator>> не требуется)
// Если требуется, напишите конструктор копий, оператор присваивания и деструктор 
// Напишите программу для тестирования вашего класса

#include "matrix.h"

int main() {
  Matrix m1;
  m1.print();

  Matrix m2(10);
  m2.print();

  Matrix m3(
    {
      {1, 2, 3, 4},
      {1, 2, 3, 4},
      {1, 2, 3, 4},
      {1, 2, 3, 4},
    }
  );
  m3.print();

  Matrix m4(m3);
  m4.print();

  Matrix m5(
    {
      {1, 2},
      {3, 4}
    }
  );
  m5.print();

  m5 = m3;
  m5.print();

  /* 
  // Error in class constructor: Matrix is not square
  Matrix m6(
    {
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
    }
  );
  m6.print();
  */

  Matrix m7(5, 0.01);
  for (int i = 0; i < m7.size(); i++)
    m7.set(i, i, 9.99);
  
  m7.set(4, 2, 3.14);
  m7.print();

  /*
  // Error in 'set' operator: Invalid index
  m7.set(100, 100, 0);
  m7.print();
  */

  m7.set(
    {
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5}
    }
  );
  m7.print();

  /*
  // Error in 'set' operator: Target matrix has different size
  m7.set(
    {
      {1, 2},
      {3, 4}
    }
  );
  m7.print();
  */

  // тестируем выполнение операторов по цепочке
  // в каждом операторе возвращаем ссылку на this 
  // и поэтому следующий оператор производит действие над тем же объектом
  
  m7.set(0, 0, 0)
    .set(0, m7.size()-1, 0)
    .set(m7.size()-1, 0, 0)
    .set(m7.size()-1, m7.size()-1, 0)
    .print();

  Matrix m8(3, 0.1);
  m8.print();

  m8.set(
    {
      {9, 8, 7},
      {6, 5, 4},
      {3, 2, 1}
    }
  ).set(2, 2, 0).print();

  Matrix m9(3);
  m9.set(m8).set(2, 2, 1).print();

  Matrix m10(10);
  m10.set(0, 0, 2).set(9, 9, 9).print();

  cout << m10.get(0, 0) << " at 0, 0" << endl
       << m10.get(9, 9) << " at 9, 9" << endl
       << m10.get(5, 5) << " at 5, 5" << endl << endl;
  
  /*
  // Error in 'get' operator: Invalid index
  cout << m10.get(10, 10) << " at 10, 10" << endl;
  */

  m10.transpose().print();
  m9.transpose().print();

  Matrix test(
    {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    }
  );

  test.print();
  test.transpose().print();

  // operators test

  Matrix summ = Matrix(5, 1) + Matrix(5, 2);
  summ.print();
  summ -= Matrix(5, 4);
  summ.print();

  // проверка умножения

  Matrix mult1({
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  });
  
  Matrix mult2({
    {6, 1, 8},
    {0, 4, 2},
    {6, 1, 8},
  });

  mult1.print();
  cout << "  *\n" << endl;
  mult2.print();

  cout << "  =\n" << endl;
  mult1 *= mult2;
  mult1.print();

  Matrix mult3(6, 6);
  mult3.print();
  cout << "* 6 =\n" << endl;
  
  mult3 *= 6;
  mult3.print();

  Matrix det_test({
    {2, 4, 3},
    {5, 7, 8},
    {6, 9, 1},
  });

  cout << det_test.determinant() << endl << endl;

  det_test.minor_matrix().print();
  det_test.algebraic_additions().print();

  Matrix aaa({
    {1, 2},
    {3, 4}
  });
  aaa.print();

  aaa.inverse().print();

  Matrix a100({
    {1,  18, 4,  6,  9 },
    {11, 17, 13, 14, 8 },
    {25, 2,  19, 15, 21},
    {10, 5,  12, 3,  7 },
    {24, 20, 22, 16, 23}
  });
  a100.print();

  cout << a100.determinant() << endl << endl;
  a100.inverse().print();

  Matrix mult_a({
    {13, 26},
    {39, 13}
  });

  Matrix mult_b({
    {7, 4},
    {2, 3}
  });

  (mult_a / mult_b).print();
  // для проверки:
  // https://ru.wikihow.com/делить-матрицы
}