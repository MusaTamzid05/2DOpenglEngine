#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos; 

uniform vec3 lightColor;
uniform vec3 objectColor;

void main() {

    float ambientStrength = 0.7f;
    vec3 ambient = ambientStrength * lightColor;
    vec3 result = ambient * objectColor;

    FragColor = vec4(result , 1.0f);
}
