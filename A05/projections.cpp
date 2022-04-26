#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_RADIANS

float n = 0.1, f = 9.9;

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 90o
glm::mat4 PO1(float a) {
	float fov = glm::radians(90.0f);
	glm::mat4 M1glm = glm::perspective(fov, a, n, f);
	M1glm[1][1] *= -1;
	glm::mat4 out = M1glm;
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 120o
glm::mat4 PO2(float a) {
	float fov = glm::radians(120.0f);
	glm::mat4 M1glm = glm::perspective(fov, a, n, f);
	M1glm[1][1] *= -1;
	glm::mat4 out = M1glm;
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 30o
glm::mat4 PO3(float a) {
	float fov = glm::radians(30.0f);
	glm::mat4 M1glm = glm::perspective(fov, a, n, f);
	M1glm[1][1] *= -1;
	glm::mat4 out = M1glm;
	return out;
}

// Create a matrix for Perspecrtive projection, with the given aspect ratio a.
// Here the perspective should only show the left side of the view
// with a FovY = 90o. Here r=0, and l, t and b should be computed
// to match both the aspect ratio and the FovY
glm::mat4 PO4(float a) {

	float t = n*tan((3.14/2)/2);
	float b = -n*tan((3.14 / 2) / 2);
	float r = 0.0;
	float l = -a * (t - b);
	
	glm::mat4 M2glm = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) * glm::frustum(l, r, b, t, n, f);
	glm::mat4 out = M2glm;
	return out;
}

