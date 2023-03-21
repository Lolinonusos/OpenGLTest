#include "renderLoop.h"

renderLoop::renderLoop() {




	objVec.push_back(new Cube());

	for (auto i = objVec.begin(); i != objVec.end(); i++) {
		objMap.insert(std::pair<std::string, VisObject*>{(*i)->getName(), (*i)});
	}

}


void renderLoop::initialize()
{
	shaders.push_back(new Shader("firstTex.vs", "firstTex.fs"));
	//shaders.push_back(new Shader("SkolVert.vs", "SkolFrag.fs"));

	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);

	for (auto i = objMap.begin(); i != objMap.end(); i++) {
		(*i).second->init();
	}


	textures.push_back(new Texture("Helene.png", GL_TEXTURE_2D));
	shaders[0]->use();
	textures[0]->texUnit(*shaders[0], "texture0", 0);

	glEnable(GL_DEPTH_TEST);
}

void renderLoop::render() {

	// Background colour
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Clear depth buffer
	glClear(GL_DEPTH_BUFFER_BIT);


	glActiveTexture(GL_TEXTURE0);
	textures[0]->bind();
	
	// Which shader program we will use
	shaders[0]->use();

	// Projection matrix
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

	//glfwSwapBuffers(window);
	//glfwPollEvents();
}

renderLoop::~renderLoop() {

	for (auto& obj : objMap) {
		delete obj.second;
	}
}

void renderLoop::mouse_callback(GLFWwindow*, double xPosIn, double yPosIn) {

	float xPos = static_cast<float>(xPosIn);
	float yPos = static_cast<float>(yPosIn);

	//std::cout << "Mouse x:" << xPos << "    y:" << yPos << std::endl;
	if (firstMouse) {
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	float xOffset = xPos - lastX;
	float yOffset = lastY - yPos;// reversed since y-coordinates range from bottom to top

	lastX = xPos;
	lastY = yPos;

	camera.processMouseMovement(xOffset, yOffset);
}