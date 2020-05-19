#include "Sphere.h"

Sphere::Sphere(int size) {
	sphereSize = size;
}

void Sphere::recursiveSubdivision(float v1[3], float v2[3], float v3[3], int depth)
{
	if (depth < 1) {
		glNormal3f(0, 0, 1);
		glVertex3f(v1[0], v1[1], v1[2]);
		glVertex3f(v2[0], v2[1], v2[2]);
		glVertex3f(v3[0], v3[1], v3[2]);
		return;
	}

	float v12[3], v13[3], v23[3];
	float originalDistance = sqrt(pow(v1[0], 2) + pow(v1[1], 2) + pow(v1[2], 2));

	v12[0] = (v1[0] + v2[0]) / 2;
	v12[1] = (v1[1] + v2[1]) / 2;
	v12[2] = (v1[2] + v2[2]) / 2;

	float euclideanDistance = sqrt(pow(v12[0], 2) + pow(v12[1], 2) + pow(v12[2], 2));

	v12[0] *= originalDistance / euclideanDistance;
	v12[1] *= originalDistance / euclideanDistance;
	v12[2] *= originalDistance / euclideanDistance;

	v13[0] = (v1[0] + v3[0]) / 2;
	v13[1] = (v1[1] + v3[1]) / 2;
	v13[2] = (v1[2] + v3[2]) / 2;

	euclideanDistance = sqrt(pow(v13[0], 2) + pow(v13[1], 2) + pow(v13[2], 2));

	v13[0] *= originalDistance / euclideanDistance;
	v13[1] *= originalDistance / euclideanDistance;
	v13[2] *= originalDistance / euclideanDistance;

	v23[0] = (v2[0] + v3[0]) / 2;
	v23[1] = (v2[1] + v3[1]) / 2;
	v23[2] = (v2[2] + v3[2]) / 2;

	euclideanDistance = sqrt(pow(v23[0], 2) + pow(v23[1], 2) + pow(v23[2], 2));

	v23[0] *= originalDistance / euclideanDistance;
	v23[1] *= originalDistance / euclideanDistance;
	v23[2] *= originalDistance / euclideanDistance;

	recursiveSubdivision(v1, v12, v13, depth - 1);
	recursiveSubdivision(v2, v12, v23, depth - 1);
	recursiveSubdivision(v3, v13, v23, depth - 1);
	recursiveSubdivision(v12, v13, v23, depth - 1);
}

void Sphere::octhedron()
{
	glTranslatef(0.f, 0.f, -35.f);
	glRotatef(15.0, 0.1, 0.1, 0.0);

	glBegin(GL_TRIANGLES);

	int depth = 6;

	//Top Front
	recursiveSubdivision(pointA, pointE, pointB, depth);

	//Top Right
	recursiveSubdivision(pointA, pointB, pointC, depth);

	//Top Back
	recursiveSubdivision(pointA, pointC, pointD, depth);

	//Top Left
	recursiveSubdivision(pointA, pointD, pointE, depth);

	//Bottom Right
	recursiveSubdivision(pointF, pointE, pointB, depth);

	//Bottom Right
	recursiveSubdivision(pointF, pointB, pointC, depth);

	//Bottom Back
	recursiveSubdivision(pointF, pointC, pointD, depth);

	//Bottom Left
	recursiveSubdivision(pointF, pointD, pointE, depth);

	glEnd();
}

void Sphere::Display()
{
	pointA[1] = sphereSize;
	pointB[0] = sphereSize;
	pointC[2] = -sphereSize;
	pointD[0] = -sphereSize;
	pointE[2] = sphereSize;
	pointF[1] = -sphereSize;

	octhedron();
}