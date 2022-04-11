#define M_PI           3.14159265358979323846  /* pi */
#define GLM_FORCE_RADIANS
#include <iostream>
#include <iostream>
#include <iostream>

// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
void makeModels() {
//// M1 : Cube
// Replace the code below, that creates a simple square, with the one to create a cube.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices components (3 * number of vertices)
M1_vertices.resize(3 * 8);

// first vertex of M1
M1_vertices[0] = -1.0;
M1_vertices[1] = -1.0;
M1_vertices[2] = -1.0;

// second vertex of M1
M1_vertices[3] =  1.0;
M1_vertices[4] = -1.0;
M1_vertices[5] = -1.0;

// third vertex of M1
M1_vertices[6] =  1.0;
M1_vertices[7] =  1.0;
M1_vertices[8] = -1.0;

// fourth vertex of M1
M1_vertices[9] = -1.0;
M1_vertices[10] = 1.0;
M1_vertices[11] = -1.0; 

//5th vertex of M1
M1_vertices[12] = -1.0;
M1_vertices[13] = -1.0;
M1_vertices[14] = 1.0;
//6th vertex of M1
M1_vertices[15] = 1.0;
M1_vertices[16] = -1.0;
M1_vertices[17] = 1.0;
//7th vertex of M1
M1_vertices[18] = 1.0;
M1_vertices[19] = 1.0;
M1_vertices[20] = 1.0;
//8th vertex of M1
M1_vertices[21] = -1.0;
M1_vertices[22] = 1.0;
M1_vertices[23] = 1.0;


// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M1_indices.resize(3 * 12);

// first triangle
M1_indices[0] = 0;
M1_indices[1] = 1;
M1_indices[2] = 2;
// second triangle
M1_indices[3] = 2;
M1_indices[4] = 3;
M1_indices[5] = 0;

// 3rd triangle
M1_indices[6] = 1;
M1_indices[7] = 2;
M1_indices[8] = 5;
// 4th triangle
M1_indices[9] = 6;
M1_indices[10] = 2;
M1_indices[11] = 5;

// 5th triangle
M1_indices[12] = 6;
M1_indices[13] = 4;
M1_indices[14] = 5;
// 6th triangle
M1_indices[15] = 4;
M1_indices[16] = 6;
M1_indices[17] = 7;

// 7th triangle
M1_indices[18] = 7;
M1_indices[19] = 3;
M1_indices[20] = 4;
// 8th triangle
M1_indices[21] = 4;
M1_indices[22] = 0;
M1_indices[23] = 3;

// 9th triangle
M1_indices[24] = 3;
M1_indices[25] = 2;
M1_indices[26] = 7;
// 10th triangle
M1_indices[27] = 2;
M1_indices[28] = 7;
M1_indices[29] = 6;


// 11th triangle
M1_indices[30] = 0;
M1_indices[31] = 4;
M1_indices[32] = 1;
// 12th triangle
M1_indices[33] = 1;
M1_indices[34] = 4;
M1_indices[35] = 5;



//// M2 : Cylinder
// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.



int NSlices = 64;
float radius = 1;
float height = 2;
float cx = 0, cy = 0, cz = 0;

// Resizes the vertices array. Repalce the values with the correct number of
// vertices components (3 * number of vertices)
M2_vertices.resize(2*(NSlices+1)*3);

M2_vertices[0] = cx;
M2_vertices[1] = cy + height / 2;
M2_vertices[2] = cz;
M2_vertices[3] = cx;
M2_vertices[4] = cy - height / 2;
M2_vertices[5] = cz;

for (int i = 0;i < NSlices;i++) {
	M2_vertices[(i + 1) * 6 + 0] = cx + radius * cos((float)i / NSlices * 2.0 * M_PI); // x of the vertex
	M2_vertices[(i + 1) * 6 + 1] = cy + height / 2; // y of the vertex
	M2_vertices[(i + 1) * 6 + 2] = cz + radius * sin((float)i / NSlices * 2.0 * M_PI); // z of the vertex}

	M2_vertices[(i + 1) * 6 + 3] = cx + radius * cos((float)i / NSlices * 2.0 * M_PI); // x of the vertex
	M2_vertices[(i + 1) * 6 + 4] = cy - height / 2; // y of the vertex
	M2_vertices[(i + 1) * 6 + 5] = cz + radius * sin((float)i / NSlices * 2.0 * M_PI); // z of the vertex}
}

// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M2_indices.resize(3 * NSlices * 4);

// indices definitions

for (int i = 0;i < NSlices;i++) {
	//up
	M2_indices[i * 12 + 0] = 0;
	M2_indices[i * 12+ 1] = 2 *( i + 1);
	M2_indices[i * 12 + 2] = 2 *((i + 1) % NSlices + 1);

	//down
	M2_indices[i * 12 + 3] = 1;
	M2_indices[i * 12 + 4] = (2 * (i + 1))+1;
	M2_indices[i * 12 + 5] = (2 * ((i + 1) % NSlices + 1))+1;

	//around
	M2_indices[i * 12 + 6] = 2 * (i + 1);							//up
	M2_indices[i * 12 + 7] = 2 * ((i + 1) % NSlices + 1);			//up
	M2_indices[i * 12 + 8] = (2 * (i + 1)) + 1;						//down (with the first)

	M2_indices[i * 12 + 9] = (2 * (i + 1)) + 1;						//down
	M2_indices[i * 12 + 10] = (2 * ((i + 1) % NSlices + 1)) + 1;	//down
	M2_indices[i * 12 + 11] = 2 * ((i + 1) % NSlices + 1);			//up (with the second)
}

//// M3 : Sphere
// Replace the code below, that creates a simple triangle, with the one to create a sphere.
int NSlicesHor = 64;
int NSlicesVert = 64;
float radiusSphere = 0.5;

float cxS = 0, cyS = 0, czS = 0;

// Resizes the vertices array. Repalce the values with the correct number of
// vertices components (3 * number of vertices)
int totVertices = ((NSlicesVert - 2) * NSlicesHor + 1) + 2 + 1;
M3_vertices.resize(3 * totVertices);

// Vertices definitions
M3_vertices[0] = cxS;
M3_vertices[1] = cyS + radiusSphere;
M3_vertices[2] = czS;


float radiusVar;
float heightVar;

for (int i = 1;i < NSlicesVert - 1;i++) {
	radiusVar = radiusSphere * sin((float)i / NSlicesVert * M_PI);
	heightVar = radiusSphere * cos((float)i / NSlicesVert * M_PI);

	for (int j = 0;j < NSlicesHor;j++) {
		M3_vertices[((i - 1) * NSlicesHor + j + 1) * 3 + 0] = cxS + radiusVar * cos((float)j / NSlicesHor * 2.0 * M_PI); // x of the vertex
		M3_vertices[((i - 1) * NSlicesHor + j + 1) * 3 + 1] = cyS + heightVar; // y of the vertex
		M3_vertices[((i - 1) * NSlicesHor + j + 1) * 3 + 2] = czS + radiusVar * sin((float)j / NSlicesHor * 2.0 * M_PI); // z of the vertex}

	}
}


M3_vertices[3 * ((NSlicesVert - 2) * NSlicesHor + 1) + 0] = cxS;
M3_vertices[3 * ((NSlicesVert - 2) * NSlicesHor + 1) + 1] = cyS - radiusSphere;
M3_vertices[3 * ((NSlicesVert - 2) * NSlicesHor + 1) + 2] = czS;



// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M3_indices.resize(3 * (NSlicesHor + totVertices) * 2);

// indices definitions


for (int i = 0;i < (NSlicesHor);i++) {
	M3_indices.push_back(0);
	M3_indices.push_back(i + 1);
	M3_indices.push_back((i + 1) % NSlicesHor + 1);
}
for (int i = ((NSlicesVert - 2) * NSlicesHor + 1) - NSlicesHor;i < (((NSlicesVert - 2) * NSlicesHor + 1));i++) {
	M3_indices.push_back(((NSlicesVert - 2) * NSlicesHor + 1));
	M3_indices.push_back(i);
	M3_indices.push_back(((i + 1)));
}

for (int i = 1;i < (totVertices - NSlicesHor) - 3;i++) {
	M3_indices.push_back(i);
	M3_indices.push_back((i + 1) % (totVertices));
	M3_indices.push_back((i + NSlicesHor) % (totVertices));
}



for (int i = 0;i < (totVertices - NSlicesHor) - 3;i++) {
	M3_indices.push_back(i + 1);
	M3_indices.push_back(i + NSlicesHor);
	M3_indices.push_back(((i + NSlicesHor) % (totVertices)) + 1);
}

//// M4 : Spring
const float radiusSpring = 0.5;
const float radiusTube = 0.1;

const float cxSpring = 0, cySpring = 0, czSpring = 0;
const float heightSpring = 1;
const int NSpiral = 3;

const int NSlicesSpring = 2048;
const int NSlicesTube = 64;

const int totVertSpring = NSlicesSpring * NSlicesTube;

// Replace the code below, that creates a simple octahedron, with the one to create a spring.
M4_vertices.resize(3 * totVertSpring);

float tubeCircleVert[2*NSlicesTube];
//Tube section
for (int i = 0;i <NSlicesTube;i++) {
	float x = radiusTube * sin((float)i / NSlicesTube * 2.0 * M_PI);
	float y = radiusTube * cos((float)i / NSlicesTube * 2.0 * M_PI);
	tubeCircleVert[2*i] = x;
	tubeCircleVert[2*i+1] = y;	
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


	for (int j = 0;j < NSlicesTube;j++) {
		glm::vec4 p= glm::vec4(tubeCircleVert[2*j], tubeCircleVert[2*j+1],0,1);

		p =Ry* T * p;

		M4_vertices[(i * NSlicesTube + j) * 3 + 0] = p[0];
		M4_vertices[(i * NSlicesTube + j) * 3 + 1] = p[1];
		M4_vertices[(i * NSlicesTube + j) * 3 + 2] = p[2];
	}
}

// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M4_indices.resize(3 * 2* totVertSpring);

// indices definitions
/*

*/
for (int i = 0;i < totVertSpring- NSlicesTube;i++) {
	M4_indices.push_back(i);
	M4_indices.push_back(i + 1);
	M4_indices.push_back((i + NSlicesTube));

	M4_indices.push_back(i + 1);
	M4_indices.push_back(i + NSlicesTube);
	M4_indices.push_back((i + NSlicesTube) + 1);

}
}