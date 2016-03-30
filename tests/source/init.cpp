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

				REQUIRE(Matrix.get_num_rows() == rows);
				REQUIRE(Matrix.get_num_cols() == columns);
			}
		}
	}
}
SCENARIO("Matrix +", "[addition]") {
	Matrix A = Matrix(2, 2);
	A.get_from_file("A2x2.txt");
	Matrix B = Matrix(2, 2);
	B.get_from_file("B2x2.txt");
	Matrix expected = Matrix(2, 2);
	expected.get_from_file("A+B2x2.txt");
	Matrix result = A + B;
	REQUIRE(result == expected);
}

SCENARIO("Matrix *", "[addition]") {
	Matrix A = Matrix(2, 2);
	A.get_from_file("A2x2.txt");
	Matrix B = Matrix(2, 2);
	B.get_from_file("B2x2.txt");
Matrix expected = Matrix(2, 2);
	expected.get_from_file("A*B2x2.txt");
	Matrix result = A * B;
	REQUIRE(result == expected);
}

SCENARIO("Matrix: operator ==", "[equal]") {
	Matrix A, B;
	A.get_from_file("A2x2.txt");
	B.get_from_file("A2x2.txt");
	bool f = (A == B);
	REQUIRE(f);
}
