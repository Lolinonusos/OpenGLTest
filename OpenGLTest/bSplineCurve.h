#pragma once

#include "visObject.h"

class bSplineCurve : public VisObject{
public:
	bSplineCurve();
	
	int grad; // int "d" i matten
	float t[10]; // Skjotvektoren
	glm::vec3 c[7];
	int findKnotInterval(float t);
	glm::vec3 deBour(float t);
};

