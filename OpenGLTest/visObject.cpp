#include "visObject.h"



VisObject::VisObject() {
	// set to matrixes to be identity Matrixes
	model = glm::mat4(1.0f);

}

VisObject::~VisObject() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

}

void VisObject::setName(std::string inName) {
	name = inName;
}

std::string VisObject::getName() {
	return name;
}

void VisObject::init() {
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
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	glBindVertexArray(0);
}

void VisObject::draw() {
	glBindVertexArray(VAO);
	objShader->use();
	objShader->setMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

void VisObject::setRenderStyle(int i) {
	renderVal = i;
}

void VisObject::getNormals() {
	glm::vec3 normal = glm::vec3(0.0f, 1.0f, 0.0f);  // The normal for the plane
	//std::vector<glm::vec3> normals;  // Vector to store the normals for each vertex
	for (int i = 0; i < sizeof(vertices) / sizeof(GLfloat); i ++) {
		glm::vec3 v1 = glm::vec3(vertices[i].position);
		glm::vec3 v2;
		glm::vec3 v3;
		if (i + 5 < sizeof(vertices) / sizeof(GLfloat)) {
			// Calculate the normal for the first triangle of the quad
			v2 = glm::vec3(vertices[i + 1].position);
			v3 = glm::vec3(vertices[i + 2].position);
			normal = glm::normalize(glm::cross(v2 - v1, v3 - v1));
		}
		else {
			// Calculate the normal for the second triangle of the quad
			v2 = glm::vec3(vertices[i].position);
			v3 = glm::vec3(vertices[i + 1].position);
			normal = glm::normalize(glm::cross(v3 - v1, v2 - v1));
		}
		vertNormals.push_back(normal);
	}
}

void VisObject::drawNormals() {
	//for (int i = 0; i < sizeof(vertices) / sizeof(GLfloat); i += 3) {
	//	glm::vec3 position(vertices[i], vertices[i + 1], vertices[i + 2]);
	//	glm::vec3 normal = vertNormals[i / 3];
	//	vertNormals.push_back(position);
	//	vertNormals.push_back(position + normal);
	//}
	
	//glGenVertexArrays(1, &VAO);
	//glBindVertexArray(VAO);

	//glGenBuffers(1, &VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, vertNormals.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	//// Set vertex attribute pointers
	//// Vertex positions
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	//glDrawElements(GL_LINES, sizeOf()/sizeOf(GLuint), GL_UNSIGNED_INT, )
}