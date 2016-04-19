#include <iostream>
#include "matrix.h"
#ifndef MATR_CPP
#define MATR_CPP

template <typename T>
void Matrix::swap(Matrix & m1) {
	std::swap(m1._matrix, _matrix);
	std::swap(m1.columns, columns);
	std::swap(m1.rows, rows);
}

template <typename T>
Matrix<T>::Matrix() : rows(0), columns(0), num(0) //конструктор инициализации 
{
	_matrix = new T*[0];
	_matrix[0] = new T[0];
}

template <typename T>
Matrix<T>::Matrix(int _rows, int _columns) :rows(_rows), columns(_columns) //конструктор с параметрами 
{
	_matrix = new T*[rows];

	for (int i = 0; i < rows; i++)
		_matrix[i] = new T[columns];
	for (int i = 0; i < rows; i++) { //  обнуление массива
		for (int j = 0; j < columns; j++)
			_matrix[i][j] = 0;
	}
}
template <typename T>
Matrix<T>::Matrix(const Matrix<T> & matrix) :rows(matrix.rows), columns(matrix.columns)//конструктор копирования 
{
	_matrix = new T*[rows];
	for (int i = 0; i < rows; ++i) {
		_matrix[i] = new T[columns];
		for (int j = 0; j < columns; ++j)
			_matrix[i][j] = matrix._matrix[i][j];
	}
}

template <typename T>
Matrix<T>::~Matrix() // деструктор
{
	for (int i = 0; i < rows; i++)
		delete[] _matrix[i];

	delete[] _matrix;
}

template <typename T>
bool Matrix<T>::operator == (const Matrix<T> &matr) {
	if (this->rows != matr.rows || this->columns != matr.columns) {
		throw "Wrong sizes of matrixes\n";
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (_matrix[i][j] != matr._matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

template <typename T>
T* Matrix<T>::operator [] (int index) {
if (index < 0 || index > this->m_rows) {
		throw indexException();
	}
	if (rows == 0 || _matrix == nullptr) {
		throw emptyException();
	}

	return this->_matrix[index];
}

template <typename T>
void Matrix<T>::Get_Matrix(string s) // получаем матрицу из файла
{
try{
	ifstream fin(s); // сконструируем объект класса ifstream для ввода из файла
	if (fin.is_open()) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				fin >> _matrix[i][j]; // выводим из файла данные
		fin.close(); // закрываем файл
		return true;
	}else {
			throw initException();
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
		return false;
	}
	return false;
	
}

template <typename T>
void Matrix<T>::Cout_Matrix() // вывод матрицы
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << " " << _matrix[i][j];
		};
		cout << "\n";
	};
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& matrix1) {
	if (this->rows != matrix1.rows || this->columns != matrix1.columns) {
		throw "Wrong sizes of matrixes\n";
	}
	if (this != &matrix1) {
		(Matrix(matrix1)).swap(*this);
	}
	return *this;
}
template <typename T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &firstMatrix) {
	if (this->rows != firstMatrix.rows || this->columns != firstMatrix.columns) {
	throw emptyException();
	}
	Matrix result(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			result[i][j] = firstMatrix._matrix[i][j] + this->_matrix[i][j];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T> &m) {
	if (this->rows != m.rows || this->columns != m.columns) {
		throw incompatibleException();
	}

	Matrix result(this->rows, m.columns);
	int a = 0;

	for (int row = 0; row < this->rows; row++) {
		for (int col = 0; col < m.columns; col++) {
			a = 0;
			for (int i = 0; i < this->columns; i++) {
				a = a + this->_matrix[row][i] * m._matrix[i][col];
			}
			result._matrix[row][col] = a;
		}

	}

	return result;
}

template <typename T>
T Matrix<T>::get_rows() // получаем кол-во строк
{
	return rows;
}

template <typename T>
T Matrix<T>::get_columns() // получаем кол-во столбцов 
{
	return columns;
}
template <typename T>
std::ostream & operator <<(std::ostream & os, const CMatrix<T> & x) {
	if (x.m_columns == 0 || x.m_rows == 0 || x.matrix == nullptr) {
		throw emptyException();
	}
	for (int i = 0; i < x.m_rows; ++i) {
		for (int j = 0; j < x.m_columns; ++j) {
			os.width(4);
			os << x.matrix[i][j];
		}
		os << std::endl;
	}

	return os;
}

template <typename T>
std::istream & operator >>(std::istream & input, CMatrix<T> & matrix) {
	for (int i = 0; i < matrix.m_rows; ++i) {
		for (int j = 0; j < matrix.m_columns; ++j) {
			try {
				if (!(input >> matrix.matrix[i][j])) {
					throw initException();
				}
			}
			catch (...) {
				throw initException();
			}
		}
	}

	return input;
}
#endif
