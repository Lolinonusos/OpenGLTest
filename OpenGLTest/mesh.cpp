#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures) {

	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	vao.bind();
	
	VBO vbo(vertices);
	EBO ebo(indices);
 
	vao.linkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0); // XYZ / World coordinates
	vao.linkAttrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float))); // Normals
	//vao.linkAttrib(vbo, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float))); // RGB / Colour values
	vao.linkAttrib(vbo, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float))); // UV / Texture coordinates

	// Unbind everything
	vao.unbind();
	vbo.unbind();
	ebo.unbind();
}

void Mesh::draw(Shader& shader) {
	shader.use();


}

void Mesh::setupMesh() {

}
