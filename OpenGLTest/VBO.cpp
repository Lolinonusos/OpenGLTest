#include "VBO.h"

//VBO::VBO(std::vector<float> vertices, GLsizeiptr size)
VBO::VBO(std::vector<Vertex>& vertices) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW); // For non-class
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