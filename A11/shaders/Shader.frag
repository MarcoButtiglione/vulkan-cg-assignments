#version 450

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	outColor = vec4(( sin(gubo.time * 6.28)) / 5.0,
					float(gubo.time) / 10.0,
					float(gubo.time) / 15.0,
					1.0);
}