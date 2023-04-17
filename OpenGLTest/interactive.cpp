#include "interactive.h"

Interactive::Interactive(Shader *inShader, std::string inName) {
	name = inName;
	objShader = inShader;
	//glm::vec3 inPosition = glm::vec3(0.0f, 0.0f, 0.0f)
    //vecPosition = inPosition;
    
    vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.4f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f) }); // Lower left
    vertices.push_back(Vertex{ glm::vec3(0.5f, -0.4f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)}); // Lower right
    vertices.push_back(Vertex{ glm::vec3(0.0f, 0.4, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f) }); // Upper

}

Interactive::~Interactive(){

}

void Interactive::init()
{
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

void Interactive::draw() {
	glBindVertexArray(VAO);
	//glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	objShader->use();
	objShader->setMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());// vertices.size());
}
