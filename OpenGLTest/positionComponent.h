#pragma once

//#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class PositionComponent { 
public:
	// Keyboard
	enum Direction {
		// X
		LEFT,
		RIGHT,
		// Y
		UP,
		DOWN,
		// Z
		FORWARD,
		BACKWARD
	};

	glm::mat4 position = glm::mat4(1.0f);
	glm::vec3 right;	// local x
	glm::vec3 up;		// local y 
	glm::vec3 front;	// local z
	const glm::vec3 worldX;
	const glm::vec3 worldY;
	const glm::vec3 worldZ;

	// Should these be protected?
	glm::mat4 rotation = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);

	PositionComponent();


	void translateLocal(Direction direction);
	void translateLocal(glm::vec3 offset);
	void translate(glm::vec3 offset);
	float moveSpeed{};
	bool useLocal{ true };

protected:
	
	//glm::mat4 matrix;
	//glm::mat4 position;
	//glm::mat4 rotation;


};

