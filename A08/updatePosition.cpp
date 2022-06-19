// Create the world matrix for the robot

glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {

	static auto startTime = std::chrono::high_resolution_clock::now();
	static float lastTime = 0.0f;
	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period>
		(currentTime - startTime).count();
	float deltaT = time - lastTime;
	lastTime = time;

	float static yaw = 0.0f, pitch = 0.0f, roll;
	float mx = 0, my = 0, mz = 0;

	if (glfwGetKey(window, GLFW_KEY_D)) {
		mx = 1;
		roll = 0.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_A)) {
		mx = -1;
		roll = 180.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_W)) {
		mz = 1;
		roll = 90.0f - 45.0f * mx;
	}
	if (glfwGetKey(window, GLFW_KEY_S)) {
		mz = -1;
		roll = -90.0f + 45.0f * mx;
	}
	if (glfwGetKey(window, GLFW_KEY_Q)) {
		my = -1;
	}
	if (glfwGetKey(window, GLFW_KEY_E)) {
		my = 1;
	}

	static glm::vec3 Pos = glm::vec3(-3, 0, 2);
	Pos.x += mx * deltaT;
	Pos.y += my * deltaT;
	Pos.z -= mz * deltaT;

	glm::mat4 out =
		glm::translate(glm::mat4(1.0), glm::vec3(Pos.x, Pos.y, Pos.z)) *
		glm::rotate(glm::mat4(1.0), glm::radians(roll), glm::vec3(0, 1, 0)) *
		glm::rotate(glm::mat4(1.0), glm::radians(pitch), glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0), glm::radians(yaw), glm::vec3(0, 0, 1)) *
		glm::scale(glm::mat4(1.0), glm::vec3(1, 1, 1));
	return out;
}

