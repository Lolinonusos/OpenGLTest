#ifndef VBO_H
#define VBO_H

#include <glm/glm.hpp>
#include <glad/glad.h>

#include <vector>



class VBO {
public:
	unsigned int ID;
	//VBO(std::vector<Vertex> &vertices);


	VBO(float* vertices, GLsizeiptr size);

	void bind();
	void unbind();
	void remove();
};

#endif