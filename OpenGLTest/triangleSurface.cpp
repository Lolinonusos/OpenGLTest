#include "triangleSurface.h"

TriangleSurface::TriangleSurface(Shader* inShader) :VisObject() {

	objShader = inShader;

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

	model = glm::mat4(1.0f);
}

TriangleSurface::TriangleSurface(Shader* inShader, std::string fileName, bool write) : VisObject() {
	
	objShader = inShader;

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
		auto n = vertices.size(); // Totale mengder vertex punkter
		Vertex vertex;
		out << n << std::endl; // Skriver inn inn totale mengden punkter �verst p� fila
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
			vertices.push_back(vertex);
		}
		in.close();
	}
	else {
		std::cout << "ERROR: Could not find file" << std::endl;
	}
}

void TriangleSurface::init() {
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
	//glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(getTranslateMatrix()));
	objShader->use();
	objShader->setMat4("model", model);
	glDrawArrays(GL_LINE_STRIP, 0, vertices.size());// vertices.size());
}
