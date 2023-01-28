#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex {
private:

	//! Overloaded ostream operator which writes all vertex data on an open textfile stream
	friend std::ostream& operator<< (std::ostream & os, const Vertex & v) {
			os << std::fixed;
			os << "(" << v.position.x << ", " << v.position.y << ", " << v.position.z << ") ";
			os << "(" << v.normal.x << ", " << v.normal.y << ", " << v.normal.z << ") ";
			os << "(" << v.texCoord.x << ", " << v.texCoord.y << ") ";
			return os;
	};

	//! Overloaded ostream operator which reads all vertex data from an open textfile stream
	friend std::istream& operator>> (std::istream & is, Vertex & v) {
			// Trenger fire temporære variabler som kun skal lese inn parenteser og komma
			char dum, dum2, dum3, dum4;
			is >> dum >> v.position.x >> dum2 >> v.position.y >> dum3 >> v.position.z >> dum4;
			is >> dum >> v.normal.x >> dum2 >> v.normal.x >> dum3 >> v.normal.z >> dum4;
			is >> dum >> v.texCoord.x >> dum2 >> v.texCoord.y >> dum3;
			return is;

	};

public:

	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;

	//float position[3];
	//float normal[3];
	//float texCoord[2];


	// This is overloading
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

	Vertex(float x, float y, float z) {
		position = glm::vec3(x, y, z);
	};

	Vertex(float x, float y, float z, float r, float g, float b) {
		position = glm::vec3(x, y, z);
		normal = glm::vec3(r, g, b); 
	};

	Vertex(float x, float y, float z, float r, float g, float b, float u, float v) {
		position = glm::vec3(x, y, z);
		normal = glm::vec3(r, g, b);
		texCoord = glm::vec2(u, v);
	};

};

#endif