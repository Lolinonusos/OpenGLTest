#version 330 core

layout(location = 0) in vec3 positionIn;    // 1st attribute buffer = vertex positions
layout(location = 1) in vec3 normalIn;       // 2nd attribute buffer = colors
layout(location = 2) in vec2 uvIn;

out vec3 fragmentPosition; //color sent to rest of pipeline
out vec3 normalTransposed;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {
   fragmentPosition = vec3(model * vec4(positionIn, 1.0));     
   normalTransposed = mat3(transpose(inverse(model))) * normalIn;

   gl_Position = projection * view * model * vec4(positionIn, 1.0);       //calculate the position of the model
}