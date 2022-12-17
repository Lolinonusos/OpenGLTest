#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

void main()
{
    // positive/negative y flips up or down 
    gl_Position = vec4(aPos.x + 0.6, -aPos.y, aPos.z, 1.0);
    ourColor = aColor;
}