#ifndef CUBE_H
#define CUBE_H

#include "visObject.h"

class Cube : public VisObject {
public:

	Cube(Shader *inShader, std::string inName);
	~Cube();
	void init() override;
	void draw() override;
};

#endif