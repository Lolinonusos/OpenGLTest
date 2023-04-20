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

	Shader *objShader;

	void setName(std::string name);
	std::string getName();

	// Virtual
	// Lar klasser som arver lage en override av funksjonen
	virtual void init();

	// Pure virtual
	// Får det ved å skrive = 0 etter funksjonen
	// Tvinger alle klasser som arver fra denne til å ha sin egen override av funksjonen
	virtual void draw(); 

	void setRenderStyle(int i);

	// Alle klasser som arver kan skrive til fil
	void writeFile(std::string adress);
	// Men bare en skal trenge å lese
	
	GLsizei vertexAmount() {
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

	void getNormals();

	void drawNormals();

	glm::mat4 GetModelMatrix() {
		glm::mat4 model = glm::mat4(1.f);
		model = glm::translate(model, position);
		return model;
		//model = glm::rotate(model, rotation.)

	}

protected:
	
	std::string name;
	
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<glm::vec3> vertNormals;

	unsigned int VAO{ 0 };
	unsigned int VBO{ 0 };
	unsigned int EBO{ 0 };

	enum RenderStyle {
		SOLID,
		WIREFRAME,
		HIDDEN
	};
	void drawStyle() {
		switch (RenderStyle(renderVal)) {
		case SOLID:
			glDrawArrays(GL_TRIANGLES, 0, vertices.size());
			break;
		case WIREFRAME:
			glDrawArrays(GL_LINES, 0, vertices.size());
			break;
		case HIDDEN:

			break;
		default:
			std::cout << "ERROR::INVALID_RENDER_VALUE" << std::endl;
			break;
		}
	};
	int renderVal;
};

#endif