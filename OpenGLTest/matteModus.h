#pragma once

#include <iostream>

#include <Eigen/Core>
#include <Eigen/Eigen>
//#include <vector>

class Matrise {
public:
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
	Matrise() {
		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> A{
			{1.0f, 1.0f},
			{2.0f, 1.0f},
			{3.0f, 1.0f},
			{4.0f, 1.0f},
			{5.0f, 1.0f},
			{6.0f, 1.0f},
			{7.0f, 1.0f},
			{8.0f, 1.0f}
		};

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> AT = A.transpose();

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> y{
			{2.0f},
			{1.0f},
			{2.5f},
			{4.5f},
			{3.0f},
			{4.0f},
			{5.0f},
			{6.5f}
		};

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> B = AT * A;
		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Binv = B.inverse();

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> c = AT * y;

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> solve = Binv * c;

		float a = solve(0, 0);
		float b = solve(1, 0);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;


	}



	void leastSquaresMethod() {
		for (int i = 0; i < 8; i++) {

		}


	}

	void matMultiply(Matrise) {

	}
};