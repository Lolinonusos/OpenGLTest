#version 330 core

// Outputs colours in RGBA
out vec4 FragColour;


// Inputs the colour from the vert shader  
//in vec3 ourColour;

// Inputs the texture coordinates from the vert shader
in vec2 texCoord;


// Gets the texture unit from the main function
uniform sampler2D tex0;


void main()
{
    FragColour = texture(tex0, texCoord);
}