#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex {
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;

	Vertex() {

	};
	Vertex(glm::vec3 xyz) {
		position = xyz;
	};
	Vertex(glm::vec3 xyz, glm::vec3 rgb) {
		position = xyz;
		normal = rgb;
	};
	Vertex(glm::vec3 xyz, glm::vec3 rgb, glm::vec2 uv) {
		position = xyz;
		normal = rgb;
		texCoord = uv;
	};



	Vertex(float x, float y, float z, float r, float g, float b, float u, float v) {
		position = glm::vec3(x, y, z);
		normal = glm::vec3(r, g, b);
		texCoord = glm::vec2(u, v);
	}
};

#endif