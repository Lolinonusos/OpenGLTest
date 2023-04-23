#include "renderLoop.h"

renderLoop::renderLoop() {



}


void renderLoop::initialize()
{
	// Shaders to be used
	shaders.push_back(new Shader("tekstur", "firstTex.vs", "firstTex.fs")); // Index 0 is texture shader
	shaders.push_back(new Shader("skole","SkolVert.vs", "SkolFrag.fs")); // Index 0 is texture shader
	shaders.push_back(new Shader("hoyde", "height.vs", "height.fs")); // index 2 is for height map
	shaders.push_back(new Shader("lysShader", "light.vs", "light.fs")); // Index 3 is light shader

	// Objects to draw
	objects.push_back(new Interactive{ shaders[0], "player" });
	objects.push_back(new Cube{ shaders[0], "Hlene" });
	objects.push_back(new Cube{ shaders[0], "2"});
	objects.push_back(new Light{ shaders[3], "lys" });
	objects.push_back(new Plane{ shaders[1], "plan" });
	
	//objects.push_back(
	terrain = new HeightMap{ "Norge.png", shaders[1], "terrain" };

	for (auto i = objects.begin(); i != objects.end(); i++) {
		objectMap.insert(std::pair<std::string, VisObject*>{(*i)->getName(), (*i)});
		//std::cout << objectMap.size();
	}


	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);

	for (auto i = objectMap.begin(); i != objectMap.end(); i++) {
		(*i).second->init();
	}
	terrain->init();

	textures.push_back(new Texture("screenshot.png", GL_TEXTURE_2D));
	//textures.push_back(new Texture("Helene.png", GL_TEXTURE_2D));
	
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

	// Activate texture
	glActiveTexture(GL_TEXTURE0);
	textures[0]->bind();
	
	// Lag tick funksjon
	// objectMap.tick(deltaTime);

	for (unsigned int i = 0; i < shaders.size(); i++) {
		
		// Which shader program we will use
		shaders[i]->use();
		
		// Projection matrix
		projection = glm::perspective(glm::radians(camera.zoom), (float)(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
		shaders[i]->setMat4("projection", projection);

		// View matrix
		view = camera.getViewMatrix();
		shaders[i]->setMat4("view", view);

		shaders[i]->setVec3("cameraPosition", camera.position);
		shaders[i]->setVec3("lightPosition", objectMap.at("player")->position + glm::vec3(0.0f, 2.0f, 0.0f));
	}
	

	//std::cout << objectMap.at("player")->position.x << " " << objectMap.at("player")->position.y << " " << objectMap.at("player")->position.z << std::endl;
	glm::vec3 playerPos = objectMap.at("player")->position;
	objectMap.at("player")->setY(terrain->getTerrainHeight(glm::vec2(playerPos.x, playerPos.z)));

	// draw loop
	for (auto& obj : objectMap) {
		obj.second->draw();
		if (obj.second->getName() == "2") {
			obj.second->setPosition(glm::vec3(2.0f, 2.0f, 0.0f));
			//std::cout << "hurrah";
		}
	}
	terrain->draw();
	//objectMap.at(std::string("terrain"))->setTerrainHeight(glm::vec2());
	//glfwSwapBuffers(window);
	//glfwPollEvents();
}

renderLoop::~renderLoop() {
	for (auto& obj : objectMap) {
		delete obj.second;
	}
}

void renderLoop::processInput()
{

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