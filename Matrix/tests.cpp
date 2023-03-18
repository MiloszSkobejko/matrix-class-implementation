#include "tests.hpp"

// Created by Miłosz Skobejko on 16/03/2023
// Using Atom Text Editor
// Moved to Xcode editor on 18/03/2023

// ...Inicjalizacja konstruktora za pomocą listy
void test_initializer_list_constructor()
{
  std::cout << "Running initializer list constructor tests...\n";
  unsigned tests = 10;

  // Example 1: 2x2 matrix of integers
  Matrix<int> m1({{1, 2}, {3, 4}});
  assert(m1.getRows() == 2);
  assert(m1.getCols() == 2);
  assert(m1.element(0, 0) == 1);
  assert(m1.element(0, 1) == 2);
  assert(m1.element(1, 0) == 3);
  assert(m1.element(1, 1) == 4);


  //Example 2: 1x3 matrix of doubles
  Matrix<double> m2({1.1, 2.1, 3.8});
  assert(m2.getRows() == 1);
  assert(m2.getCols() == 3);
  assert(m2.element(0, 0) == 1.1);
  assert(m2.element(0, 1) == 2.1);
  assert(m2.element(0, 2) == 3.8);


  // Example 3: 1x3 matrix of strings
  Matrix<std::string> m3({"foo", "bar", "baz"});
  assert(m3.getRows() == 1);
  assert(m3.getCols() == 3);
  assert(m3.element(0, 0) == "foo");
  assert(m3.element(0, 1) == "bar");
  assert(m3.element(0, 2) == "baz");


  // Example 4: 3x3 matrix of booleans
  Matrix<bool> m4({{true, false, true}, {false, true, false}, {true, false, true}});
  assert(m4.getRows() == 3);
  assert(m4.getCols() == 3);
  // Ze względu na specyfikację std::vector, macierze<bool> nie są w stanie zwrócić referencji do obiektu.
  // Do zmiany pozniej
  // assert(m4.element(0, 0) == true);
  // assert(m4.element(0, 1) == false);
  // assert(m4.element(0, 2) == true);
  // assert(m4.element(1, 0) == false);
  // assert(m4.element(1, 1) == true);
  // assert(m4.element(1, 2) == false);
  // assert(m4.element(2, 0) == true);
  // assert(m4.element(2, 1) == false);
  // assert(m4.element(2, 2) == true);

  // Example 5: 1x1 matrix of characters
  Matrix<char> m5 = {'a'};
  assert(m5.getRows() == 1);
  assert(m5.getCols() == 1);
  assert(m5.element(0, 0) == 'a');



  // Example 6: square matrix
  Matrix<int> m6{{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}};
  assert(m6.getRows() == 3 && m6.getCols() == 3);


  // Example 7: rectangular matrix
  Matrix<int> m7{{1, 2},
                 {3, 4},
                 {5, 6}};
  assert(m7.getRows() == 3 && m7.getCols() == 2);


  // Example 8: empty matrix
  Matrix<double> m8;
  assert(m8.getRows() == 0 && m8.getCols() == 0);


  // Example 9: matrix with single element
  Matrix<float> m9{3.14};
  assert(m9.getRows() == 1 && m9.getCols() == 1 && m9.element(0, 0) == 3.14f);


  // Example 10: matrix with a row of zeros
  Matrix<int> m10{{0, 0, 0, 0}};
  assert(m10.getRows() == 1 && m10.getCols() == 4);


  std::cout << "Initializer list constructor tests completed! passed: [" << tests << "/" << tests << "]" << std::endl;
}









// ...Inicjalizacja konstruktora za pomocą rozmiaru i wartości domyślnej
void test_initialize_size_constructor()
{
  std::cout << "Running initialize by size constructor tests...\n";
  unsigned tests = 4;

  // Example 1: 2x2 matrix of integers
  // Given float val to check if conversion happens
  Matrix<int> m1(2,2, 10.1);
  assert(m1.getRows() == 2);
  assert(m1.getCols() == 2);

  for (unsigned i = 0; i < m1.getRows(); i++)
    for (unsigned j = 0; j < m1.getCols(); j++)
      assert(m1.element(i, j) == 10);



  // Example 2: 10x8 matrix of floats
  Matrix<float> m2(10, 8, 0.12f);
  assert(m2.getRows() == 10);
  assert(m2.getCols() == 8);

  for (unsigned i = 0; i < m2.getRows(); i++)
    for (unsigned j = 0; j < m2.getCols(); j++)
      assert(m2.element(i, j) == 0.12f);



  // Example 3: matrix with 1 element - value
  Matrix<double> m3(0,0, 20.19);
  assert(m3.getRows() == 0);
  assert(m3.getCols() == 0);
  //Line below throws an error as expected
  //assert(m3.element(0,0) == 20.19);



  // Example 4: identity matrix constructor
  Matrix<unsigned> identity(4);
  assert(identity.getRows() == 4);
  assert(identity.getCols() == 4);
  assert(identity.element(0, 0) == 1);
  assert(identity.element(0, 1) == 0);
  assert(identity.element(0, 2) == 0);
  assert(identity.element(0, 3) == 0);
  assert(identity.element(1, 0) == 0);
  assert(identity.element(1, 1) == 1);
  assert(identity.element(1, 2) == 0);
  assert(identity.element(1, 3) == 0);
  assert(identity.element(2, 0) == 0);
  assert(identity.element(2, 1) == 0);
  assert(identity.element(2, 2) == 1);
  assert(identity.element(2, 3) == 0);
  assert(identity.element(3, 0) == 0);
  assert(identity.element(3, 1) == 0);
  assert(identity.element(3, 2) == 0);
  assert(identity.element(3, 3) == 1);


  std::cout << "Initializer by size constructor tests completed! passed: [" << tests << "/" << tests << "]" << std::endl;
}








// ...Sprawdzenie konstruktora kopiującego
void test_copy_constructor()
{
    std::cout << "Running copy constructor tests...\n";
    unsigned tests = 8;

    // Example 1
    Matrix<int> m1({{1, 2}, {3, 4}});
    Matrix<int> m2(m1);
    assert(m2 == m1);
    assert(&m2 != &m1);

    // Example 2
    Matrix<double> m3({{0.5, 1.5}, {2.5, 3.5}});
    Matrix<double> m4(m3);
    assert(m4 == m3);
    assert(&m4 != &m3);

    // Example 3
    Matrix<std::string> m5({"hello", "world"});
    Matrix<std::string> m6(m5);
    assert(m6 == m5);
    assert(&m6 != &m5);

    // Example 4
    Matrix<int> m7(3, 4, 1);
    Matrix<int> m8(m7);
    assert(m8 == m7);
    assert(&m8 != &m7);

    // Example 5
    Matrix<double> m9(2, 2, 2.0);
    Matrix<double> m10(m9);
    assert(m10 == m9);
    assert(&m10 != &m9);

    // Example 6
    Matrix<std::string> m11(1, 1, "test");
    Matrix<std::string> m12(m11);
    assert(m12 == m11);
    assert(&m12 != &m11);

    // Example 7
    Matrix<int> m13(5, 5, 0);
    Matrix<int> m14(m13);
    m14.element(3, 3) = 1;
    assert(m13 != m14);
    assert(&m13 != &m14);

    // Example 8
    Matrix<double> m15({{1.0, 2.0}, {3.0, 4.0}});
    Matrix<double> m16(m15);
    m16.element(0, 0) = 10.0;
    assert(m15 != m16);
    assert(&m15 != &m16);

    std::cout << "copy constructor tests completed! passed: [" << tests << "/" << tests << "]" << std::endl;
}








// ...Sprawdzenie operatora przypisania
void test_assigment_operator()
{
  std::cout << "Running assigment operator tests...\n";
  unsigned tests = 5;

  // Example 1 :
  Matrix<int> m1(2, 2, 1);
  Matrix<int> m2(3, 3, 2);
  m1 = m2;
  assert(m1.getRows() == 3 && m1.getCols() == 3);


  // Example 2 :
  Matrix<float> m3(3, 3, 1.5);
  m3 = m3;
  assert(m3.element(2, 2) == 1.5);


  // Example 3 :
  Matrix<double> m4(4, 4, 1.0);
  Matrix<double> m5(4, 4, 2.0);
  m4 = m5;
  assert(m4 == m5);
  assert(&m4 != &m5);


  // Example 4 :
  const Matrix<double> m8(4, 4, 1.0);
  Matrix<double> m9(2, 2, 2.0);
  m9 = m8;
  assert(m8.getRows() == m9.getRows() && m8.getCols() == m9.getCols());


  // Example 5 :
  Matrix<double> m10;
  Matrix<double> m11(4, 4, 1.0);
  m11 = m10;
  assert(m11.getRows() == 0 && m11.getCols() == 0);

  std::cout << "assigment operator tests completed! passed: [" << tests << "/" << tests << "]" << std::endl;

}





// ...Sprawdzenie operatora dodawania
void test_adding_operation()
{
    std::cout << "Running addition tests...\n";
    unsigned tests = 5;

    // Example: 1
    Matrix<double> m1({{1.0, 2.0},
                       {3.0, 4.0}});
    Matrix<double> m2({{5.0, 6.0},
                       {7.0, 8.0}});
    Matrix<double> m3 = m1 + m2;
    assert(m3.element(0, 0) == 6.0 && m3.element(0, 1) == 8.0 &&
           m3.element(1, 0) == 10.0 && m3.element(1, 1) == 12.0);

    // Example: 2
    Matrix<int> m4({{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}});
    Matrix<int> m5({{10, 11, 12},
                    {13, 14, 15},
                    {16, 17, 18}});
    Matrix<int> m6 = m4 + m5;
    assert(m6.element(0, 0) == 11 && m6.element(0, 1) == 13 && m6.element(0, 2) == 15 &&
           m6.element(1, 0) == 17 && m6.element(1, 1) == 19 && m6.element(1, 2) == 21 &&
           m6.element(2, 0) == 23 && m6.element(2, 1) == 25 && m6.element(2, 2) == 27);

    // Example: 3
    Matrix<float> m7({{1.0f, 2.0f},
                      {3.0f, 4.0f}});
    Matrix<float> m8({{-1.0f, -2.0f},
                      {-3.0f, -4.0f}});
    Matrix<float> m9 = m7 + m8;
    assert(m9.element(0, 0) == 0.0f && m9.element(0, 1) == 0.0f &&
           m9.element(1, 0) == 0.0f && m9.element(1, 1) == 0.0f);


    // Example: 4
    Matrix<int> m10({{1, 2},
                     {3, 4},
                     {5, 6}});

    Matrix<int> m11({{1, 2},
                     {3, 4}});

    try
    {
      Matrix<int> m12 = m10 + m11;
    }
    catch (const std::invalid_argument& e)
    {
      assert(std::string(e.what()) == "Matrix addition requires matrices of same dimensions.");
    }

    // Example: 5
    Matrix<int> m13({{1, 2, 3}});
    Matrix<int> m14(3, 1, 1);

    m14.element(1,0) = 2;
    m14.element(2,0) = 3;

    try
    {
      Matrix<int> m15 = m13 + m14;
    }
    catch (const std::invalid_argument& e)
    {
      assert(std::string(e.what()) == "Matrix addition requires matrices of same dimensions.");
    }

    std::cout << "assigment addition tests completed! passed: [" << tests << "/" << tests << "]" << std::endl;
}








// ...Sprawdzenie operatora odejmowania
void test_subtraction()
{
    std::cout << "Running subtraction tests...\n";
    unsigned tests = 5;
    
    Matrix<int> m1({{1, 2}, {3, 4}});
    Matrix<int> m2({{5, 6}, {7, 8}});
    Matrix<int> m3({{-4, -4}, {-4, -4}});
    Matrix<int> m4({{0, 0}, {0, 0}});
    Matrix<int> m5({{1, -2}, {-3, 4}});
    Matrix<int> m6({{0, 2}, {3,3}});
    Matrix<int> m7({{0, 4} ,{6, 0}});

    // Test basic subtraction
    assert((m1 - m2) == m3);

    // Test subtraction with identity matrix
    assert((m1 - Matrix<int>(2)) == m6);

    // Test subtraction with itself
    assert((m1 - m1) == m4);

    // Test subtraction with matrix of different size
    try {
        Matrix<int> m6(3, 3, 1);
        m1 - m6; // should throw exception
        assert(false); // should not get here
    } catch (const std::exception& e) {
        assert(std::string(e.what()) == "Matrix subtraction requires matrices of same dimensions.");
    }

    // Test subtraction with negative numbers
    assert((m1 - m5) == m7);
    
    std::cout << "assigment subtraction tests completed! passed: [" << tests << "/" << tests << "]" << std::endl;
}


#include "tests.hpp"
