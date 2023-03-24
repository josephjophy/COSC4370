#version 330 core
out vec4 color;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

vec3 CalculateDiffuse();

vec3 CalculateSpecular();

void main() {
vec3 specular_component, diffuse_component, final_color;

// Calculate a small constant ambient factor and multiply it by the light and object color
vec3 ambient_factor = (0.13 * lightColor) * objectColor;

// Calculate the specular and diffuse components of the lighting equation for the fragment
specular_component = CalculateSpecular();
diffuse_component = CalculateDiffuse();

// Combine the specular, diffuse, and ambient components to get the final color
final_color = (diffuse_component + specular_component + ambient_factor) * objectColor;

// Set the color of the fragment to the final color with an alpha value of 1.0
color = vec4(final_color, 1.0);
}

// Calculate the diffuse component of the lighting equation for a given fragment
vec3 CalculateDiffuse() {
// Declare variables for the direction of the light and the surface normal
vec3 light_direction, surface_normal;

// Declare a variable to hold the amount of diffusion
float diffusion_amount;

// Normalize the surface normal to get a unit vector
surface_normal = normalize(Normal);

// Normalize the direction of the light to get a unit vector
light_direction = normalize(lightPos - FragPos);

// Compute the amount of diffusion based on the dot product of the surface normal and the light direction
diffusion_amount = max(dot(surface_normal, light_direction), 0.1);

// Multiply the light color by the amount of diffusion to get the final diffuse component
return lightColor * diffusion_amount;
}

// Calculate the specular component of the lighting equation for a given fragment
vec3 CalculateSpecular() {
// Declare variables for the surface normal, direction of the light, view direction,
// reflected light direction, glossiness, and specular intensity
vec3 surface_normal, light_direction, view_direction, reflected_light_direction;
int glossiness_value = 41;
float specular_intensity;

// Normalize the surface normal to get a unit vector
surface_normal = normalize(Normal);

// Normalize the direction of the light to get a unit vector
light_direction = normalize(lightPos - FragPos);

// Normalize the view direction to get a unit vector
view_direction = normalize(viewPos - FragPos);

// Compute the reflected light direction based on the surface normal and direction of the light
reflected_light_direction = reflect(-light_direction, surface_normal);

// Compute the specular intensity based on the dot product of the view direction and
// reflected light direction, raised to the power of the glossiness value
specular_intensity = pow(max(dot(view_direction, reflected_light_direction), 0.0), glossiness_value);

// Multiply the specular intensity by a constant value and the light color to get the
// final specular component of the lighting equation
return specular_intensity * 0.61 * lightColor;
}