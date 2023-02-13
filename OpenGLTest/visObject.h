
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

#include "positionComponent.h"
#include "vertex.h"
#include "shader.h"

// Hensikten med denne klassen er at vi skal tegne alle 3d objeket
// gjennom klasser som arver fra denne
class visObject : public PositionComponent {
public:
	visObject();
	~visObject();

	// Virtual
	// Lar klasser som arver lage en override av funksjonen
	virtual void init(int inMatrixUniform);

	// Pure virtual
	// F�r det ved � skrive = 0 etter funksjonen
	// Tvinger alle klasser som arver fra denne til � ha sin egen override av funksjonen
	virtual void draw() = 0; 

	// Alle klasser som arver kan skrive til fil
	void writeFile(std::string adress);
	// Men bare en skal trenge � lese
protected:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	unsigned int VAO{ 0 };
	unsigned int VBO{ 0 };
	unsigned int EBO{ 0 };
	int matrixUniform{ 0 };

	glm::mat4 matrix;
};

#endif