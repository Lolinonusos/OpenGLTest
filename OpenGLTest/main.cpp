#include "main.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

// Time
float deltaTime = 0.0f; // Time between current and last frame
float lastFrame = 0.0f;

// Camera stuff
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f)); // learnopengl camera
float lastX = SCR_WIDTH / 2;
float lastY = SCR_HEIGHT / 2;
bool firstMouse = true;

renderLoop render;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window) {
    const float camSpeed = 2.0f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    // Interact object here
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) { // FORWARD
        //intObj.move(0.0f, 1.0f, 0.0f, deltaTime);
        //intObj.translate(UP, deltaTime);
        //intObj.translate(0.0f, 1.0f, z, deltaTime);
        render.objectMap.at("player")->translate(FORWARD, deltaTime);
        //render.objectMap.at("player")->setY(render.terrain->getTerrainHeight(glm::vec2(render.objectMap.at("player")->position.x, render.objectMap.at("player")->position.z)));
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) { // BACKWARD
        //intObj.move(0.0f, -1.0f, 0.0f, deltaTime);
        //intObj.translate(DOWN, deltaTime);
        //intObj.translate(0.0f, -1.0, z, deltaTime);
        render.objectMap.at("player")->translate(BACKWARD, deltaTime);
        //render.objectMap.at("player")->setY(render.terrain->getTerrainHeight(glm::vec2(render.objectMap.at("player")->position.x, render.objectMap.at("player")->position.z)));
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) { // RIGHT
        //intObj.move(1.0f, 0.0f, 0.0f, deltaTime);
        //intObj.translate(RIGHT, deltaTime);
        //intObj.translate(1.0f, 0.0f, z, deltaTime);
        render.objectMap.at("player")->translate(RIGHT, deltaTime);
        //render.objectMap.at("player")->setY(render.terrain->getTerrainHeight(glm::vec2(render.objectMap.at("player")->position.x, render.objectMap.at("player")->position.z)));
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) { // LEFT
        //intObj.move(-1.0f, 0.0f, 0.0f, deltaTime);
        //intObj.translate(LEFT, deltaTime);
        //intObj.translate(-1.0f, 0.0f, z, deltaTime);
        render.objectMap.at("player")->translate(LEFT, deltaTime);
        //render.objectMap.at("player")->setY(render.terrain->getTerrainHeight(glm::vec2(render.objectMap.at("player")->position.x, render.objectMap.at("player")->position.z)));
    }


    // Camera here
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { // FORWARD
        render.camera.translate(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { // BACKWARD
        render.camera.translate(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { // RIGHT
        render.camera.translate(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { // LEFT
        render.camera.translate(LEFT, deltaTime);
    }

    // Solid by default
    // Wireframe when pressing space
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Wireframe
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Filled triangles

    }
}

void mouse_callback(GLFWwindow*, double xPosIn, double yPosIn) {

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

    render.camera.processMouseMovement(xOffset, yOffset);
    //camera.processMouseMovement(xOffset, yOffset);
}


void scroll_callback(GLFWwindow* window, double xOffset, double yOffset) {
    //camera.ProcessMouseScroll(static_cast<float>(yOffset));
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


int main() {
    std::cout << "hello world!" << std::endl;
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Skrankel Rankel Engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Captures the mouse cursor within the center the window 
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // build and compile our shader program
    //Shader ourShader("firstTexVertShader.vs", "firstTexFragShader.fs"); 
    // you can name your shader files however you like
    //Shader ourShader("SkolVert.vs", "SkolFrag.fs"); 
    //Shader ourShader("firstTex.vs", "firstTex.fs");
    //Shader lightShader("lightVert.vs", "lightFrag.fs");


    render.initialize();

    //// Oblig 2
    //changeScene cs;
    //cs.init();
    //cs.setPosition(glm::vec3(1.0f, 0.0f, 0.0f));
    ////cube.readFile("Data.txt");


    //std::vector<Trophy> collision;
    //collision.push_back(Trophy{});
    //collision.push_back(Trophy{});

    //for (int i = 0; i < collision.size(); i++) {
    //    collision[i].init();
    //}

     
    //collision[1].setPosition(-1.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);

    // Initializing render matrixes as identity matrixes
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 model = glm::mat4(1.0f);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame; // Time between current frame and last frame
        lastFrame = currentFrame; // Time of last frame
        
        // input
        processInput(window);

        render.render();
        


        //glActiveTexture(GL_TEXTURE0);
        //helene.bind();
        ////
        ////// Which shader program we will use
        //ourShader.use();
    
        //// Projection matrix
        //projection = glm::perspective(glm::radians(camera.zoom), (float)(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
        //ourShader.setMat4("projection", projection);
        //
    
        //// View matrix
        //view = camera.getViewMatrix();
        //ourShader.setMat4("view", view);
        //intObj.draw(ourShader);
        //xyz.draw(ourShader);
        //
        //int ma

        // graph.draw();

        //for (int i = 0; i < points.size(); i++) {
        //    //points[i].draw();
        //}
        //octa.renderVal = 0;
        
       // if (ballIndex < vartAmount && npcLeft) {
       //     if (graph1) {
       //         temp = matteFireFireFire.getVertexPosition(ballIndex);
       //     }
       //     else if (!graph1) {
       //         temp = matteFireSeksTi.getVertexPosition(ballIndex);
       //     }

       //     octa.setPosition(-temp.x, -temp.y, temp.z);
       //     std::cout << ballIndex << std::endl;
       //     ballIndex += 1;
       //     if (ballIndex >= vartAmount - 1) {
       //         //ballIndex = vartAmount;
       //         npcLeft = false;
       //     }
       // }
       // else if (ballIndex >= 0 && !npcLeft) {
       //     if (graph1) {
       //         temp = matteFireFireFire.getVertexPosition(ballIndex);
       //     }
       //     else if (!graph1) {
       //         temp = matteFireSeksTi.getVertexPosition(ballIndex);
       //     }

       // octa.setPosition(-temp.x, -temp.y, temp.z);
       // ballIndex--;
       //     if (ballIndex <= 0) {
       //         ballIndex = 0;
       //         npcLeft = true;
       //     }
       // }
       //// }

       // intObj.collider();
       // //octa.collider();
       // //intObj.checkCollision(&octa);
       // //cs.draw();
       // for (int i = 0; i < collision.size(); i++) {
       //     collision[i].checkCollision(&intObj);
       // }

       // octa.draw(ourShader);
       // //xyz.setPosition(glm::vec3(1.0f, 0.0f, -0.5f));
       // matteFireFireFire.draw(ourShader);
       // matteFireSeksTi.draw(ourShader);
        //std::cout << intObj.position.x << " " << intObj.position.y << " " << intObj.position.z << std::endl;
     /*   for (int i = 0; i < collision.size(); i++) {
            collision[0].draw(ourShader);
        }*/
        //cs.checkCollision(&intObj, &camera);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

