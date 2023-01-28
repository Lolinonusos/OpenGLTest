
#ifndef VISOBJECT_H
#define VISOBJECT_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "vertex.h"
#include "shader.h"

// Hensikten med denne klassen er at vi skal tegne alle 3d objeket
// gjennom klasser som arver fra denne
class visObject {
public:
	visObject();
	~visObject();

	// Virtual
	// Lar klasser som arver lage en override av funksjonen
	virtual void init(int inMatrixUniform);

	// Pure virtual
	// Får det ved å skrive = 0 etter funksjonen
	// Tvinger alle klasser som arver fra denne til å ha sin egen override av funksjonen
	virtual void draw() = 0; 
protected:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	unsigned int VAO{};
	unsigned int VBO{};

	int matrixUniform{};
	glm::mat4 matrix;



	glm::mat4 position;
	glm::mat4 rotation;
	glm::mat4 scale;




};

#endif