#define GLM_FORCE_RADIANS
// Rotate 45 degrees around an arbitrary axis passing through (1,0,-1). The x-axis can be aligned to the arbitrary axis after a rotation of 30 degrees around the z-axis, and then -60 degrees around the y-axis.
glm::mat4 T1 = glm::translate(glm::mat4(1), glm::vec3(1, 0, -1));
glm::mat4 T1_inv = inverse(T1);

glm::mat4 Rz1 = glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 0, 1));
glm::mat4 Rz1_inv = inverse(Rz1);

glm::mat4 Ry1 = glm::rotate(glm::mat4(1), glm::radians(-60.0f), glm::vec3(0, 1, 0));
glm::mat4 Ry1_inv = inverse(Ry1);

glm::mat4 Rx1 = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0));


glm::mat4 MT1 = T1*Ry1* Rz1 * Rx1*Rz1_inv*Ry1_inv*T1_inv;


// Half the size of an object, using as fixed point (5,0,-2)


glm::mat4 S2 = glm::scale(glm::mat4(1), glm::vec3(0.5, 0.5, 0.5));

glm::mat4 T2 = glm::translate(glm::mat4(1), glm::vec3(5, 0, -2));
glm::mat4 T2_inv = inverse(T2);

glm::mat4 MT2 = T2*S2*T2_inv;
			   
// Mirror the starship along a plane passing through (1,1,1), and obtained rotating 15 degree around the x axis the xz plane
glm::mat4 Rx3 = glm::rotate(glm::mat4(1), glm::radians(15.0f), glm::vec3(1, 0, 0));
glm::mat4 Rx3_inv = inverse(Rx3);

glm::mat4 T3 = glm::translate(glm::mat4(1), glm::vec3(1, 1, 1));
glm::mat4 T3_inv = inverse(T3);

glm::mat4 M3 = glm::scale(glm::mat4(1), glm::vec3(1, -1, 1));

glm::mat4 MT3 = T3*Rx3*M3*Rx3_inv*T3_inv;
			   
// Apply the inverse of the following sequence of transforms: Translation of (0, 0, 5) then rotation of 30 degree around the Y axis, and finally a uniform scaling of a factor of 3.

glm::mat4 T4 = glm::translate(glm::mat4(1), glm::vec3(0,0,5));
glm::mat4 T4_inv = inverse(T4);
glm::mat4 Ry4 = glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 1, 0));
glm::mat4 Ry4_inv = inverse(Ry4);

glm::mat4 S4 = glm::scale(glm::mat4(1), glm::vec3(3,3,3));
glm::mat4 S4_inv = inverse(S4);

glm::mat4 MT4 = inverse(S4*Ry4*T4);
//glm::mat4 MT4 = T4_inv* Ry4_inv*S4_inv;

