#include "graph.h"

#define _USE_MATH_DEFINES
#include <cmath>

Graph::Graph() {

	float h = 0.1f;
	
	float min = -10.0f;
	float max = 10.0f;
	
	float x = min;
	float y{};
	float z{};
	for ( x = min; x <= max; x += h) {
		

			//y = 3 * sin(x * 6);
			//vertices.push_back(Vertex{glm::vec3(x, y, z), glm::vec3(x, y, z)});
			////std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			//y = 3 * sin((x + h) * 6);
			//vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });
			////std::cout << '(' << x + h << ", " << y << ", " << z << ')' << std::endl;
			//
			//y = 3 * sin(x * 6);
			//vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
			////std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;


		for (float y = min; y <= max; y += h) {
			//z = ;
			//vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << ' ' << '(' << x << ", " << y << ", " << z << ')' << '(' << 0 << ", " << 0 << ')' << std::endl;
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
		/*	vertices.push_back(Vertex{ glm::vec3(x, y + h, z), glm::vec3(x, y, z) });
			std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * y);
			vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });
			std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * (y + h));
			vertices.push_back(Vertex{ glm::vec3(x + h, y + h, z), glm::vec3(x, y, z )});*/
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			//z = 3 * sin(x * 6);
			//vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << ' ' << '(' << x << ", " << y << ", " << z << ')' << '(' << 0 << ", " << 0 << ')' << std::endl;

			//z = sin(glm::pi<float>() * x) * sin(glm::pi<float>() * y);
			//vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			//z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * y);
			//vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			//z = sin(glm::pi<float>() * x) * sin(glm::pi<float>() * (y + h));
			//vertices.push_back(Vertex{ glm::vec3(x, y + h, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
			//vertices.push_back(Vertex{ glm::vec3(x, y + h, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			//z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * y);
			//vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;

			//z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * (y + h));
			//vertices.push_back(Vertex{ glm::vec3(x + h, y + h, z), glm::vec3(x, y, z) });
			//std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
			
			//float z = x * sin(y);
			//vertices.push_back(Vertex{ x, y, z, x, y, z });

			//z = (x + h) * sin(y);
			//vertices.push_back(Vertex{ x + h, y, z, x, y, z });

			//z = x * (sin(y + h));
			//vertices.push_back(Vertex{ x, y + h, z, x, y, z });
			//vertices.push_back(Vertex{ x, y + h, z, x, y, z });

			//z = (x + h) * sin(y);
			//vertices.push_back(Vertex{ x + h, y, z, x, y, z });

			//z = (x + h) * (sin(y + h));
			//vertices.push_back(Vertex{ x + h, y + h, z, x, y, z });

			z = 2 * cos(x) * sin(y);
			vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });

			z = 2 * cos(x+h) * sin(y);
			vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });

			z = 2 * cos(x) * sin(y+h);
			vertices.push_back(Vertex{ glm::vec3(x, y + h, z), glm::vec3(x, y, z) });
			vertices.push_back(Vertex{ glm::vec3(x, y + h, z), glm::vec3(x, y, z) });

			z = 2 * cos(x+h) * sin(y);
			vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });

			z = 2 * cos(x+h) * sin(y+h);
			vertices.push_back(Vertex{ glm::vec3(x + h, y + h, z), glm::vec3(x, y, z) });

		}
	}
}

Graph::~Graph(){
}

void Graph::init(int inMatrixUniform) {
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

void Graph::draw() {
	glBindVertexArray(VAO);
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());// vertices.size());
}

// GL_TRIANGLES
// GL_LINES
// GL_LINE_LOOP
// GL_POINTS