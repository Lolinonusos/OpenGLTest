#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <vector>

#include "shader.h"


class Vertex {
public:
	glm::vec3 position; // XYZ coordinates
	glm::vec3 normal; // RGB values
	glm::vec2 texCoord; // UV coordinates
};

class Texture {
public:
	unsigned int ID;
	std::string type;
	std::string path;
};

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void draw(Shader& shader);
private:
	unsigned int VAO, VBO, EBO;

	void setupMesh();
};

#endif