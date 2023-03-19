# Matrix Class Implementation
c++ implementation of templetised matrix class with basic mathematical operations, operator overloading and output stream handling. 
Everything builded up from scratch.



## Table of contest
* [Overviev](#Overviev)
* [Status](#Status)
* [Features description](#Features-description)
* [How to use](#how-to-use)
* [Code examples](#Code-examples)
* [Full documentation](#Full-documentation)
* [Tests](#tests)
* [Author](#author)



## Overview
This project was created while working on a different repository: ascii_graphics_engine. I wanted to add 3d projection into it, 
therefore I needed matrix structure, matrix operations etc... I decided to make my own class instead of choosing existing library, because
I found a excellent opportunity to practice my skills and also make usefull tool for me as well as other intrested programmers. I wanted to keep it 
simple, flexible, easy and intuitive to use.


## Status
Right now, repository is almost finished, current versions is: v.0.0. I am planning to add more tests and functions in near future



## Features description
This project will let you create any matrix of any size, uses std::vector to handle memory managment and contain following features:
  - creating matrix of any given type (uses templates) and size
  - creating identity matrixes
  - matrix to matrix addiction
  - matrix to matrix subtraction
  - matrix by matrix multiplication
  - comparing two matrixes of the same type
  - addiction, subctation, multiplication and division by variable. This works by performing given operation to every element of matrix. 
  Exapmle: matrix1 += 2; will add 2 to every element of matrix1 instance. Similarly matrix2 = matrix1 / 2; will divide every element;
  - transposing a matrix (returning a transposed matrix)
  - accesing every element of matrix
  - getting natrix to the power of integer
  - printing matrix to the console
  
  
  
  ## How to use
  
  _All of files in this project uses only c++ standard library, there is no need to install any of plugins, packages etc..._
  
  #### instalation
  copy matrix.hpp and matrix.cpp into your project source folder. Rest of files contains tests (_below_) and example program in main.cpp
  include "matrix.hpp" in files you want to use matrix class.
  >! DO NOT ! add matrix.cpp to the compiler/target path or makefile. matrix.cpp is included in matrix.hpp by default, because it uses templates and 
  compilers need to see all of declarations and definitions at once. If you get "method redefinition" error it is caused by this. Just treat it like
  matrix.cpp isn't there, and there is only header file.
  
  
  
  ## Code examples
  
  #### creating a matrix:
  ```c++
  // Initializer list constructor:
  Matrix<float> mat1 = {{1.0, -2.678, 3.80}, {4.11, 5.7, 6.12} ,{7.45, 8.6, 9.00}};
  Matrix<int> mat2 = {-4, 7, 10, 4, 10, 123};
  Matrix<std::string> mat3({{"hello", "world"}, {"matrix", "class"}});
  
  // By size constructor (all of elements will have initial value):
  Matrix<unsgined> mat4(_rows, _cols, _initial_value);
  
  // Create indentity (5x5) matrix:
  Matrix<int> identity(5);
  ```
  
  #### mathemtical operation examples:
  ```c++
  Matrix<float> mat1 = {{6, -7, 10}, {11, -9, 5}};
  Matrix<float> mat2 = {{5, 6}, {1, 1}, {3, -2}};
  Matrix<float> mat3 = {{53, 9}, {61, 47}};
  
  mat1 = mat2 * mat3;
  mat1 *= mat2;
  
  // If operation is not allowed it will throw a std::invalid_argument error
  // So you can't do: mat2 -= mat3;
  
  mat3 = mat1 + mat2;
  mat3 = mat3 / 2.0f;
  mat1 *= 5.0f;
  ```
  
  #### other methods:
  ```c++
  Matrix<int> mat1 = {{1, 2, 3}, {4,5,6}, {7,8,9}};
  
  int return = mat1.element(1,1); // getting element at (1,1) index, in this case 5
  mat1.element(0,1) = 10;         // modyfing element at (0,1) index, in this case replacing 2 with 10
  
  mat1 = mat1.traspose();         // returns a transposed matrix
  mat1.print();                   // prints a matrix to the output stream  
  ```
  
  
  
  ## Full documentation
  Description of all methods and options is written in the documentation.md file in this repository. Currently documentation is being created and
  will be added soon
  
  
  
  ## Tests
  In the repository I added tests functions for most of the features. They are contained in tests.hpp and tests.cpp files. Default code which is in main.cpp
  run these tests by default to see if everything works as intended in your programming enviroment. Any issues will be shown by assert fucntion. They are
  not necessary in the final code and can be easly removed.
  
  
  
  ## Author
  > + _Created by Miłosz Skobejko_
  > + _Published on github 9.03.2023_
  > + _currect version: v0.0_
  
  > Created in Atom text editor, later on moved to Xcode editor
  
  
  
  
