#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class Piano :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Piano();
	~Piano() {};

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
	int pedalOne = 0;
	int pedalTwo = 0;
	int pedalThree = 0;
	int userControl = 0;
	double time = 0;
};

void keys();

void pedal(int pressed);
