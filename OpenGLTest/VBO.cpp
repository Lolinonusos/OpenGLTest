#include "VBO.h"

//VBO::VBO(std::vector<float> vertices, GLsizeiptr size)
VBO::VBO(float* vertices, GLsizeiptr size) 
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); // For non-class
   // glBufferData(GL_ARRAY_BUFFER, size, &vertices, GL_STATIC_DRAW); // For class

}

void VBO::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::remove() {
    glDeleteBuffers(1, &ID);
}