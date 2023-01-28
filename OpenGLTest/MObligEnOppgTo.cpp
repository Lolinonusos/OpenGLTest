#include "MObligEnOppgTo.h"


MObligEnOppgTo::MObligEnOppgTo() {



	float resolution = 0.12f;

	float min = 0.0f;
	float max = 2.0f;


	float z{};
	for (float x = 0; x < max; x += resolution) {



		for (float y = 0; y < 2; y += resolution) {

		}
	}
}

MObligEnOppgTo::~MObligEnOppgTo()
{
}

void MObligEnOppgTo::init(int inMatrixUniform) {
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

void MObligEnOppgTo::draw() {
	glBindVertexArray(VAO);
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());// vertices.size());
}

// GL_TRIANGLES
// GL_LINES
// GL_LINE_LOOP
// GL_POINTS