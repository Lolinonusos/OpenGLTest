#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "mesh.h"


class Axes {

	Axes(std::vector<Vertex> &vertices);
};

class Graph {

	Graph(std::vector<Vertex>& vertices);
};

class Plane {

	Plane(std::vector<Vertex>& vertices);
};

class Tetraeder {

	Tetraeder(std::vector<Vertex>& vertices);
};

class Cube {
public:
	Cube(std::vector<Vertex>& vertices);
};

#endif