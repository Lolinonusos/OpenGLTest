#pragma once

#include "cube.h"
#include "Camera.h"

class changeScene : public Cube {
public:
	changeScene();
	~changeScene();

	void checkCollision(VisObject* other, Camera* camera) {
		float dist = glm::distance(this->position, other->position);
		if (dist < this->radius + other->radius) {
		//std::cout << "Working?" << std::endl;
			camera->setPosition(this->position);
		}
		else {
			camera->setPosition(glm::vec3(0.0f, 0.0f, 10.0f));
		}
	}

};