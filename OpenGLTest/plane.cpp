#include "plane.h"

Plane::Plane(Shader* inShader, std::string inName) {
	
	model = glm::mat4(1.0f);
	objShader = inShader;
	name = inName;
	
	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f,  0.5f) });
	vertices.push_back(Vertex{ glm::vec3( 0.5f, 0.0f,  0.5f) });
	vertices.push_back(Vertex{ glm::vec3( 0.5f, 0.0f, -0.5f) });

	// First triangle
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	// Second triangle
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(0);
}

Plane::~Plane() {
}

void Plane::init() {
	// Vertex Array Object - VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Vertex Buffer Object - VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	// Element Buffer Object - EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	// Set vertex attribute pointers
	// Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// Vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// Vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6 * sizeof(float)));

	glBindVertexArray(0);
}

void Plane::draw() {
    glBindVertexArray(VAO);

    objShader->use();
    objShader->setMat4("model", model);

    switch (RenderStyle(renderVal)) {
    case SOLID:
        //glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, (void*)0);

        break;
    case WIREFRAME:
        glDrawArrays(GL_LINES, 0, vertices.size());
        break;
    case HIDDEN:
        glDrawArrays(GL_POINTS, 0, vertices.size());
        break;
    default:
        std::cout << "ERROR::INVALID_RENDER_METHOD" << std::endl;
        break;
    }
}