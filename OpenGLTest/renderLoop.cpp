#include "renderLoop.h"

renderLoop::renderLoop() {

	shaderProgram = new Shader("SkolVert.vs", "SkolFrag.fs");



	for (auto i = objVec.begin(); i != objVec.end(); i++) {
		objMap.insert(std::pair<std::string, VisObject*>{(*i)->getName(), (*i)});
	}
}


void renderLoop::initialize()
{


	for (auto i = objMap.begin(); i != objMap.end(); i++)
		(*i).second->init();
}

void renderLoop::render() {

	shaderProgram->use();

	for (auto i = objMap.begin(); i != objMap.end(); i++)
		i->second->draw(*shaderProgram);
}

renderLoop::~renderLoop() {

	// Background colour
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Clear depth buffer
	glClear(GL_DEPTH_BUFFER_BIT);
	// Can be written together like this
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto i = objMap.begin(); i != objMap.end(); i++)
		i->second->~VisObject();
}