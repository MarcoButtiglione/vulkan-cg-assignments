#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec3 lightColor;
	vec3 eyePos;
} gubo;

layout(binding = 3) uniform sampler2D texel;

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

/*
The shader will be applied to a scene where the diffuse illumination has been baked (recorded) into a texture. 
The scene will use just an ambient term plus specular Blinn. 
The scene will use a directional light.

In the second scene, binding 1 will contain a combined image sampler with a 2D texture defining the
ambient color of the object, and the uniform block in binding 2 will contain the following data to
support a directional light and the position of the viewer:
• vec3 lightDir -> the direction of the light.
• vec3 lightColor -> the basic color of the light.
• vec3 eyePos -> the position of the viewer.
*/

vec3 AmbientLighting (vec3 la, vec3 ma){
	/*
	AmbientLighting = Lamb

	la = light ambient color
	ma = ambient light reflection color
	*/
	vec3 Lamb = la * ma;
	return Lamb;
}
vec3 BlinnReflection (vec3 ms, vec3 nx,vec3 lx,vec3 wr,  float gamma){
	/*
	BlinnReflection = fSpecular

	ms = specular color of the object
	nx = unitary normal vector to the surface (normalize(fragNorm))
	lx = light direction
	wr = direction from which the object is being observed (vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);)
	gamma = specular power, diffusion of the highlight regions (greater is gamma,
	smaller is the highlight, and more shiny the object appears to be)
	*/
	vec3 fSpecular = ms * pow(clamp(dot(nx,normalize(lx+wr)),0.0f,1.0f),gamma);
	return fSpecular;
}

void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	//Diffuse color
	vec3 AmbCol = texture(texSampler, fragTexCoord).rgb;
	//Specular color
	vec3 SpecCol = texture(texel, fragTexCoord).rgb;
	//Specular power 
	float gamma = texture(texel, fragTexCoord).a * 200.0f;

	//Light model
	vec3 L_directional = gubo.lightColor;
	vec3 lx_directional = gubo.lightDir;

	//AmbientLighting
	vec3 Lamb = AmbientLighting(
		gubo.lightColor,
		AmbCol
	);

	//BRDF functions
	vec3 fSpecular = BlinnReflection(
		SpecCol,
		Norm,
		lx_directional,
		EyeDir,
		gamma
	);

	//Rendering equation
	vec3 L = L_directional*(fSpecular)+Lamb;


	outColor = vec4(clamp(L,vec3(0.0f), vec3(1.0f)), 1.0f);	
}