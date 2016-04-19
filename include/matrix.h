#pragma once
#ifndef MATR_H
#define MATR_H
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "MatrixException.h"
using namespace std;

template <typename T>
class Matrix;
 
template <class T>
std::ostream & operator<<(std::ostream & output, const Matrix<T> &);

template <class T>
std::istream & operator>>(std::istream & input, Matrix<T> &);

template <typename T>
class Matrix {
public:
	Matrix() : rows(0), columns(0), _matrix(nullptr) {};	
	Matrix(int _rows, int _columns);
	Matrix(const Matrix &matrix);
	~Matrix();
	void Get_Matrix(string s);
	void Cout_Matrix();
	Matrix &operator=(const Matrix &matrix);
	Matrix operator +(const Matrix& firstMatrix);
	Matrix operator *(int num);    
	T* operator [](int i);
	int get_rows();
	int get_columns();
	friend std::ostream & operator<< <>(std::ostream & output, const Matrix & matrix);	
	friend std::istream & operator>> <>(std::istream & input, Matrix<T> & matrix);	
private:
	void swap(Matrix & m1);
	string s;
	int rows;
	int columns;
	T **_matrix;
};
#endif
