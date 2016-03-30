#ifndef Matrix_h
#define Matrix_h
#pragma once
#include <fstream> 
#include <string> 
using namespace std;
class Matrix {
public:
	Matrix();
	Matrix(int _rows, int _columns);
	Matrix(const Matrix &matrix);
	~Matrix();
	void Get_Matrix(string s);
	void Cout_Matrix();
	Matrix &operator=(const Matrix &matrix);
	Matrix operator +(const Matrix& firstMatrix);
	Matrix operator *(const Matrix &m);
	void get_num(string s);
	int* operator [](int i);
	int get_rows();
	int get_columns();
	bool operator== (const Matrix &r) const; 
private:
	void swap(Matrix & m1);
	string s{};
	int rows{};
	int num {};
	int columns{};
	int **_matrix{};
};
#endif
 
