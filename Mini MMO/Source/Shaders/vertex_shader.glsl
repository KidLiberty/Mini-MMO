//
//  vertex_shader.glsl
//  Mini MMO
//
//  Created by Brandon Stone on 12/19/24.
//

#version 330 core

layout(location = 0) in vec3 position; // Input vertex position
layout(location = 1) in vec3 color;    // Input vertex color

out vec3 vertexColor; // Output color to fragment shader

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0); // Transform vertex
    vertexColor = color; // Pass the color to the fragment shader
}
