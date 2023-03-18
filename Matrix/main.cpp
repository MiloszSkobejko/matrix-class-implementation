#include "matrix.hpp"
//#include "tests.h"
#include <vector>


int main()
{
//  test_initializer_list_constructor();
//  test_initialize_size_constructor();
//  test_copy_constructor();
//  test_assigment_operator();
//  test_adding_operation();
//  test_subtraction();

  Matrix<int> mat1 = {{1,2,3}, {4,5,6}, {7,8,9}};
  Matrix<bool> mat2 = {{false,true}, {false, false}};
  Matrix<float> mat3 = {1,2,3,4,5,6};

  mat3.print();
  // mat1 = mat1 + 2;
  // mat1.print();



  //std::cout << mat3.element(7) << std::endl;
  return 0;
}
