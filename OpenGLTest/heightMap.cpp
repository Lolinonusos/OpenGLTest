#include "heightMap.h"

HeightMap::HeightMap(const char* imgPath, Shader *inShader, std::string inName) {
	objShader = inShader;
	name = inName;

	int width, height, channels;
	unsigned char* data = stbi_load(imgPath, &width, &height, &channels, 1);

	float res = 1;
	float x{};
	float y{};
	float z{};
	int vert{};

	for (x = -height / 2; x < (height / 2); x += res) {
		for (z = -height / 2; z < (width / 2); z += res) {

			y = (float)data[vert];
			vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, y, z) });

			y = (float)data[vert+width];
			vertices.push_back(Vertex{ glm::vec3(x + res, y, z), glm::vec3(x, y, z) });

			y = (float)data[vert+1];
			vertices.push_back(Vertex{ glm::vec3(x, y, z + res), glm::vec3(x, y, z) });
			vertices.push_back(Vertex{ glm::vec3(x, y, z + res), glm::vec3(x, y, z) });

			y = (float)data[vert+width];
			vertices.push_back(Vertex{ glm::vec3(x + res, y, z), glm::vec3(x, y, z) });

			y = (float)data[vert+1+width];
			vertices.push_back(Vertex{ glm::vec3(x + res, y, z + res), glm::vec3(x, y, z) });

			vert++;
			// Get tex elvation for (i, j) tex coordinate)
			//unsigned char* texEl = data + (j + width * i) * channels;
			// Raw height at coordinate
			//unsigned char y = texEl[0]; // Needs correct path to file, gives nullptr if file is not found

		/*	vertices.push_back(Vertex{ 
				(-height / 2.0f + height * i/(float)height), 
				((int)y * yScale - yShift), 
				(-width / 2.0f + width * j / (float)width) 
			});*/
		}
	}
	
	stbi_image_free(data);

	for (unsigned int i = 0; i < height - 1; i++) {
		for (unsigned int j = 0; j < width; j++) {
			for (unsigned int k = 0; k < 2; k++) {
				indices.push_back(j + width * (i + k));
			}
		}
	}


}

void HeightMap::init() {
	// Vertex Array Object - VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Vertex Buffer Object - VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	// Element Buffer Object - EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	// Set vertex attribute pointers
	// Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// Vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// Vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6 * sizeof(float)));

	glBindVertexArray(0);
}

void HeightMap::draw() {
	glBindVertexArray(VAO);

	objShader->use();
	objShader->setMat4("model", model);

		switch (RenderStyle(renderVal)) {
		case SOLID:
			//glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
			//glDrawElements(GL_TRIANGLE_STRIP, NUM_VERTS_PER_STRIP, GL_UNSIGNED_INT, (void*)(sizeof(unsigned int) * NUM_VERTS_PER_STRIP * strip));
			//glDrawArrays(GL_TRIANGLES, 0, vertices.size());// vertices.size());
			//glDrawArrays(GL_POINTS, 0, vertices.size());// vertices.size());
			glDrawArrays(GL_LINE_STRIP, 0, vertices.size());// vertices.size());

			break;
		case WIREFRAME:
			glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, nullptr);
			break;
		case HIDDEN:
			glDrawElements(GL_POINTS, indices.size(), GL_UNSIGNED_INT, nullptr);
			break;
		default:
			std::cout << "ERROR::INVALID_RENDER_METHOD" << std::endl;
			break;
		}
		glBindVertexArray(0);

}
