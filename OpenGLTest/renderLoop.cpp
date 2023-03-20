#include "renderLoop.h"

renderLoop::renderLoop() {




	objVec.push_back(new Cube());

	for (auto i = objVec.begin(); i != objVec.end(); i++) {
		objMap.insert(std::pair<std::string, VisObject*>{(*i)->getName(), (*i)});
	}

	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
}


void renderLoop::initialize()
{

	for (auto i = objMap.begin(); i != objMap.end(); i++) {
		(*i).second->init();
	}

	//shaders.push_back(new Shader("SkolVert.vs", "SkolFrag.fs"));
	shaders.push_back(new Shader("firstTex.vs", "firstTex.fs"));

	textures.push_back(new Texture("Helene.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE));

	shaders[0]->use();
	shaders[0]->setInt("tex0", 0);
	//textures[0]->texUnit(*shaders[0], "tex0", 0);
}

void renderLoop::render() {

	// Background colour
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Clear depth buffer
	glClear(GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	

	shaders[0]->use();
	textures[0]->bind();

	projection = glm::perspective(glm::radians(camera.zoom), (float)(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
	shaders[0]->setMat4("projection", projection);


	// View matrix
	view = camera.getViewMatrix();
	shaders[0]->setMat4("view", view);

	//for (auto i = objMap.begin(); i != objMap.end(); i++) {
	//	(*i).second->draw(*shaderProgram);
	//}
	for (auto& obj : objMap) {
		obj.second->draw(*shaders[0]);
	}
}

renderLoop::~renderLoop() {

	for (auto& obj : objMap) {
		delete obj.second;
	}
}