#ifndef tests_hpp
#define tests_hpp

#include "matrix.hpp"
#include <cassert>
#include <string>


// Created by Miłosz Skobejko on 15/03/2023
// Using Atom Text Editor
// Copied to Xcode editor on 18/03/2023

// tests.h oraz tests.cpp zostały utworzone w celu sprawdzenia, czy elementy klasy matrix.h działają poprawnie
// Sprawdzane są konstruktory, operatory,


//Testy konstruktorów (lista inic.)
void test_initializer_list_constructor();

//Testy konstruktorów (rozmiar)
void test_initialize_size_constructor();

//Testy konstruktora kopiującego
void test_copy_constructor();

//Testy operatora przypisania
void test_assigment_operator();

//Testy operacji matetatyznych
void test_adding_operation();
void test_subtraction();


#endif /* tests_hpp */
