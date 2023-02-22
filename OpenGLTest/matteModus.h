#pragma once

#include <iostream>

#include <Eigen/Core>
#include <Eigen/Eigen>
//#include <vector>
#include "fileWriter.h"

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
	// solve = 
	Matrise() {


	}


	// Oppgave 4.4.4
	void FireFireFire() {
		// f(x) = a * x^2 + b *x + c 
		std::cout << "\nOppgave 4.4.4: " << std::endl;

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> A{
			{ 1.0f, 1.0f, 1.0f},
			{ 4.0f, 2.0f, 1.0f},
			{ 9.0f, 3.0f, 1.0f},
			{16.0f, 4.0f, 1.0f},
			{25.0f, 5.0f, 1.0f},
			{36.0f, 6.0f, 1.0f},
			{49.0f, 7.0f, 1.0f},
			{64.0f, 8.0f, 1.0f}
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

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> BM = AT * A;
		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Binv = BM.inverse();

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> C = AT * y;

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> solve = Binv * C;

		float a = solve(0, 0);
		float b = solve(1, 0);
		float c = solve(2, 0);

		std::cout << "a = " << a << std::endl; // a = 0.0505955
		std::cout << "b = " << b << std::endl; // b = 0.193451
		std::cout << "c = " << c << std::endl; // c = 1.40178

		float R = 0.0f;
		float G = 1.0f;
		float B = 0.5f;

		writeGraphLeastSquares("Oppg444.txt", R, G, B, -10.0f, 10.0f, 0.25f, a, b, c);
	}

	// Oppgave 4.6.10
	void FireSeksTi() {
		// f(x) = a * x^3 + b * x^2 + c * x + d 

		std::cout << "\nOppgave 4.6.10: " << std::endl;
		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> A{
			{  1.0f,  1.0f, 1.0f, 1.0f},
			{ 27.0f,  9.0f, 3.0f, 1.0f},
			{ 64.0f, 16.0f, 4.0f, 1.0f},
			{216.0f, 36.0f, 6.0f, 1.0f}
		};
		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Ainv = A.inverse();

		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> y{
			{4.0f},
			{1.5f},
			{5.0f},
			{2.0f}
		};
		
		Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> x = Ainv * y;

		float a = x(0, 0);
		float b = x(1, 0);
		float c = x(2, 0);
		float d = x(3, 0);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;

		float R = 0.0f;
		float G = 0.5f;
		float B = 1.0f;

		writeGraphInterpolation("Oppg4610.txt", R, G, B, -10.0f, 10.0f, 0.25f, a, b, c, d);
	}
};