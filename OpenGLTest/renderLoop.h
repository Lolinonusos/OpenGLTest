#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "shader.h"

#include "positionComponent.h"
#include "visObject.h"

class renderLoop {
public:
	Shader* shaderProgram{ nullptr };



	renderLoop();
	~renderLoop();

	// run initialize here
	void initialize();

	void render();

	std::vector<VisObject*> objVec;
	std::unordered_map<std::string, VisObject*> objMap;

	// matrixes
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

private:
};

