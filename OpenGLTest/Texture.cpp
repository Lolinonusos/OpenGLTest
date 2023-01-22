#include "texture.h"

oldTexture::oldTexture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
	
    // Assigns texture type to the texture object
    type = texType;

    stbi_set_flip_vertically_on_load(true);

    // Image width, height and colour channels
    int imgWidth, imgHeight, numColChannels;
    
    // Read image from file
    unsigned char* bytes = stbi_load(image, &imgWidth, &imgHeight, &numColChannels, 0);
    
    // Generates an OpenGL texture object
    glGenTextures(1, &ID);
    // Assigns the texture to a Texture Unit
    glActiveTexture(slot);
    glBindTexture(texType, ID);

    // GL_REPEAT: The default behavior for textures.Repeats the texture image.
    // GL_MIRRORED_REPEAT : Same as GL_REPEAT but mirrors the image with each repeat.
    // GL_CLAMP_TO_EDGE : Clamps the coordinates between 0 and 1. The result is that higher coordinates become clamped to the edge, resulting in a stretched edge pattern.
    // GL_CLAMP_TO_BORDER : Coordinates outside the range are now given a user - specified border color.

    // Set texture wrapping options on the currently bound texture object
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering options on the currently bound texture object
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (bytes) {
        // Assigns the image to the OpenGL Texture object
        glTexImage2D(texType, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, bytes);
        // Generates MipMaps
        glGenerateMipmap(texType);
    }
    else {
        std::cout << "Failed to load image texture" << std::endl;
    }

    // Freeing image memory
    stbi_image_free(bytes);
    glBindTexture(texType, ID);

}

void oldTexture::texUnit(Shader &shader, const char* uniform, unsigned int unit) {
    glUniform1i(glGetUniformLocation(shader.ID, uniform), unit);
    // Use our shader program
    shader.use();

    //glUniform1i(glGetUniformLocation(shader.ID, uniform), unit);

    //ourShader.setInt(uniform, unit);

    // Gets the location of the uniform
    //GLuint texUni = glGetUniformLocation(shader.ID, uniform);
    // Shader needs to be activated before changing the value of a uniform
    //shader.use();
    // Sets the value of the uniform
    //glUniform1i(texUni, unit);
}

void oldTexture::bind() {
    glBindTexture(type, ID);
}

void oldTexture::unbind() {
    glBindTexture(type, 0);
}

void oldTexture::remove() {
    glDeleteTextures(1, &ID);
}