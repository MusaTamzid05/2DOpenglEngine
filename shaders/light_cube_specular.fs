#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos; 

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 viewPos;

uniform float specularStrength;

void main() {

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir , norm);
    float spec = pow(max(dot(viewDir , reflectDir) , 0.0) , 32);
    vec3 specular = specularStrength * spec * lightColor;

 
    vec3 result = specular * objectColor;

    FragColor = vec4(result , 1.0f);
}
