#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class Table :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Table();
	void cylinder(float h, float r);
	~Table() {};

	void Display();
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int x, int y);

	void HandleSpecialKey(int key, int state, int x, int y) {}
	void HandleMouse(int button, int state, int x, int y) {}
	void HandleMouseDrag(int x, int y) {}
	void HandleMouseMove(int x, int y) {}

private:
	float xrot, yrot, zrot;
	float scale;
};