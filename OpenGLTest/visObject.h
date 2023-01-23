#ifndef VISOBJECT_H
#define VISOBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "vertex.h"

// Hensikten med denne klassen er at vi skal tegne alle 3d objeket
// gjennom klasser som arver fra denne
class visObject {
public:
	visObject();
	~visObject();

	// Virtual
	// Lar klasser som arver lage en override av funksjonen
	virtual void init();
	// Pure virtual??????????????
	// Får det ved å skrive = 0 etter funksjonen
	// Tvinger alle klasser som arver fra denne til å ha sin egen override av funksjonen
	virtual void draw() = 0; 
protected:
	std::vector<Vertex> vertices;
	unsigned int VAO{};
	unsigned int VBO{};

	GLint matrixUniform{};

	glm::mat4 matrix;
};

#endif