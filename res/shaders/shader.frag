#version 330 core
in vec3 TexCoords;
out vec4 FragColor;

uniform samplerCube cubemapTexture;

void main() {
    FragColor = texture(cubemapTexture, TexCoords);
}
