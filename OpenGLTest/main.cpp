#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <iostream>
#include <cmath>

#include "shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
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
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------
    Shader ourShader("firstTexVertShader.vs", "firstTexFragShader.fs"); // you can name your shader files however you like

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // Positions         // Colours         // Texture
        //  x      y     z      r     g     b      u     v
         0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,    // bottom right
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,    // bottom left
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,    // top 
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f
    };
    unsigned int indices[] = {  // note that we start from 0!
         0, 2, 1,
         0, 3, 2
    };

    VAO vao;
    vao.bind();

    VBO vbo(vertices, sizeof(vertices));
    EBO ebo(indices, sizeof(indices));

    vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.linkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    // Unbind everything
    vao.unbind();
    vbo.unbind();
    ebo.unbind();
     
    
    // Texture
    unsigned int texture;
    glGenTextures(1, &texture);
    // Binding texture
    glBindTexture(GL_TEXTURE_2D, texture);
    
    // Set texture wrapping and filtering options on the currently bound texture object
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //glActiveTexture(GL_TEXTURE0);

    // Load and generate texture
    int imgWidth, imgHeight, numColChannels;
    unsigned char* bytes = stbi_load("Helene.png", &imgWidth, &imgHeight, &numColChannels, 0);
    if (bytes) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load image texture" << std::endl;
    }

    // Freeing image memory
    stbi_image_free(bytes);

    //unsigned int VBO, VAO;
    //glGenVertexArrays(1, &VAO);
    //glGenBuffers(1, &VBO);

    //// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    //glBindVertexArray(VAO);

    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //// position attribute
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);
    //
    //// color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);

    //// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    //// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    //glBindVertexArray(0);


    // Change how triangles are drawn
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Full triangles
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Wire-Frame


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // Background colour
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Clean the back buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);

        // Use our shader program
        ourShader.use();

        glBindTexture(GL_TEXTURE_2D, texture);
        vao.bind();

        float timeVal = glfwGetTime();

        // Sine function:
        // a * sin(x * b) + c
        // a = amplitude, controls size of sine wave
        // b = periodicity, controls frequency/speed of sine wave
        // c = offset, puts a physical offset on the sine wave


        float xMove = 0.5f * sin(timeVal);
        float yMove = 0.5f * sin(timeVal);
        ourShader.setFloat("xMove", xMove);
        ourShader.setFloat("yMove", yMove);


       // glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    //glDeleteVertexArrays(1, &VAO);
    //glDeleteBuffers(1, &VBO);

    vao.remove();
    vbo.remove();
    ebo.remove();
    glDeleteTextures(1, &texture);
    
    ourShader.remove();


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

