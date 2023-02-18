#pragma once


#include <Eigen/Core>
#include <Eigen/Eigen>
//#include <vector>

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
	// c = AT * y
	Matrise();
	Eigen::Matrix<float, 2, 8> A{ 
		{1.0f, 2.0f},
		{2.0f, 1.0f},
		{3.0f, 2.5f},
		{4.0f, 4.5f},
		{5.0f, 3.0f},
		{6.0f, 4.0f},
		{7.0f, 5.0f},
		{8.0f, 6.5f}
	};

	Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> AT = A.transpose();

	Eigen::Matrix<float, 8, 1> y;

	Eigen::Matrix<float, 2, 2> B;

	Eigen::Matrix<float, 2, 1> c;


	void leastSquaresMethod() {
		for (int i = 0; i < 8; i++) {

		}


	}

	void matMultiply(Matrise) {

	}
};