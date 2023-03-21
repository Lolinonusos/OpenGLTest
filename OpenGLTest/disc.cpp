#include "disc.h"

Disc::Disc() {
	vertices.push_back(Vertex{ 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f });
	for (unsigned int i = 0; i < 13; i++) {
		double angle = 30 * i * 3.14 / 180;
		float x = cos(angle);
		float y = sin(angle);
		float z{ 0.0f };
		float r = i % 2;
		float g{ 0.0f };
		float b{ 0.5f };
		vertices.push_back(Vertex{ x, y, z, r, g, b });
	}
	for (unsigned int i = 0; i < 14; i++) {
		indices.push_back(i);
	}
}

Disc::~Disc() {

}

void Disc::init() {
	//Vertex Array Object - VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//Vertex Buffer Object - VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	// Set vertex attribute pointers
	// Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// Vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	// Vertex texture coords
	//glEnableVertexAttribArray(2);
	//glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	// Element Buffer Object - EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Disc::draw(Shader shader) {
	glBindVertexArray(VAO);
	//glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	shader.setMat4("model", model);
	glDrawElements(GL_TRIANGLE_FAN, vertices.size(), GL_UNSIGNED_INT, 0);
}