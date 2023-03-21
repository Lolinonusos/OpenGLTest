#include "main.h"


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;


// Time
float deltaTime = 0.0f; // Time between current and last frame
float lastFrame = 0.0f;


float mixValue = 0.2f;


// Camera stuff
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f)); // learnopengl camera
float lastX = SCR_WIDTH / 2;
float lastY = SCR_HEIGHT / 2;
bool firstMouse = true;

// Interactive object
Interactive intObj;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window) {
    const float camSpeed = 2.0f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    //float z = 2 * cos(intObj.position.x) * sin(intObj.position.y);

    // Interact object here
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) { // FORWARD
        //intObj.move(0.0f, 1.0f, 0.0f, deltaTime);
        intObj.translate(UP, deltaTime);
        //intObj.translate(0.0f, 1.0f, z, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) { // BACKWARD
        //intObj.move(0.0f, -1.0f, 0.0f, deltaTime);
        intObj.translate(DOWN, deltaTime);
        //intObj.translate(0.0f, -1.0, z, deltaTime);

    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) { // RIGHT
        //intObj.move(1.0f, 0.0f, 0.0f, deltaTime);
        intObj.translate(RIGHT, deltaTime);
        //intObj.translate(1.0f, 0.0f, z, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) { // LEFT
        //intObj.move(-1.0f, 0.0f, 0.0f, deltaTime);
        intObj.translate(LEFT, deltaTime);
        //intObj.translate(-1.0f, 0.0f, z, deltaTime);
    }

    // Camera here
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { // FORWARD
        //camPos += camSpeed * camFront;
        //camera.translate(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { // BACKWARD
        //camera.translate(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { // RIGHT
        //camera.translate(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { // LEFT
        //camera.translate(LEFT, deltaTime);
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
    Shader ourShader("firstTex.vs", "firstTex.fs");

    Texture helene("Helene.png", GL_TEXTURE_2D);
    ourShader.use();
    helene.texUnit(ourShader, "texture0", 0);
    //glm::vec3 cubePositions[] = {
    //glm::vec3(0.0f,  0.0f,  0.0f),
    //glm::vec3(2.0f,  5.0f, -15.0f),
    //glm::vec3(-1.5f, -2.2f, -2.5f),
    //glm::vec3(-3.8f, -2.0f, -12.3f),
    //glm::vec3(2.4f, -0.4f, -3.5f),
    //glm::vec3(-1.7f,  3.0f, -7.5f),
    //glm::vec3(1.3f, -2.0f, -2.5f),
    //glm::vec3(1.5f,  2.0f, -2.5f),
    //glm::vec3(1.5f,  0.2f, -1.5f),
    //glm::vec3(-1.3f,  1.0f, -1.5f)
    //};
    renderLoop render;
    render.initialize();

    XYZ xyz;
    xyz.init();

  

    //cube.init();

    intObj.init();
    //

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
        
        //// Background colour
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        ////// Clean the back buffer and assign the new color to it
        //glClear(GL_COLOR_BUFFER_BIT);
        ////// Clear depth buffer
        //glClear(GL_DEPTH_BUFFER_BIT);
        //// Can be written together like this
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

