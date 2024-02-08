#version 410

layout (location = 0) in vec3 aPos;
out vec3 vPos;

uniform mat4 modelViewProjectionMatrix;
uniform float time;
in vec4 position;
in float vertexIndex;

void main() {
    gl_Position = modelViewProjectionMatrix * position;
    vec3 p;
    p.x = gl_Position.x;
    p.y = gl_Position.y;
    p.z = gl_Position.z;
    vPos = p;
}
