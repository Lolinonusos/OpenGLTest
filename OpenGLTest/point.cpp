#include "point.h"

Point::Point(float x, float y, float z, float r, float g, float b) {
	vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(r, g, b) });
	//vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
	//vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
}

Point::~Point() {
}

void Point::init() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

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

	glBindVertexArray(0);
}

void Point::draw(Shader shader) {
	glBindVertexArray(VAO);
	//glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	shader.setMat4("model", model);
	glDrawArrays(GL_POINTS, 0, vertices.size());
}
