#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>

#include <vector>

class EBO {
public:
	unsigned int ID;
	EBO(std::vector<unsigned int> &indices);

	void bind();
	void unbind();
	void remove();
};

#endif