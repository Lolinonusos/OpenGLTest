#ifndef EDITORCAM_H
#define EDITORCAM_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "positionComponent.h"

class EditorCam : public PositionComponent {
public:
	glm::mat4 position = glm::mat4(1.0f);

	float yaw{ 0 };
	float pitch{ 0 };

	EditorCam();

	void lookAt();

	void move();


};

#endif