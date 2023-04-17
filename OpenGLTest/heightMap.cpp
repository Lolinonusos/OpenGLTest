#include "heightMap.h"

HeightMap::HeightMap(const char* imgPath, Shader *inShader, std::string inName) {
	objShader = inShader;
	name = inName;

	FromImageFile(imgPath, 30, 15, 100);

	//int width, height, channels;
	//unsigned char* data = stbi_load(imgPath, &width, &height, &channels, 1);

	//float one = 1;
	//float x{}; // right / left
	//float y{}; // up / down
	//float z{}; // in / out of screen
	//int vert{}; // run through image data array with this

	//float heightMultiplier{0.3};

	//// Dag mode
	//for (x = -width / 2; x < (width / 2); x += one) {
	//	for (z = -height / 2; z < (height / 2); z += one) {

	//		y = (float)data[vert] * heightMultiplier;
	//		vertices.push_back(Vertex{ glm::vec3(x, y, z), glm::vec3(x, 0, z) });

	//		y = (float)data[vert + width] * heightMultiplier;
	//		vertices.push_back(Vertex{ glm::vec3(x + one, y, z), glm::vec3(x, 0, z) });

	//		y = (float)data[vert + 1] * heightMultiplier;
	//		vertices.push_back(Vertex{ glm::vec3(x, y, z + one), glm::vec3(x, 0, z) });
	//		vertices.push_back(Vertex{ glm::vec3(x, y, z + one), glm::vec3(x, 0, z) });

	//		y = (float)data[vert + width] * heightMultiplier;
	//		vertices.push_back(Vertex{ glm::vec3(x + one, y, z), glm::vec3(x, 0, z) });

	//		y = (float)data[vert + 1 + width] * heightMultiplier;
	//		vertices.push_back(Vertex{ glm::vec3(x + one, y, z + one), glm::vec3(x, 0, z) });

	//		vert++;
	//	}
	//}
	//
	//stbi_image_free(data);

	//// Tror ikke disse funker :)

	//// Generate indices
	//for (unsigned int x = 0; x < width; x++) {
	//	for (unsigned int z = 0; z < height; z++) {
	//		int idx = z * (width + 1) + x;

	//		// First triangle
	//		indices.push_back(idx);
	//		indices.push_back(idx + 1);
	//		indices.push_back(idx + (width + 1));

	//		// Second triangle
	//		indices.push_back(idx + 1);
	//		indices.push_back(idx + 1 + (width + 1));
	//		indices.push_back(idx + (width + 1));
	//	}
	//}

}

void HeightMap::FromImageFile(const std::string& fileName, float size, float maxHeight, unsigned resolution)
{
	int numComponents = 4; // RGBA
	int imageWidth, imageHeight, imageNumComponents;
	unsigned char* imageData = stbi_load(fileName.c_str(), &imageWidth, &imageHeight, &imageNumComponents, numComponents);
	if (!imageData) {
		std::cout << ("Failed to load image from file: " + fileName);
		return;
	}
	//numComponents = imageNumComponents;
	

	vertices.clear();
	indices.clear(); // Add a new index vector

	float h = size / resolution;
	float hSize = size / 2.f;
	glm::vec3 color(0.5f, 0.5f, 0.5f);

	const int shortestSide = std::min(imageWidth, imageHeight);
	const float pixelJump = (float)shortestSide / (float)resolution;

	for (int x = 0; x < resolution - 1; x++)
	{
		for (int y = 0; y < resolution - 1; y++)
		{
			// Calculate the unique vertex index for each corner of the current quad
			int bottomLeftIndex = x + y * resolution;
			int bottomRightIndex = (x + 1) + y * resolution;
			int topLeftIndex = x + (y + 1) * resolution;
			int topRightIndex = (x + 1) + (y + 1) * resolution;

			// Add the indices for the two triangles of the quad
			indices.push_back(bottomLeftIndex);
			indices.push_back(bottomRightIndex);
			indices.push_back(topLeftIndex);

			indices.push_back(topLeftIndex);
			indices.push_back(bottomRightIndex);
			indices.push_back(topRightIndex);
		}
	}

	float xp = 0.f;
	float yp = 0.f;
	for (int x = 0; x < resolution; x++)
	{
		for (int y = 0; y < resolution; y++)
		{
			int index = ((int)(yp / imageHeight * (resolution - 1))) * imageWidth + (int)(xp / imageWidth * (resolution - 1));
			float height = imageData[index * numComponents] / 255.f * maxHeight;

			//height = (float)imageData[vert] * heightMultiplier

			vertices.emplace_back(x * h - hSize, height, y * h - hSize, color, x / (float)resolution, y / (float)resolution);
			yp += pixelJump;
		}
		xp += pixelJump;
		yp = 0.f;
	}

	stbi_image_free(imageData);
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
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, (void*)0);
		//glDrawElements(GL_TRIANGLE_STRIP, NUM_VERTS_PER_STRIP, GL_UNSIGNED_INT, (void*)(sizeof(unsigned int) * NUM_VERTS_PER_STRIP * strip));
		//glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		//glDrawArrays(GL_POINTS, 0, vertices.size());
		//glDrawArrays(GL_LINES, 0, vertices.size());
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

void HeightMap::bary(glm::vec3 point) {

	for (int i = 0; i < vertices.size(); i += 3) {

	}

	float A = 0;
	float B = 0;
	float C = 0;



}