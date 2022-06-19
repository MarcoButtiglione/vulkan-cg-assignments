#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec3 lightPos;
	vec3 lightColor;
	vec3 eyePos;
	vec4 coneInOutDecayExp;
	vec4 selector;
} gubo;


/**** Modify from here *****/

vec3 direct_light_dir(vec3 pos) {
	// Directional light direction
	return gubo.lightDir;
}

vec3 direct_light_color(vec3 pos) {
	// Directional light color
	return gubo.lightColor;
}

vec3 point_light_dir(vec3 pos) {
	// Point light direction
	/*
	p = light position
	x = the rendered point (fragPos)
	*/
	vec3 p = gubo.lightPos;
	vec3 x = pos;

	vec3 lx =normalize(p-x);
	return lx ;
}

vec3 point_light_color(vec3 pos) {
	// Point light color
	/*
	l = light color
	g = target distance (the distance at which the light reduction is exactly 1)
	p = light position
	x = the rendered point (fragPos)
	beta = decay factor
	*/
	vec3 l = gubo.lightColor;
	float g = gubo.coneInOutDecayExp.z;
	vec3 p = gubo.lightPos;
	vec3 x = pos;
	float beta =gubo.coneInOutDecayExp.w;

	vec3 L = l*pow(float(g/length(p-x)),float(beta)) ;
	return L;
}

vec3 spot_light_dir(vec3 pos) {
	// Spot light direction
	/*
	p = light position
	x = the rendered point (fragPos)
	*/
	vec3 p = gubo.lightPos;
	vec3 x = pos;

	vec3 lx =normalize(p-x);
	return lx ;
}

vec3 spot_light_color(vec3 pos) {
	// Spot light color
	/*
	l = light color
	g = target distance (the distance at which the light reduction is exactly 1)
	p = light position
	x = the rendered point (fragPos)
	beta = decay factor
	d = direction of the spot light
	cOut = outer cones
	cIn = inner cones
	*/
	vec3 l = gubo.lightColor;
	float g = gubo.coneInOutDecayExp.z;
	vec3 p = gubo.lightPos;
	vec3 x = pos;
	float beta =gubo.coneInOutDecayExp.w;
	vec3 d=gubo.lightDir;
	float cOut = gubo.coneInOutDecayExp.x;
	float cIn =gubo.coneInOutDecayExp.y;

	vec3 L = l*pow(float(g/length(p-x)),float(beta))*clamp((dot(normalize(p-x),d)-cOut)/(cIn-cOut),0.0f,1.0f) ;
	return L;
}

/**** To from here *****/





void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	
	vec3 lD;	// light direction from the light model
	vec3 lC;	// light color and intensity from the light model
	
	lD = direct_light_dir(fragPos) * gubo.selector.x +
	     point_light_dir(fragPos)  * gubo.selector.y +
	     spot_light_dir(fragPos)   * gubo.selector.z;
	lC = direct_light_color(fragPos) * gubo.selector.x +
	     point_light_color(fragPos)  * gubo.selector.y +
	     spot_light_color(fragPos)   * gubo.selector.z;

	vec3 Diffuse = (texture(texSampler, fragTexCoord).rgb * gubo.selector.w + vec3(1,1,1) * (1-gubo.selector.w)) * (max(dot(Norm, lD),0.0f) );
	vec3 Specular = vec3(pow(max(dot(EyeDir, -reflect(lD, Norm)),0.0f), 64.0f));
	
	outColor = vec4((Diffuse + Specular) * lC, 1.0f);	
}