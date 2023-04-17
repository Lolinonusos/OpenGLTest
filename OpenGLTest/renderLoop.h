#pragma once

//#include "main.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>
#include <unordered_map>

#include "Camera.h"

//#include "shader.h"
#include "texture.h"

#include "positionComponent.h"
#include "visObject.h"

#include "interactive.h"
#include "cube.h"
#include "heightMap.h"
#include "light.h"
#include "plane.h"
#include "interactive.h"


class renderLoop {
public:
	//Shader* shaderProgram{ nullptr };
	//Texture* texture{ nullptr };


	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 800;

	Camera camera{ glm::vec3(0.0f, 2.0f, 3.0f) };
	


	renderLoop();
	~renderLoop();

	// run initialize here
	void initialize();

	void render();

	void processInput();
	void mouse_callback(GLFWwindow*, double xPosIn, double yPosIn);

	// matrixes
	glm::mat4 model{};
	glm::mat4 view{};
	glm::mat4 projection{};

	float lastX = SCR_WIDTH / 2;
	float lastY = SCR_HEIGHT / 2;
	bool firstMouse = true;

	std::vector<VisObject*> objects;
	std::unordered_map<std::string, VisObject*> objectMap;

	std::vector<Shader*> shaders;
	std::unordered_map <std::string, Shader*> shaderMap;

	std::vector<Texture*> textures;
	std::unordered_map < std::string, Texture*> textureMap;

private:

};

