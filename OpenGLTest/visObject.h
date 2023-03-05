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
class VisObject : public PositionComponent {
public:
	VisObject();
	~VisObject();

	// Virtual
	// Lar klasser som arver lage en override av funksjonen
	virtual void init(int inMatrixUniform);

	// Pure virtual
	// Får det ved å skrive = 0 etter funksjonen
	// Tvinger alle klasser som arver fra denne til å ha sin egen override av funksjonen
	virtual void draw() = 0; 

	void setRenderStyle(int i);

	// Alle klasser som arver kan skrive til fil
	void writeFile(std::string adress);
	// Men bare en skal trenge å lese
	
	int vertexAmount() {
		return vertices.size();
	}

	glm::vec3 getVertexPosition(int index) {
		return vertices[index].position;
	}

	void collider(float inRadius = 1.0f) {
		radius = inRadius;
	}
	virtual void checkCollision(VisObject* other) {
		//const glm::vec3 you = this->position;
		float dist = glm::distance(this->position, other->position);
		if (dist < this->radius + other->radius) {
			std::cout << "collision" << std::endl;
		}
	}

	float radius{};

protected:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	unsigned int VAO{ 0 };
	unsigned int VBO{ 0 };
	unsigned int EBO{ 0 };
	int matrixUniform{ 0 };

	enum RenderStyle {
		SOLID,
		WIREFRAME,
		HIDDEN
	};
	int renderVal;

	// Collision
};

#endif