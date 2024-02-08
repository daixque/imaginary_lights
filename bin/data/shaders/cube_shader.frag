#version 410 core

uniform vec4 color;
out vec4 outputColor;
in vec3 vPos;

void main() {
    float alpha = (0.80 - (vPos.y + 1000) / 2000.f) * 0.5;
    outputColor = vec4(1.0, 1.0, 1.0, alpha); // white color
    //outputColor = color;
}
