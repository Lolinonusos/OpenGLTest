#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>

class EBO {
public:
	unsigned int ID;
	EBO(unsigned int* indices, GLsizeiptr size);

	void bind();
	void unbind();
	void remove();
};

#endif