#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <cmath>

#include "shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

#include "vertex.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;


// Time
float deltaTime = 0.0f; // Time between current and last frame
float lastFrame = 0.0f;


float mixValue = 0.2f;


// Camera stuff
glm::vec3 camPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 camFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 camUp = glm::vec3(0.0f, 1.0f, 0.0f);

float yaw{ -90.0f }; // Starts looking rowards negative z-axis
float pitch{};
float roll{};
float lastX = SCR_WIDTH / 2;
float lastY = SCR_HEIGHT / 2;
bool firstMouse = true;


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window) {
    const float camSpeed = 2.0f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { // FORWARD
        camPos += camSpeed * camFront;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { // BACKWARD
        camPos -= camSpeed * camFront;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { // RIGHT
        camPos += glm::normalize(glm::cross(camFront, camUp)) * camSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { // LEFT
        camPos -= glm::normalize(glm::cross(camFront, camUp)) * camSpeed;
    }


    /*if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        mixValue += 0.001f;
        if (mixValue >= 1.0f) {
            mixValue = 1.0f;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        mixValue -= 0.001f;
        if (mixValue <= 0.0f) {
            mixValue = 0.0f;
        }
    }*/
}

void mouse_callback(GLFWwindow*, double xPos, double yPos) {
    std::cout << "Mouse x:" << xPos << "    y:" << yPos << std::endl;
    if (firstMouse) {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }

    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos;// reversed since y-coordinates range from bottom to top
    lastX = xPos;
    lastY = yPos;

    const float sensitivity = 0.01;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (pitch > 89.0f) {
        pitch = 89.0f;
    }
    if (pitch < -89.0) {
        pitch = -89.0;
    }

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camFront = glm::normalize(direction);
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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Skrankel Rankel", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Captures the mouse cursor within the center the window 
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // build and compile our shader program
    // ------------------------------------
    //Shader ourShader("firstTexVertShader.vs", "firstTexFragShader.fs"); // you can name your shader files however you like
    Shader ourShader("rotate.vs", "firstTexFragShader.fs"); // you can name your shader files however you like


    // set up vertex data (and buffer(s)) and configure vertex attributes
    //float vertices[] = {
    //    // Positions         // Colours         // Texture
    //    //  x      y     z      r     g     b      u     v
    //     0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,    // bottom right
    //     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,    // bottom left
    //    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,    // top 
    //    -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f
    //};
    //unsigned int indices[] = {  // note that we start from 0!
    //     0, 2, 1,
    //     0, 3, 2
    //};
    float boxVerts[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };
    glm::vec3 cubePositions[] = {
    glm::vec3(0.0f,  0.0f,  0.0f),
    glm::vec3(2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f,  2.0f, -2.5f),
    glm::vec3(1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    VAO boxVAO;
    boxVAO.bind();

    VBO boxVBO(boxVerts, sizeof(boxVerts));
   
    boxVAO.linkAttrib(boxVBO, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    boxVAO.linkAttrib(boxVBO, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    
   /* boxVAO.unbind();
    boxVBO.unbind();*/

    //VAO vao;
    //vao.bind();
    //
    //VBO vbo(vertices, sizeof(vertices));
    //EBO ebo(indices, sizeof(indices));
    //
    //vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    //vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    //vao.linkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    //// Unbind everything
    //vao.unbind();
    //vbo.unbind();
    //ebo.unbind();
    // 
    Texture helene("skeet (1).png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    ourShader.use();
    ourShader.setInt("tex0", 0);
    
    //helene.texUnit(ourShader, "texture0", 0);
    
    
    // Change how triangles are drawn
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Full triangles
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Wire-Frame
    
    // Projection is how much "zoomed" out the camera should be
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
    ourShader.setMat4("projection", projection);
    //glm::vec4 vec(1.0, 0.0f, 0.0f, 0.0f);
    
    glEnable(GL_DEPTH_TEST);
    
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame; // Time between current frame and last frame
        lastFrame = currentFrame; // Time of last frame
     

        
        // input
        processInput(window);
    
        glfwSetCursorPosCallback(window, mouse_callback);

        // Background colour
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Clean the back buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);
        // Clear depth buffer
        glClear(GL_DEPTH_BUFFER_BIT);
        // Can be written together like this
         
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        helene.bind();
      
        // Which shader program we will use
        ourShader.use();
    
        
    
        // Initialize the matrixes to be an identity matrix 
        glm::mat4 view = glm::mat4(1.0f);
        
        // Positive x is to the right on the the screen
        // Positive Y is upwards on the screen
        // Positive Z is out from the screen
        //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -30.0f));
        //view = glm::rotate(view, glm::radians(-35.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
        
        // This block makes camere move in a circle around 0x, 0y, 0z.
        //const float radius{ 10.0f }; // How big circle the camera should spin in
        //float camX = sin(glfwGetTime()) * radius;
        //float camY = cos(glfwGetTime()) * radius;
        //view = glm::lookAt(glm::vec3(camX, 0.0f, camY),
        //                   glm::vec3(0.0f, 0.0f, 0.0f),
        //                   glm::vec3(0.0f, 1.0f, 0.0f));

        view = glm::lookAt(camPos, camPos + camFront, camUp);

        //int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        //int viewLoc = glGetUniformLocation(ourShader.ID, "view");
        //int projectionLoc = glGetUniformLocation(ourShader.ID, "projection");

        ourShader.setMat4("view", view);

        //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        //glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        //ourShader.setMat4("projection", projection);


        //model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        ////std::cout << "W = " << vec.w << "  X = " << vec.x << "  Y = " << vec.y << "  Z = " << vec.z << std::endl;
    
        //unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        //glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));
    
    
    
        //float timeVal = glfwGetTime();
        // Sine function:
        // a * sin(x * b) + c
        // a = amplitude, controls size of sine wave
        // b = periodicity, controls frequency/speed of sine wave
        // c = offset, puts a physical offset on the sine wave
    
        //float xMove = 0.5f * sin(timeVal);
        //float yMove = 0.5f * sin(timeVal);
        //ourShader.setFloat("xMove", xMove);
        //ourShader.setFloat("yMove", yMove);
        //ourShader.setFloat("mixValue", mixValue); // Expose the variable to the shader files
        
        // Binds texture so that it appears in render



        
        boxVAO.bind();
        
        for (int i = 0; i < 10; i++) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * 1 + i * 2;
            model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(0.5f, 1.0f, 0.0f));
            ourShader.setMat4("model", model);
            //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        
        
        //vao.bind();
        //glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
    
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // optional: de-allocate all resources once they've outlived their purpose:
    boxVAO.remove();
    boxVBO.remove();
    
    
  /*  vao.remove();
    vbo.remove();
    ebo.remove();*/
    
    // Texture
    helene.remove();
    
    // Shader program
    ourShader.remove();
    
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

