#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

out vec3 ourPosition;

uniform float xMove;

uniform float yMove;

void main()
{
    // positive/negative y flips up or down 
    gl_Position = vec4(aPos.x + xMove, aPos.y + yMove, aPos.z, 1.0);
    ourColor = aColor;
    ourPosition = aPos;
}