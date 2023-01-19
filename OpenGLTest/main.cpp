#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


#include <iostream>
#include <cmath>

#include "mesh.h"
#include "shader.h"

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
float fov{ 45.0f };

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
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


void scroll_callback(GLFWwindow* window, double xOffset, double yOffset) {
    fov -= (float)yOffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f) {
        fov = 45.0f;
         std::cout << "Scrollin'" << std::endl;
    }
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
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Captures the mouse cursor within the center the window 
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


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
    Vertex vert1;
    Vertex vert2;
    Vertex vert3;
    Vertex vert4;
    Vertex vert5;
    Vertex vert6;

    Vertex vert7;
    Vertex vert8;
    Vertex vert9;
    Vertex vert10;
    Vertex vert11;
    Vertex vert12;

    Vertex vert13;
    Vertex vert14;
    Vertex vert15;
    Vertex vert16;
    Vertex vert17;
    Vertex vert18;

    Vertex vert19;
    Vertex vert20;
    Vertex vert21;
    Vertex vert22;
    Vertex vert23;
    Vertex vert24;

    Vertex vert25;
    Vertex vert26;
    Vertex vert27;
    Vertex vert28;
    Vertex vert29;
    Vertex vert30;

    Vertex vert31;
    Vertex vert32;
    Vertex vert33;
    Vertex vert34;
    Vertex vert35;
    Vertex vert36;

     vert1.position = glm::vec3(-0.5f, -0.5f, -0.5f);     vert1.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert1.texCoord = glm::vec2(0.0f, 0.0f);
     vert2.position = glm::vec3( 0.5f, -0.5f, -0.5f);     vert2.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert2.texCoord = glm::vec2(1.0f, 0.0f);
     vert3.position = glm::vec3( 0.5f,  0.5f, -0.5f);     vert3.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert3.texCoord = glm::vec2(1.0f, 1.0f);
     vert4.position = glm::vec3( 0.5f,  0.5f, -0.5f);     vert4.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert4.texCoord = glm::vec2(1.0f, 1.0f);
     vert5.position = glm::vec3(-0.5f,  0.5f, -0.5f);     vert5.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert5.texCoord = glm::vec2(0.0f, 1.0f);
     vert6.position = glm::vec3(-0.5f, -0.5f, -0.5f);     vert6.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert6.texCoord = glm::vec2(0.0f, 0.0f);
                                                          
     vert7.position = glm::vec3(-0.5f, -0.5f,  0.5f);     vert7.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert7.texCoord = glm::vec2(0.0f, 0.0f);
     vert8.position = glm::vec3( 0.5f, -0.5f,  0.5f);     vert8.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert8.texCoord = glm::vec2(1.0f, 0.0f);
     vert9.position = glm::vec3( 0.5f,  0.5f,  0.5f);     vert9.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert9.texCoord = glm::vec2(1.0f, 1.0f);
    vert10.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert10.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert10.texCoord = glm::vec2(1.0f, 1.0f);
    vert11.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert11.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert11.texCoord = glm::vec2(0.0f, 1.0f);
    vert12.position = glm::vec3(-0.5f, -0.5f,  0.5f);    vert12.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert12.texCoord = glm::vec2(0.0f, 0.0f);

    vert13.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert13.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert13.texCoord = glm::vec2(1.0f, 0.0f);
    vert14.position = glm::vec3(-0.5f,  0.5f, -0.5f);    vert14.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert14.texCoord = glm::vec2(1.0f, 1.0f);
    vert15.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert15.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert15.texCoord = glm::vec2(0.0f, 1.0f);
    vert16.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert16.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert16.texCoord = glm::vec2(0.0f, 1.0f);
    vert17.position = glm::vec3(-0.5f, -0.5f,  0.5f);    vert17.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert17.texCoord = glm::vec2(0.0f, 0.0f);
    vert18.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert18.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert18.texCoord = glm::vec2(1.0f, 0.0f);

    vert19.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert19.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert19.texCoord = glm::vec2(1.0f, 0.0f);
    vert20.position = glm::vec3( 0.5f,  0.5f, -0.5f);    vert20.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert20.texCoord = glm::vec2(1.0f, 1.0f);
    vert21.position = glm::vec3( 0.5f, -0.5f, -0.5f);    vert21.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert21.texCoord = glm::vec2(0.0f, 1.0f);
    vert22.position = glm::vec3( 0.5f, -0.5f, -0.5f);    vert22.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert22.texCoord = glm::vec2(0.0f, 1.0f);
    vert23.position = glm::vec3( 0.5f, -0.5f,  0.5f);    vert23.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert23.texCoord = glm::vec2(0.0f, 0.0f);
    vert24.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert24.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert24.texCoord = glm::vec2(1.0f, 0.0f);
    
    vert25.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert25.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert25.texCoord = glm::vec2(0.0f, 1.0f);
    vert26.position = glm::vec3( 0.5f, -0.5f, -0.5f);    vert26.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert26.texCoord = glm::vec2(1.0f, 1.0f);
    vert27.position = glm::vec3( 0.5f, -0.5f,  0.5f);    vert27.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert27.texCoord = glm::vec2(1.0f, 0.0f);
    vert28.position = glm::vec3( 0.5f, -0.5f,  0.5f);    vert28.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert28.texCoord = glm::vec2(1.0f, 0.0f);
    vert29.position = glm::vec3(-0.5f, -0.5f,  0.5f);    vert29.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert29.texCoord = glm::vec2(0.0f, 0.0f);
    vert30.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert30.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert30.texCoord = glm::vec2(0.0f, 1.0f);
    
    vert31.position = glm::vec3(-0.5f,  0.5f, -0.5f);    vert31.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert31.texCoord = glm::vec2(0.0f, 1.0f);
    vert32.position = glm::vec3( 0.5f,  0.5f, -0.5f);    vert32.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert32.texCoord = glm::vec2(1.0f, 1.0f);
    vert33.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert33.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert33.texCoord = glm::vec2(1.0f, 0.0f);
    vert34.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert34.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert34.texCoord = glm::vec2(1.0f, 0.0f);
    vert35.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert35.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert35.texCoord = glm::vec2(0.0f, 0.0f);
    vert36.position = glm::vec3(-0.5f,  0.5f, -0.5f);    vert36.normal = glm::vec3(0.0f, 1.0f, 0.0f);   vert36.texCoord = glm::vec2(0.0f, 1.0f);


std::vector<Vertex> verts = {
    vert1, vert2, vert3, vert4, vert5, vert6,

    vert7, vert8,  vert9, vert10, vert11, vert12,

    vert13, vert14, vert15, vert16, vert17, vert18,

    vert19, vert20, vert21, vert22, vert23, vert24,

    vert25, vert26, vert27, vert28, vert29, vert30,

    vert31, vert32, vert33, vert34, vert35, vert36


    };
    float boxVerts[] = {
  

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

    Mesh mesh();

    VAO boxVAO;
    boxVAO.bind();

    VBO boxVBO(verts);
   
    boxVAO.linkAttrib(boxVBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
    boxVAO.linkAttrib(boxVBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
    boxVAO.linkAttrib(boxVBO, 1, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
    
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
    // fov starts at 45.0 radians
    glm::mat4 projection = glm::perspective(glm::radians(fov), (float)(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
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

