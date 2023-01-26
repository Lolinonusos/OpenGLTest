#include "triangleSurface.h"

TriangleSurface::TriangleSurface() :visObject() {
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.0f, 0.0), glm::vec3(1.0f, 0.0f, 0.0) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.0f, 0.0), glm::vec3(0.0f, 1.0f, 0.0) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.5f, 0.0), glm::vec3(0.0f, 0.0f, 1.0) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.0f, 0.0), glm::vec3(0.0f, 0.0f, 1.0) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.5f, 0.0), glm::vec3(0.0f, 1.0f, 0.0) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.5f, 0.0), glm::vec3(1.0f, 0.0f, 0.0) });

	matrix = glm::mat4(1.0f);
}

TriangleSurface::TriangleSurface(std::string fileName) : visObject() {
	readFile(fileName);
	matrix = glm::mat4(1.0f);

}

TriangleSurface::~TriangleSurface() {

}

void TriangleSurface::readFile(std::string fileName) {
	std::ifstream in;
	in.open(fileName.c_str());

	if (in.is_open()) {
		int n;
		Vertex vertex;
		in >> n;
		
		vertices.reserve(n);
		for (int i = 0; i < n; i++) {
			//in >> vertex;
			vertices.push_back(vertex);
		}
		in.close();
	}
}

void TriangleSurface::init(int shader)
{
}

void TriangleSurface::draw()
{
}
