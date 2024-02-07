#version 410 core

uniform vec4 color;
out vec4 outputColor;

void main() {
    //outputColor = vec4(1.0, 1.0, 1.0, 0.3); // white color
    outputColor = color;
}
