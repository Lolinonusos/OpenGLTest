#pragma once

#include <vector>
#include "blaze/Blaze.h"

class Matrise {
	//std::vector<std::vector <float>> vectorVector[2];
	//std::vector<float> matSize;

	// Koordinatene til punktene er:
	// 1.0f, 2.0f
	// 2.0f, 1.0f
	// 3.0f, 2.5f
	// 4.0f, 4.5f
	// 5.0f, 3.0f
	// 6.0f, 4.0f
	// 7.0f, 5.0f
	// 8.0f, 6.5f

	// y = A * x + e
	// B = AT * A
	// C = AT * y


	blaze::DynamicMatrix<float, blaze::columnMajor> A {
		{1.0f, 1.0f},
		{2.0f, 1.0f},
		{3.0f, 1.0f},
		{4.0f, 1.0f},
		{5.0f, 1.0f},
		{6.0f, 1.0f},
		{7.0f, 1.0f},
		{8.0f, 1.0f} 
	};

	// Inverted of A
	blaze::DynamicMatrix<float, blaze::rowMajor> AT = blaze::inv(A);


	blaze::DynamicMatrix<float, blaze::columnMajor> y{
		{2.0f},
		{1.0f},
		{2.5f},
		{4.5f},
		{3.0f},
		{4.0f},
		{5.0f},
		{6.5f}
	};

	void leastSquaresMethod() {

	}

	void matMultiply(Matrise) {

	}
};