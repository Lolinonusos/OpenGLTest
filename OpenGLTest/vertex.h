#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex {
public:
	// Will hold x, y, z coortinates, r, g, b values, and u, v coordinates
	std::vector<float> vertices;

	void addVert(float x, float y, float z, float r, float g, float b, float u, float v);
};

#endif