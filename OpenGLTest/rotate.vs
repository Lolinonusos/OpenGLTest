#version 330 core

// Positions/ coordinates
layout (location = 0) in vec3 aPos;

// Colours
//layout (location = 1) in vec3 aColour;

// Texture coordinates
layout (location = 1) in vec2 aTexCoord;


// Outputs colour for the frag shader
//out vec3 ourColour;

// Outputs texture coordinates to the frag shader
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Outputs the positions/ coordinates of all vertices
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    // Assigns the colours from the vertec data to "ourColour"
    //ourColour = aColour;
    
    // Assigns the texture coordinates from the vertex data to "texCoord"
    texCoord = vec2(aTexCoord.x, aTexCoord.y);
}