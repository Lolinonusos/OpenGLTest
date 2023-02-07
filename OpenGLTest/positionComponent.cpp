#include "positionComponent.h"

PositionComponent::PositionComponent()
{
}

void PositionComponent::translateLocal(Direction direction) {
	
	// X
	if (direction == RIGHT) {
		position = glm::translate(position, right * moveSpeed);

	}
	if (direction == LEFT) {
		position = glm::translate(position, -right * moveSpeed);

	}
	// Y
	if (direction == UP) {
		position = glm::translate(position, up * moveSpeed);

	}
	if (direction == DOWN) {
		position = glm::translate(position, -up * moveSpeed);

	}
	// Z
	if (direction == FORWARD) {
		position = glm::translate(position, front * moveSpeed);
	}
	if (direction == BACKWARD) {
		position = glm::translate(position, -front * moveSpeed);
	}
}

void PositionComponent::translateLocal(glm::vec3 offset) {
	position = glm::translate(position, offset);
}

void PositionComponent::translate(glm::vec3 offset) {
	position = glm::translate(position, offset);
}
