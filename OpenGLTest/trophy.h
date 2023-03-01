#pragma once

#include "octahedronBall.h"

class trophy : public OctahedronBall {
public:

	void checkCollision(VisObject* other) override {
		float dist = glm::distance(this->position, other->position);
		if (dist < this->radius + other->radius) {
			other->setRenderStyle(2);
		}
	}
};

