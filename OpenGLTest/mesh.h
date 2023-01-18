#ifndef MESH_H
#define MESH_H

//#include <vector>

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "texture.h"

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	VAO vao;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void draw(Shader& shader);
private:
	void setupMesh();
};

#endif