#ifndef VERTEX_H
#define VERTEX_H


#include <vector>
#include "glm/glm.hpp"

class Vertex {
public:
	// Will hold x, y, z coortinates, r, g, b values, and u, v coordinates
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
};

#endif