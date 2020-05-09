#pragma once
#include "DisplayableObject.h"

class Sphere :
	public DisplayableObject
{
public:
	Sphere(int size);
	~Sphere() {};
	int sphereSize;

	void Display();
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int x, int y);

	void HandleSpecialKey(int key, int state, int x, int y) {}
	void HandleMouse(int button, int state, int x, int y) {}
	void HandleMouseDrag(int x, int y) {}
	void HandleMouseMove(int x, int y) {}

private:
	float pointA[3] = { 0.0f, 10.0f, 0.0f };
	float pointB[3] = { 10.0f, 0.0f, 0.0f };
	float pointC[3] = { 0.0f, 0.0f, -10.0f };
	float pointD[3] = { -10.0f, 0.0f, 0.0f };
	float pointE[3] = { 0.0f, 0.0f, 10.0f };
	float pointF[3] = { 0.0f, -10.0f, 0.0f };

	void recursiveSubdivision(float v1[3], float v2[3], float v3[3], int depth);
	void octhedron();
};

