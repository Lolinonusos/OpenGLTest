#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "shader.h"

class Camera{
	glm::vec3 position{ glm::vec3(0.0f, 0.0f, 0.0f) };
	glm::vec3 target{ glm::vec3(0.0f, 0.0f, 0.0f) };
	glm::vec3 orientation{ glm::vec3(0.0f, 0.0f, -1.0f) };// 
	glm::vec3 up{ glm::vec3(0.0f, 1.0f, 0.0f) }; // y is up direction
	//glm::vec3 right{glm::normalize(glm::cross(up, ))}
};

#endif