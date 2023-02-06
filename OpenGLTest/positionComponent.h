#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class PositionComponent { 
public:
	glm::vec3 position;
	glm::vec3 right;	// local x
	glm::vec3 up;		// local y 
	glm::vec3 front;	// local z
	const glm::vec3 worldX;
	const glm::vec3 worldY;
	const glm::vec3 worldZ;

	PositionComponent();

protected:
	
	//glm::mat4 matrix;
	//glm::mat4 position;
	//glm::mat4 rotation;
	//glm::mat4 scale;


};

