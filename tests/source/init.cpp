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

SCENARIO("Matrix: operator ==", "[equal]") {
	Matrix A = Matrix(2, 2);
	A.Get_Matrix("A2x2.txt");
	Matrix B = Matrix(2, 2);
	B.Get_Matrix("A2x2.txt");
	bool f = (A == B);
	REQUIRE(f);
}
SCENARIO("Matrix: operator []", "[addition]") {
	Matrix A = Matrix(2, 2);
	A.Get_Matrix("A2x2.txt");
	Matrix B = Matrix(1,2);
	B.Get_Matrix("A.txt");
	REQUIRE(A[2]==B[1]);
}
