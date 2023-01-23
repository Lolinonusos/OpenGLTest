#ifndef MESH_H
#define MESH_H

#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "vertex.h"

#include <string>
#include <vector>


//class Vertex {
//public:
//	glm::vec3 position; // XYZ coordinates
//	glm::vec3 normal; // RGB values
//	glm::vec2 texCoord; // UV coordinates
//};

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
	unsigned int VAO;
		
	// Constructor
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

	// Render mesh
	void draw(Shader& shader);
private:

	unsigned int VBO, EBO;

	void setupMesh();
};

#endif