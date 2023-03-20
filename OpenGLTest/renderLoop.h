#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>
#include <unordered_map>

//#include "main.h"
#include "Camera.h"

//#include "shader.h"
#include "texture.h"

#include "positionComponent.h"
#include "visObject.h"

#include "cube.h"


class renderLoop {
public:
	//Shader* shaderProgram{ nullptr };
	//Texture* texture{ nullptr };

	std::vector<Shader*> shaders;
	std::vector<Texture*> textures;

	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 800;

	Camera camera;

	renderLoop();
	~renderLoop();

	// run initialize here
	void initialize();

	void render();

	std::vector<VisObject*> objVec;
	std::unordered_map<std::string, VisObject*> objMap;

	// matrixes
	glm::mat4 model{};
	glm::mat4 view{};
	glm::mat4 projection{};

private:
};

