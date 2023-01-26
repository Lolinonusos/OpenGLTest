#include "xyz.h"

XYZ::XYZ() {
	vertices.push_back(Vertex{ glm::vec3(0, 0, 0), glm::vec3(1, 0, 0) });
	vertices.push_back(Vertex{ glm::vec3(1, 0, 0), glm::vec3(1, 0, 0) });
	vertices.push_back(Vertex{ glm::vec3(0, 0, 0), glm::vec3(0, 1, 0) });
	vertices.push_back(Vertex{ glm::vec3(0, 1, 0), glm::vec3(0, 1, 0) });
	vertices.push_back(Vertex{ glm::vec3(0, 0, 0), glm::vec3(0, 0, 1) });
	vertices.push_back(Vertex{ glm::vec3(0, 0, 1), glm::vec3(0, 0, 1) });

}

XYZ::~XYZ() {

}

void XYZ::init(int inMatrixUniform) {

	matrixUniform = inMatrixUniform;

	// Generating and binding Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Generating and binding Vertex Buffer Object
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Vertex Buffer Object 
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

void XYZ::draw() {
	glBindVertexArray(VAO);
	
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_LINES, 0, vertices.size());
}
