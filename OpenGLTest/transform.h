#pragma once

#include <glm/glm.hpp>

class Transform{
	glm::mat4 matrix = glm::mat4(1.0f);
	glm::vec3 vector = glm::vec3(0.0f, 0.0f, 0.0f);
};

