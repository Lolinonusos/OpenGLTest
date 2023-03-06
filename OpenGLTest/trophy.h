#pragma once

#include "octahedronBall.h"
#include "cube.h"

class Trophy : public Cube {
public:

	void checkCollision(VisObject* other) override {
		float dist = glm::distance(this->position, other->position);
		if (dist < this->radius + other->radius) {
			//std::cout << "Trophy collision" << std::endl;
			this->setRenderStyle(HIDDEN);
		}
		else {
			setPosition(glm::vec3(1.0f, 0.0f, 0.0f));
			this->setRenderStyle(SOLID);

		}
	}
};

