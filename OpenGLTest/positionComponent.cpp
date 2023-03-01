#include "positionComponent.h"

PositionComponent::PositionComponent() {
}

void PositionComponent::translateLocal(Direction direction) {
	
	// X
	if (direction == RIGHT) {
		//position = glm::translate(position, right * moveSpeed);
		position += right;
		matrix = glm::translate(matrix, position);
	}
	if (direction == LEFT) {
		//position = glm::translate(position, -right * moveSpeed);
		position -= right;
		matrix = glm::translate(matrix, position);
	}
	// Y
	if (direction == UP) {
		//position = glm::translate(position, up * moveSpeed);
		position += up;
		matrix = glm::translate(matrix, position);
	}
	if (direction == DOWN) {
		//position = glm::translate(position, -up * moveSpeed);
		position -= up;
		matrix = glm::translate(matrix, position);
	}
	// Z
	if (direction == FORWARD) {
		//position = glm::translate(position, front * moveSpeed);
		position += front;
		matrix = glm::translate(matrix, position);
	}
	if (direction == BACKWARD) {
		//position = glm::translate(position, -front * moveSpeed);
		position -= front;
		matrix = glm::translate(matrix, position);
	}
}

void PositionComponent::translateLocal(glm::vec3 offset, float deltaTime) {
	//position = glm::translate(position, offset);
}

void PositionComponent::translate(Direction direction, float deltaTime) {
	// X
	if (direction == RIGHT) {
		//position = glm::translate(position, right * moveSpeed);
		position += worldRight * deltaTime;
		//matrix = glm::translate(matrix, position);
	}
	if (direction == LEFT) {
		//position = glm::translate(position, -right * moveSpeed);
		position -= worldRight * deltaTime;
		//matrix = glm::translate(matrix, position);
	}
	// Y
	if (direction == UP) {
		//position = glm::translate(position, up * moveSpeed);
		position -= worldUp * deltaTime;
		//matrix = glm::translate(matrix, position);
	}
	if (direction == DOWN) {
		//position = glm::translate(position, -up * moveSpeed);
		position += worldUp * deltaTime;
		//matrix = glm::translate(matrix, position);
	}
	// Z
	if (direction == FORWARD) {
		//position = glm::translate(position, front * moveSpeed);
		position += worldFront * deltaTime;
		//matrix = glm::translate(matrix, position);
	}
	if (direction == BACKWARD) {
		//position = glm::translate(position, -front * moveSpeed);
		position -= worldFront * deltaTime;
		//matrix = glm::translate(matrix, position);
	}
}

void PositionComponent::setPosition(glm::vec3 offset) {
	position = offset;
}