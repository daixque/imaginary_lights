#version 410 core

uniform sampler2D imageTexture;
uniform vec2 resolution;
uniform vec4 color;
out vec4 outputColor;
in vec4 vColor;

void main() {
    //outputColor = vec4(1.0, 1.0, 1.0, 0.3); // white color
    outputColor = color;
//    vec4 texColor = texture(imageTexture, gl_FragCoord.xy / resolution.xy);
//    outputColor = color * texColor;  // Use the color data and texture color
}
