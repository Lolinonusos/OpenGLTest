#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>

//#include "vertex.h"

class VBO {
public:
	unsigned int ID;
	VBO(float* vertices, GLsizeiptr size);
	//VBO(std::vector<float> vertices, GLsizeiptr size); // Using vertex class


	void bind();
	void unbind();
	void remove();
};

#endif