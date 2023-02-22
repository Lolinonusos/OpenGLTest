#pragma once

#include <fstream>
//#include <vector>

//#include "vertex.h"

inline void writeGraphLeastSquares(std::string fileName, float R, float G, float B, float min, float max, float resolution, float a, float b, float c) {
	int n{ 0 };

	for (float i = min; i <= max; i += resolution) {
		n += 3;
	}

	std::ofstream out;
	out.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (out.is_open()) {
		out << n << std::endl;
		float y{ 0 };
		for (float x = min; x <= max; x += resolution) {

			y = a * pow(x, 2) + b * x + c;
					// x			y			 z				  // r			  g			   b				// u			v
			out << "(" << x << ", " << y << ", " << 0 << ") " << "(" << R << ", " << G << ", " << B << ") " << "(" << 0 << ", " << 0 << ")" << std::endl;
		}
		out.close();
	}
	else {
		std::cout << "ERROR: Could not find file" << std::endl;
	}
}

inline void writeGraphInterpolation(std::string fileName, float R, float G, float B, float min, float max, float resolution, float a, float b, float c, float d) {
	int n{ 0 };

	for (float i = min; i <= max; i += resolution) {
		n += 3;
	}

	std::ofstream out;
	out.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (out.is_open()) {

		out << n << std::endl;

		float y{ 0 };
		for (float x = min; x <= max; x += resolution) {

			y = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
			out << "(" << x << ", " << y << ", " << 0 << ") " << "(" << R << ", " << G << ", " << B << ") " << "(" << 0 << ", " << 0 << ")" << std::endl;
		}
		out.close();
	}
	else {
		std::cout << "ERROR: Could not find file" << std::endl;
	}
}

inline void writeSurfaceInterp(std::string fileName, float min, float max, float resolution) {
	
	int n { 0 };
	for (float i = min; i < max; i += resolution) {
		n += 6;
	}

	std::ofstream out;
	out.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (out.is_open()) {

		out << n << std::endl;

		for (float x = min; x < max; x += resolution) {
			for (float y = min; y < max; y += resolution) {
				
			}
		}
		out.close();

	}
	else {
		std::cout << "ERROR: Could not find file" << std::endl;
	}
}

inline void writeSurface(std::string fileName, float xMin, float xMax, float yMin, float yMax, float resolution) {
	int n{ 0 };
	for (float i = xMin; i < xMax; i += resolution) {
		n += 6;
	}

	std::ofstream out;
	out.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (out.is_open()) {

		out << n << std::endl;

		for (float x = xMin; x < xMax; x += resolution) {
			for (float y = xMin; y < xMax; y += resolution) {

			}
		}
		out.close();
	}
	else {
		std::cout << "ERROR: Could not find file" << std::endl;
	}
}