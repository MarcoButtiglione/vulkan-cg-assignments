 // Create a look in direction matrix
 // Pos    -> Position of the camera
 // Angs.x -> direction (alpha)
 // Angs.y -> elevation (beta)
 // Angs.z -> roll (rho)
glm::mat4 LookInDirMat(glm::vec3 Pos, glm::vec3 Angs) {
	glm::mat4 Mv =
		glm::rotate(glm::mat4(1.0), -Angs.z, glm::vec3(0, 0, 1)) *
		glm::rotate(glm::mat4(1.0), -Angs.y, glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0), -Angs.x, glm::vec3(0, 1, 0)) *
		glm::translate(glm::mat4(1.0), glm::vec3(-Pos.x, -Pos.y, -Pos.z));
	glm::mat4 out = Mv;
	return out;
}

 // Create a look at matrix
 // Pos    -> Position of the camera (c)
 // aim    -> Posizion of the target (a)
 // Roll   -> roll (rho)
glm::mat4 LookAtMat(glm::vec3 Pos, glm::vec3 aim, float Roll) {
	glm::mat4 Mv = glm::lookAt(glm::vec3(Pos.x, Pos.y, Pos.z),
		glm::vec3(aim.x, aim.y, aim.z),
		glm::vec3(0,1, 0));
	glm::mat4 Rz = glm::rotate(glm::mat4(1), -Roll, glm::vec3(0, 0, 1));
	glm::mat4 out =Rz* Mv;
	return out;
}



