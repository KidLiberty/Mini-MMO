//
//  fragement_shader.glsl
//  Mini MMO
//
//  Created by Brandon Stone on 12/19/24.
//

#version 330 core

in vec3 vertexColor; // Input color from vertex shader
out vec4 fragColor;  // Output color of the fragment

void main() {
    fragColor = vec4(vertexColor, 1.0); // Use vertex color with full opacity
}
