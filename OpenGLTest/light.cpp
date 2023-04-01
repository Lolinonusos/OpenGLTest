#include "light.h"

Light::Light() {
	vertices.push_back(Vertex{ glm::vec3(-0.25f, -0.25f, 0.25f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(0.0f, 0.0f)});
	vertices.push_back(Vertex{ glm::vec3(0.25f, -0.25f, 0.25f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(1.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.25f, 0.0f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(0.5f, 0.5f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, -0.25f, -0.25f), glm::vec3(0.8f,0.8f, 0.8f), glm::vec2(0.5f, 0.5f) });

	

	
}

void Light::init() {


}

void Light::draw() {
	//glBindVertexArray(VAO);
	//glDrawElements(GL_TRIANGLES, indices.size, GL_UNSIGNED_INT, nullptr);
	//glBindVertexArray(0);
}