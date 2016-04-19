#include <matrix.h>
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {

	GIVEN("The number of rows and columns") {

		auto rows = 3;
		auto columns = 3;

		WHEN("Create instansce of Matrix") {
			Matrix Matrix(rows, columns);
			THEN("The number of rows and columns must be preserved") {

				REQUIRE(Matrix.get_rows() == rows);
				REQUIRE(Matrix.get_columns() == columns);
			}
		}
	}
}  
SCENARIO("Matrix +", "[addition]") {
	Matrix A = Matrix(2, 2);
	A.Get_Matrix("A2x2.txt");
	Matrix B = Matrix(2, 2);
	B.Get_Matrix("B2x2.txt");
	Matrix expected = Matrix(2, 2);
	expected.Get_Matrix("A+B2x2.txt");
	Matrix result = A + B;
	REQUIRE(result == expected);
}

SCENARIO("Matrix *", "[addition]") {
	Matrix A = Matrix(2, 2);
	A.Get_Matrix("A2x2.txt");
	Matrix B = Matrix(2, 2);
	B.Get_Matrix("B2x2.txt");
Matrix expected = Matrix(2, 2);
	expected.Get_Matrix("A*B2x2.txt");
	Matrix result = A * B;
	REQUIRE(result == expected);
}

SCENARIO("Matrix operator [](int)", "[row]") 
{
	Matrix A(2,2);
	std::ifstream("A2x2.txt") >> A;
	int* row = A[1];
	REQUIRE(row[0]==2);
	REQUIRE(row[1]==1);
}
SCENARIO("Matrix operator ==", "[comparison]") 
{
		Matrix A = Matrix(2, 2);
	A.Get_Matrix("A2x2.txt");

	std::ifstream("A2x2.txt") >> A;

	REQUIRE(A==A);
}
 
 SCENARIO("MatrixException: init matrix", "[init]") {
	bool flag = false;
	CMatrix<int> A;
	try {
		A.readFromFile("11111");
	}
	catch (initException &e) {
		flag = true;
	}
	REQUIRE(flag);
}

SCENARIO("MatrixException: empty matrix", "[empty]") {
	bool flag = false;
	CMatrix<int> A;
	try {
		cout << A;
	}
	catch (emptyException &e) {
		flag = true;
	}
	REQUIRE(flag);
}

SCENARIO("MatrixException: index error", "[index]") {
	bool flag = false;
	CMatrix<int> A(2, 2);
	try {
		int* a = A[3];
	}
	catch (indexException &e) {
		flag = true;
	}
	REQUIRE(flag);
}

SCENARIO("MatrixException: incompatible matrixes", "[size]") {
	bool flag = false;
	CMatrix<int> A(2, 2), B(3, 3);
	try {
		A + B;
	}
	catch (incompatibleException &e) {
		flag = true;
	}
	REQUIRE(flag);
}

SCENARIO("Matrix: operator + for double", "[addition]") {
	CMatrix<double> A, B, expected;
	A.readFromFile("A2x2.txt");
	B.readFromFile("B2x2.txt");
	expected.readFromFile("A+B2x2.txt");

	CMatrix<double> result = A + B;
	REQUIRE(result == expected);
}
