#pragma once

#include "visObject.h"

class OctahedronBall : visObject {
public:
	OctahedronBall(int n = 0);
	~OctahedronBall();
	void init(int matrixUniform) override;
	void draw();
private:
	int recursions;
	int indices;

	void octahedronUnitBall();
	void makeTriangle(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3);
	void subdivide(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, int n);

};

