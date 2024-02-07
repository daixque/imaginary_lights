#version 410

uniform mat4 modelViewProjectionMatrix;
uniform float time;
in vec4 position;
in float vertexIndex;

float random(vec2 st) {
    vec2 a = vec2(12.9898,78.233);
    st = fract(st * a);
    return fract(sin(dot(st, a))* 43758.5453);
}

void main() {
    // Calculate the wave
    float wave =
        (sin(time * 1 + position.x * 0.4 + random(vec2(position.z, position.x))) + cos(time * 1 + position.z * 0.5)) * 2.0
        + cos(time * 1.5 + position.x + random(vec2(position.x, position.z)) * 0.2 + random(vec2(position.z, position.x)))
        + random(vec2(position.x, position.z)) * 3;

    // Add the wave to the y-coordinate of the position
    vec4 newPosition = position;
    newPosition.y += wave;

    // Transform the position to clip space
    gl_Position = modelViewProjectionMatrix * newPosition;
}
