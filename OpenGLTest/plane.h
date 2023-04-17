#pragma once

#include "visObject.h"

class Plane : public VisObject {
public:
	Plane(Shader* inShader, std::string inName);
	~Plane();

	void init();
	void draw();
};

