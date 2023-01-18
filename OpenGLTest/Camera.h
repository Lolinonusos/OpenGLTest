#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f; // Mouse sensitivity
const float ZOOM = 45.0f;


class Camera{
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up; // y is up direction
	glm::vec3 right;//
	glm::vec3 worldUp;

	float yaw;
	float pitch;

	float movementSpeed;
	float mouseSensitivity;
	float zoom;

	// Constructor with vectors
	Camera(glm::vec3 inPosition = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 inUp = glm::vec3(0.0f, 1.0f, 0.0f), float inYaw = YAW, float inPitch = PITCH) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM) {
		position = inPosition;
		worldUp = inUp;
		yaw = inYaw;
		pitch = inPitch;
	}
};

#endif