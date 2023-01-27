#include "graph.h"

#define _USE_MATH_DEFINES
#include <cmath>

Graph::Graph() {



	float h = 0.25f;
	
	float xmin = 0.0f;
	float xmax = 1.0f;
	float ymin = 0.0f;
	float ymax = 1.0f;



	float z{};
	for (float x = 0; x < 1; x += h) {
		
		//float z = 5 * sin(x);
		//vertices.push_back(Vertex{glm::vec3(x, 0, z), glm::vec3(x, 0, z)});


		for (float y = 0; y < 1; y += h) {
			
			//float func{ 3 * x - x * 3 - 3 *x * y * 2 };
			


			z = sin(glm::pi<float>() * x) * sin(glm::pi<float>() * y);
			vertices.push_back(Vertex{glm::vec3(x, y, z), glm::vec3(x, y, z)});
			z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * y);
			vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });
			z = sin(glm::pi<float>() * x) * sin(glm::pi<float>() * (y + h));
			vertices.push_back(Vertex{ glm::vec3(x, y + h, z), glm::vec3(x, y, z) });
			vertices.push_back(Vertex{ glm::vec3(x, y + h, z), glm::vec3(x, y, z) });
			z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * y);
			vertices.push_back(Vertex{ glm::vec3(x + h, y, z), glm::vec3(x, y, z) });
			z = sin(glm::pi<float>() * (x + h)) * sin(glm::pi<float>() * (y + h));
			vertices.push_back(Vertex{ glm::vec3(x + h, y + h, z), glm::vec3(x, y, z )});
		}
	}
}

Graph::~Graph()
{
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