#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

float w = 2, f = 12, n = -4;
float l = -w, r = w;


// Create a matrix for Isometric projection with the given aspect ration a
glm::mat4 PO1(float a) {
	float t = w / a, b = -w / a;
	glm::mat4 Ry = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0));
	glm::mat4 Rx = glm::rotate(glm::mat4(1), glm::radians(35.26f), glm::vec3(1, 0, 0));
	glm::mat4 out=glm::scale(glm::mat4(1.0),glm::vec3(1,-1,1))*
		glm::ortho(l,r,b,t,n,f)*
		Rx*Ry;
	return out;
}

// Create a matrix for Dimnetric projection (alpha = 45 degree)
// with the given aspect ration a
glm::mat4 PO2(float a) {
	float t = w / a, b = -w / a;
	glm::mat4 Ry = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0));
	glm::mat4 Rx = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0));
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) *
		glm::ortho(l, r, b, t, n, f) *
		Rx * Ry;
	return out;
}

// Create a matrix for Trimetric projection (alpha = 45 degree, beta = 60 degree)
// with the given aspect ration a
glm::mat4 PO3(float a) {
	float t = w / a, b = -w / a;
	glm::mat4 Ry = glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0, 1, 0));
	glm::mat4 Rx = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0));
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) *
		glm::ortho(l, r, b, t, n, f) *
		Rx * Ry;
	return out;
}

// Create a matrix for Cabinet projection (alpha = 45)
// with the given aspect ration a
glm::mat4 PO4(float a) {
	float t = w / a, b = -w / a;
	glm::mat4 Sz = glm::mat4(
		1,0,0,0,
		0,1,0,0,
		-0.5*cos(3.14/4),-0.5 * sin(3.14 / 4),1,0,
		0,0,0,1);
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) *
		glm::ortho(l, r, b, t, n, f) * Sz;
	return out;
}

