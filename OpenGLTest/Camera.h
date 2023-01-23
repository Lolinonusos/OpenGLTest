#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// This camera is from learnOpenGL.com 

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
public:
	// Camera position and movement
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up; // y is up direction
	glm::vec3 right;//
	glm::vec3 worldUp;
	// Euler angles; camera rotation
	float yaw;
	float pitch;
	// Camera options
	float movementSpeed;
	float mouseSensitivity;
	float zoom;

	// Constructor with vectors
	Camera(glm::vec3 inPosition = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 inUp = glm::vec3(0.0f, 1.0f, 0.0f), float inYaw = YAW, float inPitch = PITCH) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM) {
		position = inPosition;
		worldUp = inUp;
		yaw = inYaw;
		pitch = inPitch;
		updateCameraVectors();
	}

	glm::mat4 getViewMatrix() {
		return glm::lookAt(position, position + front, up);
	}

	void processKeyboard(Camera_Movement direction, float deltaTime) {
		float velocity = movementSpeed * deltaTime;
		if (direction == FORWARD) {
			position += front * velocity;
		}
		if (direction == BACKWARD) {
			position -= front * velocity;
		}
		if (direction == RIGHT) {
			position += right * velocity;
		}
		if (direction == LEFT) {
			position -= right * velocity;
		}
	}

	void processMouseMovement(float xOffset, float yOffset) {

		xOffset *= mouseSensitivity;
		yOffset *= mouseSensitivity;

		yaw += xOffset;
		pitch += yOffset;

		if (pitch > 89.0f) {
			pitch = 89.0;
		}
		if (pitch < -89.0f) {
			pitch = -89.0;
		}

		updateCameraVectors();
	}

	// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yOffset)
	{
		zoom -= (float)yOffset;
		if (zoom < 1.0f)
			zoom = 1.0f;
		if (zoom > 45.0f)
			zoom = 45.0f;
	}

private:
	void updateCameraVectors() {
		glm::vec3 newFront;

		newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		newFront.y = sin(glm::radians(pitch));
		newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

		front = glm::normalize(newFront);

		right = glm::normalize(glm::cross(front, worldUp));
		up = glm::normalize(glm::cross(right, front));
	}
};

#endif