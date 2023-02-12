#include "octahedronBall.h"

OctahedronBall::OctahedronBall(int n) : recursions(n), indices(0), visObject() {
	vertices.reserve(3 * 8 * pow(4, recursions));
	octahedronUnitBall();
}

OctahedronBall::~OctahedronBall() {

}

void OctahedronBall::init(int matrixUniform) {
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
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	// Vertex texture coords
	//glEnableVertexAttribArray(2);
	//glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	glBindVertexArray(0);
}

void OctahedronBall::draw() {
	glBindVertexArray(VAO);
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

void OctahedronBall::octahedronUnitBall() {
	glm::vec3 v0 { glm::vec3(0.0f, 0.0f, 1.0f) };
	glm::vec3 v1 { glm::vec3(1.0f, 0.0f, 0.0f) };
	glm::vec3 v2 { glm::vec3(0.0f, 1.0f, 0.0f) };
	glm::vec3 v3 { glm::vec3(-1.0f, 0.0f, 0.0f) };
	glm::vec3 v4 { glm::vec3(0.0f, -1.0f, 0.0f) };
	glm::vec3 v5 { glm::vec3(0.0f, 0.0f, -1.0f) };


	subdivide(v0, v1, v2, recursions);
	subdivide(v0, v2, v3, recursions);
	subdivide(v0, v3, v4, recursions);
	subdivide(v0, v4, v1, recursions);
	subdivide(v5, v2, v1, recursions);
	subdivide(v5, v3, v2, recursions);
	subdivide(v5, v4, v3, recursions);
	subdivide(v5, v1, v4, recursions);
}

void OctahedronBall::makeTriangle(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3) {
	Vertex v{ v1.x, v1.y, v1.z, v1.r, v1.g, v1.b };
	vertices.push_back(v);
	v = Vertex{ v2.x, v2.y, v2.z, v2.r, v2.g, v2.b };
	vertices.push_back(v);
	v = Vertex{ v3.x, v3.y, v3.z, v3.r, v3.g, v3.b };
	vertices.push_back(v);
}

void OctahedronBall::subdivide(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, int n) {
	if (n > 0) {
		glm::vec3 v1 = a + b;
		glm::normalize(v1);
		glm::vec3 v2 = a + c;
		glm::normalize(v2);
		glm::vec3 v3 = c + b;
		glm::normalize(v3);

		subdivide(a, v1, v2, n - 1);
		subdivide(b, v2, v3, n - 1);
		subdivide(c, v3, v1, n - 1);
		subdivide(v3, v2, v1, n - 1);
	}
	else {
		makeTriangle(a, b, c);
	}
}
