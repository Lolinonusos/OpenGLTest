#ifndef CUBE_H
#define CUBE_H

#include "visObject.h"

class Cube : public VisObject {
public:
	Cube();
	~Cube();
	void init() override;
	void draw(Shader shader) override;
};

#endif