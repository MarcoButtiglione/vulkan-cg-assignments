#version 450

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	int i;
	outColor = vec4((float(i % 5) + sin(gubo.time * 6.28)) / 5.0,
					float(i % 10) / 10.0,
					float(i) / 15.0,
					1.0);
}