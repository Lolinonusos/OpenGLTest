#pragma once

#include "visObject.h"

class OctahedronBall : visObject {
public:
	OctahedronBall();
	~OctahedronBall();
	void init(int matrixUniform) override;
	void draw();
private:
	void makeTriangle();
	void subdivide();

};

