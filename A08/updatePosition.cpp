#define GLM_FORCE_RADIANS
#include <chrono>

// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {
	static auto startTime = std::chrono::high_resolution_clock::now();
	static float lastTime = 0.0f;

	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period>
		(currentTime - startTime).count();
	float deltaT = time - lastTime;
	lastTime = time;

	static float yaw = glm::radians(0.0f);
	static glm::vec3 pos = glm::vec3(-3, 0, 2);

	glm::vec3 ux = glm::vec3(glm::rotate(glm::mat4(1), yaw, glm::vec3(0, 1, 0)) * glm::vec4(1, 0, 0, 1));
	glm::vec3 uy = glm::vec3(0, 1, 0);
	glm::vec3 uz = glm::vec3(glm::rotate(glm::mat4(1), yaw, glm::vec3(0, 1, 0)) * glm::vec4(0, 0, -1, 1));

	const float ROTATION_SPEED = glm::radians(90.0f);
	const float MOVE_SPEED = 5.0;

	if (glfwGetKey(window, GLFW_KEY_W)) {
		pos += ux * MOVE_SPEED * deltaT;
		pos += uz * MOVE_SPEED * deltaT;
	}
	if (glfwGetKey(window, GLFW_KEY_A)) {
		yaw += ROTATION_SPEED * deltaT;;
		//pos -= glm::vec3(0, 0, MOVE_SPEED);
	}
	if (glfwGetKey(window, GLFW_KEY_S)) {
		yaw += glm::radians(180.0f) * deltaT; ;
		//pos -= glm::vec3(MOVE_SPEED, 0, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_D)) {
		yaw -= ROTATION_SPEED * deltaT;;
		//pos += glm::vec3(0 ,0, MOVE_SPEED);
	}

	glm::mat4 out;

	out = glm::translate(glm::mat4(1), pos) *
		glm::rotate(glm::mat4(1.0), yaw, glm::vec3(0, 1, 0));
	return out;
}


