#include "light.h"

Light::Light(Shader *inShader, std::string inName) {
	name = inName;
	objShader = inShader;

	vertices.push_back(Vertex{ glm::vec3(-0.25f, -0.25f, 0.25f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(0.0f, 0.0f)});
	vertices.push_back(Vertex{ glm::vec3(0.25f, -0.25f, 0.25f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(1.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.25f, 0.0f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(0.5f, 0.5f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, -0.25f, -0.25f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(0.5f, 0.5f) });

	

	
}

void Light::init() {
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
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// Vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6 * sizeof(float)));

	glBindVertexArray(0);

}

void Light::draw() {
	glBindVertexArray(VAO);
	
	objShader->use();
	objShader->setMat4("model", model);


	switch (RenderStyle(renderVal)) {
	case SOLID:
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
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