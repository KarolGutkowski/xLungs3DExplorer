//#shader vertex
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;


out vec3 normal;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    normal = mat3(transpose(inverse(model))) * aNormal;
    fragPos = vec3(model * vec4(aPos, 1.0));
}

//#shader fragment
#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;

uniform vec3 color;

struct DirectionalLight
{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 viewPos;

vec3 CalculateDirectionalLight(DirectionalLight lights[2], vec3 norm, vec3 fragPos, vec3 viewDir, vec3 color);

void main()
{
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPos - fragPos);

    DirectionalLight dirLights[2]; // for now im creatint the light in shader

    dirLights[0].direction = vec3(-0.2f, -1.0f, -0.3f);
    dirLights[0].ambient = vec3(0.2f);
    dirLights[0].diffuse = vec3(1.0f);
    dirLights[0].specular = vec3(1.0f);

    dirLights[0].direction = vec3(0.2f, -1.0f, 0.3f);
    dirLights[0].ambient = vec3(0.2f);
    dirLights[0].diffuse = vec3(1.0f);
    dirLights[0].specular = vec3(1.0f);

    FragColor = vec4(CalculateDirectionalLight(dirLights, norm, fragPos, viewDir, color), 1.0f);
}


vec3 CalculateDirectionalLight(DirectionalLight lights[2], vec3 norm, vec3 fragPos, vec3 viewDir, vec3 color)
{
    vec3 ambient = lights[0].ambient * color;

    vec3 diffuse = vec3(0.0f);

    vec3 specular = vec3(0.0f);

    for (int i = 0; i < 2; i++)
    {
        vec3 lightDir = normalize(-lights[i].direction);
        float diff = max(dot(norm, lightDir), 0.0);

        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 65.0f);

        diffuse += lights[i].diffuse * diff * color;
        specular += lights[i].specular * spec * vec3(1.0f);
    }


    return ambient + diffuse + specular;
}