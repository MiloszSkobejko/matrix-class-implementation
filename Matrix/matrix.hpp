#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>

// Created by Miłosz Skobejko on 11/03/2023
// Using Atom Text Editor
// Moved to Xcode at 18/03/2023

// Klasa Matrix jest właną implementacją klasy macierzy, stworzoną od zera.
// Klasa wykorzystuje przeciążanie operatorów oraz jest klasą szablonową, co
// pozwala na szersze wykorzystanie jej możliwości.

#include <iostream>
#include <cmath>
#include <vector>
#include <initializer_list>

template <typename Type> class Matrix
{
    private:
            std::vector< std::vector<Type> > elements;
            unsigned int rows;
            unsigned int cols;

    public:

            /* KONSTRUKTORY */
            Matrix() : rows(0), cols(0) {}
            Matrix(std::initializer_list< std::initializer_list<Type> > matrix);
            Matrix(std::initializer_list<Type> matrix);
            Matrix(unsigned int _rows, unsigned int _cols, Type _init);
            Matrix(unsigned _size); //Creates Identity Matrix
            Matrix(const Matrix<Type> & original);

            /*  DESTRUKTOR  */
            virtual ~Matrix() {}


            /*  PRZECIĄŻONE OPERATORY DLA OPERACJI MATEMATYCZNYCH  */

            // Macierz operator Macierz
            Matrix<Type> & operator= (const Matrix<Type> & right);
            Matrix<Type>   operator+ (const Matrix<Type> & right);
            Matrix<Type> & operator+=(const Matrix<Type> & right);
            Matrix<Type>   operator- (const Matrix<Type> & right);
            Matrix<Type> & operator-=(const Matrix<Type> & right);
            Matrix<Type>   operator* (const Matrix<Type> & right);
            Matrix<Type> & operator*=(const Matrix<Type> & right);

            // Macierz operator skalar
            Matrix<Type> operator+(const Type & right);
            Matrix<Type> operator-(const Type & right);
            Matrix<Type> operator*(const Type & right);
            Matrix<Type> operator/(const Type & right);
            Matrix<Type> & operator+=(const Type & right);
            Matrix<Type> & operator-=(const Type & right);
            Matrix<Type> & operator*=(const Type & right);
            Matrix<Type> & operator/=(const Type & right);
            Type & operator()(const unsigned & i, const unsigned & j);


            // Definicje i deklaracje klas zaprzyjaźnionych; razem ponieważ
            // kompilator nie uznaje rozdzielenia poniższych funkcji na osobne
            // zapisanie definicji w innym pliku i wyrzuca błędy
            friend bool operator==(const Matrix<Type> & m1, const Matrix<Type> & m2)
            {
              if (m1.rows != m2.rows || m1.cols != m2.cols) return false;

              for (unsigned i = 0; i < m1.rows; i++)
               for (unsigned j = 0; j < m1.cols; j++)
                if (m1.elements[i][j] != m2.elements[i][j]) return false;

              return true;
            }

            friend bool operator!=(const Matrix<Type> & m1, const Matrix<Type> & m2) { return m1 == m2 ? false : true; }
            friend Matrix<Type> operator*(const Type & value, Matrix<Type> & right) { return right * value; }
            // friend Matrix<Type> operator+(const Type & value, Matrix<Type> & right) { return right + value; }
            // friend Matrix<Type> operator-(const Type & value, Matrix<Type> & right) { return right - value; }

    
            /*  METODDY */
            void print();
            unsigned getRows() const;
            unsigned getCols() const;
            Type & element(unsigned & i, unsigned & j);
            Type & element(const unsigned & i, const unsigned & j);
            Type & element(unsigned & i);
            Type & element(const unsigned & i);
            bool is_square() {return cols == rows;}
            Matrix<Type> transpose() const;
            Matrix<Type> power(unsigned n);

};

#include "matrix.cpp"

#endif /* matrix_hpp */
