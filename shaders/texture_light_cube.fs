#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


struct Material {
    
    float shininess;
    vec3 ambient;
    sampler2D diffuse;
    vec3 specular;
};

in vec2 TexCoords;

uniform Material material;
uniform Light light;
uniform vec3 viewPos;


void main() {

    vec3 ambient = light.ambient * vec3(texture(material.diffuse , TexCoords));

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm , lightDir) , 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse , TexCoords));

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir , norm);
    float spec = pow(max(dot(viewDir , reflectDir) , 0.0) , material.shininess);
    vec3 specular = light.specular * (spec * material.specular);


    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result , 1.0);
}