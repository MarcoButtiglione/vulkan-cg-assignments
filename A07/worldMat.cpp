// Create a world matrix using position, Euler angles, and size
// Euler angles are passed in YPR parameter:
// YPR.x : Yaw
// YPR.y : Pitch
// YPR.z : Roll
glm::mat4 MakeWorldMatrixEuler(glm::vec3 pos, glm::vec3 YPR, glm::vec3 size) {
	glm::mat4 Mw =
		glm::translate(glm::mat4(1.0), glm::vec3(pos[0], pos[1], pos[2])) *
		glm::rotate(glm::mat4(1.0), glm::radians(YPR.x), glm::vec3(0, 1, 0)) *
		glm::rotate(glm::mat4(1.0), glm::radians(YPR.y), glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0), glm::radians(YPR.z), glm::vec3(0, 0, 1)) *
		glm::scale(glm::mat4(1.0), glm::vec3(size[0], size[1], size[2]));
	glm::mat4 out = Mw;
	return out;
}

// Create a world matrix using position, quaternion angles, and size
glm::mat4 MakeWorldMatrixQuat(glm::vec3 pos, glm::quat rQ, glm::vec3 size) {
	glm::mat4 MQ = glm::mat4(rQ);
	glm::mat4 Mw =
		glm::translate(glm::mat4(1.0), glm::vec3(pos[0], pos[1], pos[2])) *
		MQ*
		glm::scale(glm::mat4(1.0), glm::vec3(size[0], size[1], size[2]));

	glm::mat4 out = Mw;
	return out;
}

