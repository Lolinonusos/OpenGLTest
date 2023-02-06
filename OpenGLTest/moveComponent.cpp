#include "moveComponent.h"

void moveComponent::localMove(Direction direction, float deltaTime) {
	float velocity = moveSpeed * deltaTime;
	// X
	if (direction == RIGHT) {
		position += right * velocity;
	}
	if (direction == LEFT) {
		position -= right * velocity;
	}
	// Y
	if (direction == UP) {
		position += up * velocity;
	}
	if (direction == DOWN) {
		position -= up * velocity;
	}
	// Z
	if (direction == FORWARD) {
		position += front * velocity;
	}
	if (direction == BACKWARD) {
		position -= front * velocity;
	}
}

void moveComponent::worldMove(Direction direction, float deltaTime) {
	float velocity = moveSpeed * deltaTime;
	// X
	if (direction == FORWARD) {
		position += worldX * velocity;
	}
	if (direction == BACKWARD) {
		position -= worldX * velocity;
	}
	// Y
	if (direction == RIGHT) {
		position += worldY * velocity;
	}
	if (direction == LEFT) {
		position -= worldY * velocity;
	}
	// Z
	if (direction == UP) {
		position += worldZ * velocity;
	}
	if (direction == DOWN) {
		position -= worldZ * velocity;
	}
}
