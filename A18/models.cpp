#define M_PI           3.14159265358979323846  /* pi */


// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;
std::vector<Vertex> M3_vertices;
std::vector<Vertex> M4_vertices;

void makeModels() {
//// M1 : Cube
// Replace the code below, that creates a simple square, with the one to create a cube.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices
M1_vertices.resize(4*6);

//front
M1_vertices[0].pos  = glm::vec3(-1.0,-1.0,-1.0);
M1_vertices[0].norm = glm::vec3(0.0,0.0,-1.0);
M1_vertices[1].pos  = glm::vec3(1.0,-1.0,-1.0);
M1_vertices[1].norm = glm::vec3(0.0,0.0,-1.0);
M1_vertices[2].pos  = glm::vec3(1.0,1.0,-1.0);
M1_vertices[2].norm = glm::vec3(0.0,0.0,-1.0);
M1_vertices[3].pos  = glm::vec3(-1.0,1.0,-1.0);
M1_vertices[3].norm = glm::vec3(0.0,0.0,-1.0);

//left
M1_vertices[4].pos = glm::vec3(-1.0, -1.0, -1.0);
M1_vertices[4].norm = glm::vec3(-1.0, 0.0, 0.0);
M1_vertices[5].pos = glm::vec3(-1.0, 1.0, -1.0);
M1_vertices[5].norm = glm::vec3(-1.0, 0.0, 0.0);
M1_vertices[6].pos = glm::vec3(-1.0, 1.0, 1.0);
M1_vertices[6].norm = glm::vec3(-1.0, 0.0, 0.0);
M1_vertices[7].pos = glm::vec3(-1.0, -1.0, 1.0);
M1_vertices[7].norm = glm::vec3(-1.0, 0.0, 0.0);

//back
M1_vertices[8].pos = glm::vec3(-1.0, -1.0, 1.0);
M1_vertices[8].norm = glm::vec3(0.0, 0.0, 1.0);
M1_vertices[9].pos = glm::vec3(1.0, -1.0, 1.0);
M1_vertices[9].norm = glm::vec3(0.0, 0.0, 1.0);
M1_vertices[10].pos = glm::vec3(1.0, 1.0, 1.0);
M1_vertices[10].norm = glm::vec3(0.0, 0.0, 1.0);
M1_vertices[11].pos = glm::vec3(-1.0, 1.0, 1.0);
M1_vertices[11].norm = glm::vec3(0.0, 0.0, 1.0);

//right
M1_vertices[12].pos = glm::vec3(1.0, -1.0, 1.0);
M1_vertices[12].norm = glm::vec3(1.0, 0.0, 0.0);
M1_vertices[13].pos = glm::vec3(1.0, -1.0, -1.0);
M1_vertices[13].norm = glm::vec3(1.0, 0.0, 0.0);
M1_vertices[14].pos = glm::vec3(1.0, 1.0, -1.0);
M1_vertices[14].norm = glm::vec3(1.0, 0.0, 0.0);
M1_vertices[15].pos = glm::vec3(1.0, 1.0, 1.0);
M1_vertices[15].norm = glm::vec3(1.0, 0.0, 0.0);

//Bottom
M1_vertices[16].pos = glm::vec3(-1.0, -1.0, -1.0);
M1_vertices[16].norm = glm::vec3(0.0, -1.0, 0.0);
M1_vertices[17].pos = glm::vec3(1.0, -1.0, -1.0);
M1_vertices[17].norm = glm::vec3(0.0, -1.0, 0.0);
M1_vertices[18].pos = glm::vec3(1.0, -1.0, 1.0);
M1_vertices[18].norm = glm::vec3(0.0, -1.0, 0.0);
M1_vertices[19].pos = glm::vec3(-1.0, -1.0, 1.0);
M1_vertices[19].norm = glm::vec3(0.0, -1.0, 0.0);

//Top
M1_vertices[20].pos = glm::vec3(-1.0, 1.0, 1.0);
M1_vertices[20].norm = glm::vec3(0.0, 1.0, 0.0);
M1_vertices[21].pos = glm::vec3(1.0, 1.0, 1.0);
M1_vertices[21].norm = glm::vec3(0.0, 1.0, 0.0);
M1_vertices[22].pos = glm::vec3(1.0, 1.0, -1.0);
M1_vertices[22].norm = glm::vec3(0.0, 1.0, 0.0);
M1_vertices[23].pos = glm::vec3(-1.0, 1.0, -1.0);
M1_vertices[23].norm = glm::vec3(0.0, 1.0, 0.0);




// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M1_indices.resize(3 * 2*6);

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
int NSlicesCylinder = 16;
float radiusCylinder = 1;
float heightCylinder = 2;
float cxCyl = 0, cyCyl = 0, czCyl = 0;


// Resizes the vertices array. Repalce the values with the correct number of
// vertices
M2_vertices.resize(4 * NSlicesCylinder+2);
// Vertices definitions

//Top central vertex
M2_vertices[0].pos = glm::vec3(cxCyl, cyCyl + heightCylinder / 2, czCyl);
M2_vertices[0].norm = glm::vec3(0.0, 1.0, 0.0);

//Bottom central vertex
M2_vertices[1].pos = glm::vec3(cxCyl, cyCyl - heightCylinder / 2, czCyl);
M2_vertices[1].norm = glm::vec3(0.0, -1.0, 0.0);

//Top/bottom vertices of the top/bottom faces
for (int i = 0;i < NSlicesCylinder;i++) {
	//Top vertices (even indexes: 2, 4..., 2*NSlicesCylinder)
	M2_vertices[(i + 1) * 2 + 0].pos = glm::vec3(
		cxCyl + radiusCylinder * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
		cyCyl + heightCylinder / 2,
		czCyl + radiusCylinder * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
	);
	M2_vertices[(i + 1) * 2 + 0].norm = glm::vec3(0.0, 1.0, 0.0);
	//Bottom vertices (odd indexes 3, 5..., 2*NSlicesCylinder+1)
	M2_vertices[(i + 1) * 2 + 1].pos = glm::vec3(
		cxCyl + radiusCylinder * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
		cyCyl - heightCylinder / 2,
		czCyl + radiusCylinder * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
	);
	M2_vertices[(i + 1) * 2 + 1].norm = glm::vec3(0.0, -1.0, 0.0);
}

//Top/bottom vertices of the side faces
for (int i = NSlicesCylinder;i < 2*NSlicesCylinder;i++) {

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

	//Bottom vertices (odd indexes 2*NSlicesCylinder+3,..., 4*NSlicesCylinder+1)
	M2_vertices[(i + 1) * 2 + 1].pos = glm::vec3(
		cxCyl + radiusCylinder * cos((float)i / NSlicesCylinder * 2.0 * M_PI),
		cyCyl - heightCylinder / 2,
		czCyl + radiusCylinder * sin((float)i / NSlicesCylinder * 2.0 * M_PI)
	);
	M2_vertices[(i + 1) * 2 + 1].norm = M2_vertices[(i + 1) * 2 + 0].norm;
}



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
	M2_indices[i * 12 + 6] = (2 * NSlicesCylinder) + 2 * (i + 1);									//up
	M2_indices[i * 12 + 7] = (2 * NSlicesCylinder) + 2 * ((i + 1) % NSlicesCylinder + 1);			//up
	M2_indices[i * 12 + 8] = (2 * NSlicesCylinder) + (2 * (i + 1)) + 1;								//down (with the first)

	M2_indices[i * 12 + 9] = (2 * NSlicesCylinder) + (2 * (i + 1)) + 1;								//down
	M2_indices[i * 12 + 10] = (2 * NSlicesCylinder) + (2 * ((i + 1) % NSlicesCylinder + 1)) + 1;	//down
	M2_indices[i * 12 + 11] = (2 * NSlicesCylinder) + 2 * ((i + 1) % NSlicesCylinder + 1);			//up (with the second)
}


//// M3 : Sphere
// Replace the code below, that creates a simple triangle, with the one to create a sphere.
int NSlicesHorSphere = 16;
int NSlicesVertSphere = 16;
float radiusSphere = 1;

float cxSph = 0, cySph = 0, czSph = 0;

// Resizes the vertices array. Repalce the values with the correct number of
// vertices
M3_vertices.resize(NSlicesVertSphere * NSlicesHorSphere - NSlicesHorSphere+2);

// Vertices definitions
//Top central vertex

M3_vertices[0].pos = glm::vec3(cxSph, cySph + radiusSphere, czSph);
M3_vertices[0].norm = glm::vec3(0.0,1.0,0.0);

float radiusVar;
float heightVar;

for (int i = 0;i < NSlicesVertSphere-1 ;i++) {
	radiusVar = radiusSphere * sin((float)(i+1) / NSlicesVertSphere * M_PI);
	heightVar = radiusSphere * cos((float)(i+1) / NSlicesVertSphere * M_PI);

	for (int j = 0;j < NSlicesHorSphere;j++) {
		//(1,2,...,NSlicesVertSphere*NSlicesHorSphere-NSlicesHorSphere)
		M3_vertices[i* NSlicesHorSphere + j+1].pos = glm::vec3(
			cxSph + radiusVar * cos((float)j / NSlicesHorSphere * 2.0 * M_PI),
			cySph + heightVar,
			czSph + radiusVar * sin((float)j / NSlicesHorSphere * 2.0 * M_PI)
		);
		M3_vertices[i * NSlicesHorSphere + j+1].norm = glm::vec3(
			cos((float)j / NSlicesHorSphere * 2.0 * M_PI)* sin((float)(i + 1) / NSlicesVertSphere * M_PI),
			cos((float)(i+1) / NSlicesVertSphere * M_PI),
			sin((float)j / NSlicesHorSphere * 2.0 * M_PI)* sin((float)(i + 1) / NSlicesVertSphere * M_PI)
		);	
	}
	
}

//Bottom central vertex
M3_vertices[NSlicesVertSphere * NSlicesHorSphere - NSlicesHorSphere+1].pos = glm::vec3(cxSph, cySph - radiusSphere, czSph);
M3_vertices[NSlicesVertSphere * NSlicesHorSphere - NSlicesHorSphere+1].norm = glm::vec3(0.0, -1.0, 0.0);

// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
int totVertices = ((NSlicesVertSphere - 2) * NSlicesHorSphere + 1) + 2 + 1;
M3_indices.resize(3 * (NSlicesHorSphere + totVertices) * 2);

// indices definitions
//(RIVEDERE QUESTA PARTE DELL'ASS.9, QUI SEMBRA AVERLA FATTA MEGLIO)
//Top 
for (int i = 0;i < NSlicesHorSphere;i++) {
	M3_indices.push_back(0);
	M3_indices.push_back(i + 1);
	M3_indices.push_back((i + 1) % NSlicesHorSphere + 1);
}
//Bottom 
for (int i = 0;i < NSlicesHorSphere;i++) {
	M3_indices.push_back(NSlicesVertSphere* NSlicesHorSphere - NSlicesHorSphere + 1);
	M3_indices.push_back(NSlicesVertSphere* NSlicesHorSphere - NSlicesHorSphere-i);
	M3_indices.push_back(NSlicesVertSphere* NSlicesHorSphere - NSlicesHorSphere -((i + 1) % NSlicesHorSphere));
}
//Side
for (int i = 0;i < NSlicesVertSphere - 2;i++) {
	for (int j = 0;j < NSlicesHorSphere;j++) {
		M3_indices.push_back(i* NSlicesHorSphere + j + 1);
		M3_indices.push_back(i* NSlicesHorSphere + j + 2);
		M3_indices.push_back(i* NSlicesHorSphere + j + 1 + NSlicesHorSphere);

		M3_indices.push_back(i * NSlicesHorSphere + j + 1);
		M3_indices.push_back(i * NSlicesHorSphere + j + NSlicesHorSphere);
		M3_indices.push_back(i * NSlicesHorSphere + j + NSlicesHorSphere + 1);
	}
}


//// M4 : Spring
const float radiusSpring = 2;
const float radiusTube = 0.5;

const float cxSpring = 0, cySpring = 0, czSpring = 0;
const float heightSpring = 5;
const int NSpiral = 3;

const int NSlicesSpring = 1024;
const int NSlicesTube = 16;

const int totVertSpring = NSlicesSpring * NSlicesTube;

// Replace the code below, that creates a simple octahedron, with the one to create a spring.
M4_vertices.resize(totVertSpring);

float tubeCircleVert[4 * NSlicesTube];
//Tube section
for (int i = 0;i < NSlicesTube;i++) {
	float normX = sin((float)i / NSlicesTube * 2.0 * M_PI);
	float normY = cos((float)i / NSlicesTube * 2.0 * M_PI);
	float x = radiusTube * sin((float)i / NSlicesTube * 2.0 * M_PI);
	float y = radiusTube * cos((float)i / NSlicesTube * 2.0 * M_PI);
	tubeCircleVert[4 * i + 0] = x;
	tubeCircleVert[4 * i + 1] = y;
	tubeCircleVert[4 * i + 2] = normX;
	tubeCircleVert[4 * i + 3] = normY;
}


// Vertices definitions


for (int i = 0;i < NSlicesSpring;i++) {
	glm::mat4 T = glm::translate(
		glm::mat4(1),
		glm::vec3(
			cxSpring + radiusSpring,
			cySpring + heightSpring * ((float)i / NSlicesSpring),
			czSpring
		)
	);
	glm::mat4 Ry = glm::rotate(
		glm::mat4(1),
		glm::radians((float)i / NSlicesSpring * NSpiral * 360.0f),
		glm::vec3(0, 1, 0)
	);
	glm::mat4 M = Ry * T;


	for (int j = 0;j < NSlicesTube;j++) {
		glm::vec4 p = glm::vec4(tubeCircleVert[4 * j + 0], tubeCircleVert[4 * j + 1], 0, 1);
		glm::vec4 n = glm::vec4(tubeCircleVert[4 * j + 2], tubeCircleVert[4 * j + 3], 0, 0);

		p = M * p;
		n = M * n;

		M4_vertices[(i * NSlicesTube + j)].pos = glm::vec3(p[0], p[1], p[2]);
		M4_vertices[(i * NSlicesTube + j)].norm = glm::vec3(n[0], n[1], n[2]);
	}
}



// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M4_indices.resize(3 * 2 * totVertSpring);

// indices definitions
/*

*/
for (int i = 0;i < totVertSpring - NSlicesTube;i++) {
	if ((i + 1) % NSlicesTube == 0) {
		M4_indices.push_back(i);
		M4_indices.push_back(i + 1 - NSlicesTube);
		M4_indices.push_back((i + NSlicesTube));

		M4_indices.push_back(i + 1 - NSlicesTube);
		M4_indices.push_back(i + NSlicesTube);
		M4_indices.push_back(i + 1);
	}
	else {
		M4_indices.push_back(i);
		M4_indices.push_back(i + 1);
		M4_indices.push_back((i + NSlicesTube));

		M4_indices.push_back(i + 1);
		M4_indices.push_back(i + NSlicesTube);
		M4_indices.push_back((i + NSlicesTube) + 1);
	}





}


}