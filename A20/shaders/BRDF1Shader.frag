#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec3 lightPos;
	vec3 lightColor;
	vec4 lightParams;
	vec3 eyePos;
} gubo;

layout(binding = 3) uniform sampler2D texel;

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

/*
This shader will be applied to a Sphere, with different materials on its surface
The scene will use diffuse Lambert with specular Phong
The sphere will be lit with a spot light.

For the first scene, binding 1 will contain a combined image sampler with a 2D texture defining the
diffuse color of the object, and binding 2 will contain the following information in a uniform block to
define the spot light and the position of the viewer:
• vec3 lightDir -> the direction of the light.
• vec3 lightPos -> the position of the light.
• vec3 lightColor -> the basic color of the light.
• vec4 lightParams -> the other parameters of the spot light.
• vec3 eyePos -> the position of the viewer.
The members of lightParams are the following:
• lightParams.x -> a float component containing the cosine of the inner angle.
• lightParams.y -> a float component containing the cosine of the outer angle.
• lightParams.z -> a float component containing the denominator exponent b.
• lightParams.w -> a float component containing the basic distance g.

*/

vec3 LambertReflection( vec3 md, vec3 lx, vec3 nx){
	/*
	LambertReflection = fDiffuse

	md = diffuse color of the object
	lx = light direction
	nx = unitary normal vector to the surface (normalize(fragNorm))

	*/
	vec3 fDiffuse =md*max(dot(lx,nx),0.0f);
	return fDiffuse;
}
vec3 PhongReflection(vec3 ms, vec3 wr, vec3 lx, vec3 nx, float gamma)  {
	/*
	PhongReflection = fSpecular

	ms = specular color of the object
	wr = direction from which the object is being observed (vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);)
	lx = light direction
	nx = unitary normal vector to the surface (normalize(fragNorm))
	gamma = specular power, diffusion of the highlight regions (greater is gamma,
	smaller is the highlight, and more shiny the object appears to be)
	*/
	
	vec3 fSpecular = ms * pow(clamp(dot(wr,-reflect(lx,nx)),0.0f,1.0f),gamma);
	return fSpecular;
}

vec3 spot_light_color(vec3 l, float g ,vec3 p, vec3 x,float beta, vec3 d, float cOut, float cIn) {
	/*
	spot_light_color = L(l,lx)

	l = light color
	g = target distance (the distance at which the light reduction is exactly 1)
	p = light position
	x = the rendered point (fragPos)
	beta = decay factor
	d = direction of the spot light
	cOut = outer cones
	cIn = inner cones
	*/

	vec3 L = l*pow(float(g/length(p-x)),float(beta))*clamp((dot(normalize(p-x),d)-cOut)/(cIn-cOut),0.0f,1.0f) ;

	return L;
}
vec3 spot_light_dir(vec3 p, vec3 x) {
	/*
	spot_light_dir = lx

	p = light position
	x = the rendered point (fragPos)
	*/

	vec3 lx =normalize(p-x);
	return lx ;
}


void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	//Diffuse color
	vec3 DifCol = texture(texSampler, fragTexCoord).rgb;
	//Specular color
	vec3 SpecCol = texture(texel, fragTexCoord).rgb;
	//Specular power 
	float gamma = texture(texel, fragTexCoord).a * 200.0f;

	//Light model
	vec3 Lspot = spot_light_color(
		gubo.lightColor,
		gubo.lightParams.w,
		gubo.lightPos,
		fragPos,
		gubo.lightParams.z,
		gubo.lightDir,
		gubo.lightParams.y,
		gubo.lightParams.x
	);

	//Light direction
	vec3 lx = spot_light_dir(
		gubo.lightPos,
		fragPos
	);

	//BRDF functions
	vec3 fDiffuse = LambertReflection(
		DifCol,
		lx,
		Norm
	);
	vec3 fSpecular = PhongReflection(
		SpecCol,
		EyeDir,
		lx,
		Norm,
		gamma
	);

	//Rendering equation
	vec3 L = Lspot*(fDiffuse+fSpecular);

	outColor = vec4(clamp(L,vec3(0.0f), vec3(1.0f)), 1.0f);	
}