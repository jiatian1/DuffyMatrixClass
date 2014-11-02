#include<iostream>
#include <vector>
#include <numeric>
//using namespace std

#include "ArrayStorage.h"
#include "Array.h"
#include "RegularArray.h"
#include "Vector.h"

#include "MatrixStorage.h"
#include "Matrix.h"
#include "RegularMatrix.h"
#include "NumMat.h"

#include "Utility.h"

int main(){

	Array<double, int> arr1(10); // start index = 1
	Array<double, int> arr2(10,-1); // start index = -1
	Array<double, int> arr3(10, 0, 3.14); // start index = 0, all values = 3.14

	print(arr1);
	print(arr2);
	print(arr3);

	Matrix<double, int> m1(10, 10);
	Matrix<double, int> m2(10, 10, -2, 3.14);

	print(m1);
	print(m2);

	return 0;
}