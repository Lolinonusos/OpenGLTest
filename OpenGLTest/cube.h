#ifndef CUBE_H
#define CUBE_H

#include "visObject.h"

class Cube : public VisObject {
public:
	Cube();
	~Cube();
	void init(int inMatrixUniform) override;
	void draw() override;
};

#endif