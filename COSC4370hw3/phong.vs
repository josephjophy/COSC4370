#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
  // Passes fragment shader
  Normal = normal;


  // Sets position of vertex
  gl_Position =  view * vec4(position, 0.99) * model *projection; 

  // Sets position of the vertex in world coordinates
  FragPos = vec3(model * vec4(position, 0.99) );
} 