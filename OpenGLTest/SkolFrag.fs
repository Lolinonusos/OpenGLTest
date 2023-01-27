#version 330 core
out vec4 fragmentColor;     //color sent to fragment on screen

in vec4 color;              //color received from the pipeline (and vertex shader)

void main() {
   //color given to current fragment (pixel)
   //fragmentColor = vec4(1,0,0,0);
   fragmentColor = color;   
}
