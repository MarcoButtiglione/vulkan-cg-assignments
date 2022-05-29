#define M_PI           3.14159265358979323846  /* pi */

// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec2 UV;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;


void makeModels() {
//// M1 : Cube
	M1_vertices.resize(4 * 6);

	//back
	M1_vertices[0].pos = glm::vec3(-1.0, -1.0, -1.0);
	M1_vertices[0].norm = glm::vec3(0.0, 0.0, -1.0);
	M1_vertices[0].UV = glm::vec2(0.125, 0.125);
	M1_vertices[1].pos = glm::vec3(1.0, -1.0, -1.0);
	M1_vertices[1].norm = glm::vec3(0.0, 0.0, -1.0);
	M1_vertices[1].UV = glm::vec2(0.125, 0.0);
	M1_vertices[2].pos = glm::vec3(1.0, 1.0, -1.0);
	M1_vertices[2].norm = glm::vec3(0.0, 0.0, -1.0);
	M1_vertices[2].UV = glm::vec2(0.25, 0.0);
	M1_vertices[3].pos = glm::vec3(-1.0, 1.0, -1.0);
	M1_vertices[3].norm = glm::vec3(0.0, 0.0, -1.0);
	M1_vertices[3].UV = glm::vec2(0.25, 0.125);

	//left
	M1_vertices[4].pos = glm::vec3(-1.0, -1.0, -1.0);
	M1_vertices[4].norm = glm::vec3(-1.0, 0.0, 0.0);
	M1_vertices[4].UV = glm::vec2(0.125, 0.125);
	M1_vertices[5].pos = glm::vec3(-1.0, 1.0, -1.0);
	M1_vertices[5].norm = glm::vec3(-1.0, 0.0, 0.0);
	M1_vertices[5].UV = glm::vec2(0.25, 0.125);
	M1_vertices[6].pos = glm::vec3(-1.0, 1.0, 1.0);
	M1_vertices[6].norm = glm::vec3(-1.0, 0.0, 0.0);
	M1_vertices[6].UV = glm::vec2(0.25, 0.25);
	M1_vertices[7].pos = glm::vec3(-1.0, -1.0, 1.0);
	M1_vertices[7].norm = glm::vec3(-1.0, 0.0, 0.0);
	M1_vertices[7].UV = glm::vec2(0.125, 0.25);

	//front
	M1_vertices[8].pos = glm::vec3(-1.0, -1.0, 1.0);
	M1_vertices[8].norm = glm::vec3(0.0, 0.0, 1.0);
	M1_vertices[8].UV = glm::vec2(0.125, 0.25);
	M1_vertices[9].pos = glm::vec3(1.0, -1.0, 1.0);
	M1_vertices[9].norm = glm::vec3(0.0, 0.0, 1.0);
	M1_vertices[9].UV = glm::vec2(0.125, 0.375);
	//
	M1_vertices[10].pos = glm::vec3(1.0, 1.0, 1.0);
	M1_vertices[10].norm = glm::vec3(0.0, 0.0, 1.0);
	M1_vertices[10].UV = glm::vec2(0.25, 0.375);
	//
	M1_vertices[11].pos = glm::vec3(-1.0, 1.0, 1.0);
	M1_vertices[11].norm = glm::vec3(0.0, 0.0, 1.0);
	M1_vertices[11].UV = glm::vec2(0.25, 0.25);


	//right
	M1_vertices[12].pos = glm::vec3(1.0, -1.0, 1.0);
	M1_vertices[12].norm = glm::vec3(1.0, 0.0, 0.0);
	M1_vertices[12].UV = glm::vec2(0.125, 0.375);
	M1_vertices[13].pos = glm::vec3(1.0, -1.0, -1.0);
	M1_vertices[13].norm = glm::vec3(1.0, 0.0, 0.0);
	M1_vertices[13].UV = glm::vec2(0.125, 0.499);
	M1_vertices[14].pos = glm::vec3(1.0, 1.0, -1.0);
	M1_vertices[14].norm = glm::vec3(1.0, 0.0, 0.0);
	M1_vertices[14].UV = glm::vec2(0.25, 0.499);
	M1_vertices[15].pos = glm::vec3(1.0, 1.0, 1.0);
	M1_vertices[15].norm = glm::vec3(1.0, 0.0, 0.0);
	M1_vertices[15].UV = glm::vec2(0.25, 0.375);

	//Bottom
	M1_vertices[16].pos = glm::vec3(-1.0, -1.0, -1.0);
	M1_vertices[16].norm = glm::vec3(0.0, -1.0, 0.0);
	M1_vertices[16].UV = glm::vec2(0.0, 0.25);
	M1_vertices[17].pos = glm::vec3(1.0, -1.0, -1.0);
	M1_vertices[17].norm = glm::vec3(0.0, -1.0, 0.0);
	M1_vertices[17].UV = glm::vec2(0.0, 0.375);
	M1_vertices[18].pos = glm::vec3(1.0, -1.0, 1.0);
	M1_vertices[18].norm = glm::vec3(0.0, -1.0, 0.0);
	M1_vertices[18].UV = glm::vec2(0.125, 0.375);
	M1_vertices[19].pos = glm::vec3(-1.0, -1.0, 1.0);
	M1_vertices[19].norm = glm::vec3(0.0, -1.0, 0.0);
	M1_vertices[19].UV = glm::vec2(0.125, 0.25);


	//Top
	//
	M1_vertices[20].pos = glm::vec3(-1.0, 1.0, 1.0);
	M1_vertices[20].norm = glm::vec3(0.0, 1.0, 0.0);
	M1_vertices[20].UV = glm::vec2(0.25, 0.25);
	//
	M1_vertices[21].pos = glm::vec3(1.0, 1.0, 1.0);
	M1_vertices[21].norm = glm::vec3(0.0, 1.0, 0.0);
	M1_vertices[21].UV = glm::vec2(0.25, 0.375);
	M1_vertices[22].pos = glm::vec3(1.0, 1.0, -1.0);
	M1_vertices[22].norm = glm::vec3(0.0, 1.0, 0.0);
	M1_vertices[22].UV = glm::vec2(0.375, 0.375);
	M1_vertices[23].pos = glm::vec3(-1.0, 1.0, -1.0);
	M1_vertices[23].norm = glm::vec3(0.0, 1.0, 0.0);
	M1_vertices[23].UV = glm::vec2(0.375, 0.25);




	// Resizes the indices array. Repalce the values with the correct number of
	// indices (3 * number of triangles)
	M1_indices.resize(3 * 2 * 6);

	//front
	M1_indices[0] = 0;
	M1_indices[1] = 1;
	M1_indices[2] = 2;
	//
	M1_indices[3] = 2;
	M1_indices[4] = 3;
	M1_indices[5] = 0;

	//left
	M1_indices[6] = 4;
	M1_indices[7] = 5;
	M1_indices[8] = 6;
	//
	M1_indices[9] = 6;
	M1_indices[10] = 7;
	M1_indices[11] = 4;

	//back
	M1_indices[12] = 8;
	M1_indices[13] = 9;
	M1_indices[14] = 10;
	//
	M1_indices[15] = 10;
	M1_indices[16] = 11;
	M1_indices[17] = 8;

	//right
	M1_indices[18] = 12;
	M1_indices[19] = 13;
	M1_indices[20] = 14;
	//
	M1_indices[21] = 14;
	M1_indices[22] = 15;
	M1_indices[23] = 12;


	//top
	M1_indices[24] = 16;
	M1_indices[25] = 17;
	M1_indices[26] = 18;
	//
	M1_indices[27] = 18;
	M1_indices[28] = 19;
	M1_indices[29] = 16;

	//bottom
	M1_indices[30] = 20;
	M1_indices[31] = 21;
	M1_indices[32] = 22;
	//
	M1_indices[33] = 22;
	M1_indices[34] = 23;
	M1_indices[35] = 20;


//// M2 : Cylinder
// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices
	int NSlicesCylinder = 64;
	float radiusCylinder = 1;
	float heightCylinder = 3;
	float cxCyl = 0, cyCyl = 0, czCyl = 0;


	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices
	M2_vertices.resize(4 * NSlicesCylinder + 4);
	// Vertices definitions

	//Top central vertex
	M2_vertices[0].pos = glm::vec3(cxCyl, cyCyl + heightCylinder / 2, czCyl);
	M2_vertices[0].norm = glm::vec3(0.0, 1.0, 0.0);
	M2_vertices[0].UV = glm::vec2(0.625, 0.125);

	//Bottom central vertex
	M2_vertices[1].pos = glm::vec3(cxCyl, cyCyl - heightCylinder / 2, czCyl);
	M2_vertices[1].norm = glm::vec3(0.0, -1.0, 0.0);
	M2_vertices[1].UV = glm::vec2(0.875, 0.125);

	//Top/bottom vertices of the top/bottom faces
	for (int i = 0;i < NSlicesCylinder;i++) {
		//Top vertices (even indexes: 2, 4..., 2*NSlicesCylinder)
		M2_vertices[(i + 1) * 2 + 0].pos = glm::vec3(
			cxCyl + radiusCylinder * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
			cyCyl + heightCylinder / 2,
			czCyl + radiusCylinder * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
		);
		M2_vertices[(i + 1) * 2 + 0].norm = glm::vec3(0.0, 1.0, 0.0);
		M2_vertices[(i + 1) * 2 + 0].UV = glm::vec2(
			0.625 + 0.125 * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
			0.125 + 0.125 * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
		);

		//Bottom vertices (odd indexes 3, 5..., 2*NSlicesCylinder+1)
		M2_vertices[(i + 1) * 2 + 1].pos = glm::vec3(
			cxCyl + radiusCylinder * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
			cyCyl - heightCylinder / 2,
			czCyl + radiusCylinder * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
		);
		M2_vertices[(i + 1) * 2 + 1].norm = glm::vec3(0.0, -1.0, 0.0);
		M2_vertices[(i + 1) * 2 + 1].UV = glm::vec2(
			0.875 + 0.125 * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
			0.125 + 0.125 * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
		);
	}

	//Top/bottom vertices of the side faces
	for (int i = NSlicesCylinder;i < 2 * NSlicesCylinder;i++) {

		//Top vertices (even indexes: 2*NSlicesCylinder+2,..., 4*NSlicesCylinder)
		M2_vertices[(i + 1) * 2 + 0].pos = glm::vec3(
			cxCyl + radiusCylinder * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
			cyCyl + heightCylinder / 2,
			czCyl + radiusCylinder * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
		);
		M2_vertices[(i + 1) * 2 + 0].norm = glm::vec3(
			cos((float)i / NSlicesCylinder * 2.0 * M_PI),
			0.0,
			sin((float)i / NSlicesCylinder * 2.0 * M_PI)
		);
		M2_vertices[(i + 1) * 2 + 0].UV = glm::vec2(
			1.0-((float)(i- NSlicesCylinder)/NSlicesCylinder) * 0.5,
			0.25
		);
		
		//Bottom vertices (odd indexes 2*NSlicesCylinder+3,..., 4*NSlicesCylinder+1)
		M2_vertices[(i + 1) * 2 + 1].pos = glm::vec3(
			cxCyl + radiusCylinder * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
			cyCyl - heightCylinder / 2,
			czCyl + radiusCylinder * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
		);
		M2_vertices[(i + 1) * 2 + 1].norm = M2_vertices[(i + 1) * 2 + 0].norm;	
		M2_vertices[(i + 1) * 2 + 1].UV = glm::vec2(
			1.0 - ((float)(i - NSlicesCylinder) / NSlicesCylinder) * 0.5,
			0.50
		);
	}

	M2_vertices[4 * NSlicesCylinder + 2].pos = glm::vec3(cxCyl + radiusCylinder,cyCyl + heightCylinder / 2,czCyl);
	M2_vertices[4 * NSlicesCylinder + 2].norm = glm::vec3(1.0,0.0,0.0);
	M2_vertices[4 * NSlicesCylinder + 2].UV = glm::vec2(
		0.5,
		0.25
	);

	M2_vertices[4 * NSlicesCylinder + 3].pos = glm::vec3(cxCyl + radiusCylinder, cyCyl - heightCylinder / 2, czCyl);
	M2_vertices[4 * NSlicesCylinder + 3].norm = glm::vec3(1.0, 0.0, 0.0);
	M2_vertices[4 * NSlicesCylinder + 3].UV = glm::vec2(
		0.5,
		0.5
	);


	

	// Resizes the indices array. Repalce the values with the correct number of
	// indices (3 * number of triangles)
	M2_indices.resize(3 * NSlicesCylinder * 4);

	// indices definitions
	for (int i = 0;i < NSlicesCylinder;i++) {
		//up
		M2_indices[i * 12 + 0] = 0;
		M2_indices[i * 12 + 1] = 2 * (i + 1);
		M2_indices[i * 12 + 2] = 2 * ((i + 1) % NSlicesCylinder + 1);

		//down
		M2_indices[i * 12 + 3] = 1;
		M2_indices[i * 12 + 4] = (2 * (i + 1)) + 1;
		M2_indices[i * 12 + 5] = (2 * ((i + 1) % NSlicesCylinder + 1)) + 1;

		//around
		M2_indices[i * 12 + 6] = (2 * NSlicesCylinder) + 2 * (i + 1);			//up
		M2_indices[i * 12 + 7] = (2 * NSlicesCylinder) + 2 * (i + 2);			//up
		M2_indices[i * 12 + 8] = (2 * NSlicesCylinder) + (2 * (i + 1)) + 1;		//down (with the first)

		M2_indices[i * 12 + 9] = (2 * NSlicesCylinder) + 2 * (i + 1) + 1;		//down
		M2_indices[i * 12 + 10] = (2 * NSlicesCylinder) + 2 * (i + 2) + 1;		//down
		M2_indices[i * 12 + 11] = (2 * NSlicesCylinder) + 2 * (i + 2);			//up (with the second)
	}

}