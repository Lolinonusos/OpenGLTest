#include "positionComponent.h"

PositionComponent::PositionComponent() {

	matrix = glm::mat4(1.0f);
	matrix = glm::translate(matrix, glm::vec3(0.0f));
	matrix = glm::rotate(matrix, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	matrix = glm::scale(matrix, glm::vec3(1.0f));

	updateWorldVectors();
	updateLocalVectors();
}

void PositionComponent::translateLocal(Direction direction) {
	
	// X
	if (direction == RIGHT) {
		//position = glm::translate(position, right * moveSpeed);
		position += right;
		//matrix = glm::translate(matrix, position);
	}
	if (direction == LEFT) {
		//position = glm::translate(position, -right * moveSpeed);
		position -= right;
		//matrix = glm::translate(matrix, position);
	}
	// Y
	if (direction == UP) {
		//position = glm::translate(position, up * moveSpeed);
		position += up;
		//matrix = glm::translate(matrix, position);
	}
	if (direction == DOWN) {
		//position = glm::translate(position, -up * moveSpeed);
		position -= up;
		//matrix = glm::translate(matrix, position);
	}
	// Z
	if (direction == FORWARD) {
		//position = glm::translate(position, front * moveSpeed);
		position += front;
		//matrix = glm::translate(matrix, position);
	}
	if (direction == BACKWARD) {
		//position = glm::translate(position, -front * moveSpeed);
		position -= front;
		//matrix = glm::translate(matrix, position);
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
	}
	setPositionMatrix(position);
}

void PositionComponent::translate(float inX, float inY, float inZ, float deltaTime) {
	position += glm::vec3(inX, inY, inZ) * deltaTime;
	setPositionMatrix(position);
}

void PositionComponent::setPosition(glm::vec3 offset) {
	position += offset;
	setPositionMatrix(position);
}

void PositionComponent::setPosition(float x, float y, float z) {
	position += glm::vec3(x, y ,z);
	setPositionMatrix(position);
}

void PositionComponent::setRotation(float angle, glm::vec3)
{
}
