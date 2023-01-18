#ifndef VBO_H
#define VBO_H

#include <glm/glm.hpp>
#include <glad/glad.h>

#include <vector>

class Vertex {
public:
	glm::vec3 position; // XYZ coordinates
	glm::vec3 normal; // RGB values
	glm::vec2 texCoord; // UV coordinates
};

class VBO {
public:
	unsigned int ID;
	VBO(std::vector<Vertex> &vertices);
	//VBO(std::vector<float> vertices, GLsizeiptr size); // Using vertex class


	void bind();
	void unbind();
	void remove();
};

#endif