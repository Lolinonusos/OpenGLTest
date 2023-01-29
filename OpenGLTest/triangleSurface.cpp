#include "triangleSurface.h"

TriangleSurface::TriangleSurface() :visObject() {

	float h = 0.005f;

	float min = -2.0f;
	float max = 2.0f;

	float x = min;
	float y{};
	float z{};
	for (x = min; x <= max; x += h) {


		y = 3 * sin(x * 6);
		vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
		//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

		y = 3 * sin((x + h) * 6);
		vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });
		//std::cout << '(' << x + h << ", " << y << ", " << z << ')' << std::endl;

		y = 3 * sin(x * 6);
		vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
		//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
	}

	matrix = glm::mat4(1.0f);
}

TriangleSurface::TriangleSurface(std::string fileName, bool write) : visObject() {
	
	if (write) {
		writefile(fileName);
	}
	readFile(fileName);
}

TriangleSurface::~TriangleSurface() {

}

void TriangleSurface::writefile(std::string fileName) {
	std::ofstream out;
	out.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (out.is_open()) {
		auto n = vertices.size();
		Vertex vertex;
		out << n << std::endl;
		for (auto i = vertices.begin(); i  != vertices.end(); i++) {
			out << *i << std::endl;
		}
		out.close();
	}
	else {
	std::cout << "ERROR: Could not find file" << std::endl;
	}

}

void TriangleSurface::readFile(std::string fileName) {
	std::ifstream in;
	
	in.open(fileName.c_str());

	if (in.is_open()) {
		unsigned int n;
		in >> n; // Antall linjer
		Vertex vertex;
		vertices.reserve(n);
		for (int i = 0; i < n; i++) {
			in >> vertex;
			//std::cout << "I read that file a million times " << i << std::endl;
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
	glDrawArrays(GL_LINE_LOOP, 0, vertices.size());// vertices.size());
}
