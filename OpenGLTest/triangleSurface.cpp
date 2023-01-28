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
}

TriangleSurface::~TriangleSurface() {

}

void TriangleSurface::readFile(std::string fileName) {
	std::ifstream in;
	//fileName = "OpenGLTest\OpenGLTest\Data.txt";
	in.open(fileName.c_str());

	if (in.is_open()) {
		int n;
		Vertex vertex;
		in >> n; // Antall linjer
		vertices.reserve(n);
		for (int i = 0; i < n; i++) {
			in >> vertex;
			std::cout << "I read that file a million times" << i << std::endl;
			vertices.push_back(vertex);
		}
		in.close();
	}
	else {
		std::cout << "ERROR: Could not find file" << std::endl;

	}
}

void TriangleSurface::init(int shader) {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

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

void TriangleSurface::draw()
{
	glBindVertexArray(VAO);
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_LINES, 0, vertices.size());// vertices.size());
}
