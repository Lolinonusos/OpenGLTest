#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>
#include "VBO.h"

class VAO {
public:
	unsigned int ID;
	VAO();

	void linkAttrib(VBO &VBO, unsigned int layout, unsigned int numComponents, GLenum type, GLsizeiptr stride, void* offset);

	void bind();
	void unbind();
	void remove();
};

#endif