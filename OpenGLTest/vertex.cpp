#include "vertex.h"

void Vertex::addVert(float x, float y, float z, float r, float g, float b, float u, float v) {
	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);
	vertices.push_back(r);
	vertices.push_back(g);
	vertices.push_back(b);
	vertices.push_back(u);
	vertices.push_back(v);
}
