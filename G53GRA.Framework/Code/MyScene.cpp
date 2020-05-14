#include "MyScene.h"
#include "objects/Chair.h"
#include "objects/Table.h"
#include "objects/Fan.h"
#include "objects/Piano.h"
#include "objects/Room.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	lighting();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Room* r = new Room();
	AddObjectToScene(r);

	Table* t = new Table();
	AddObjectToScene(t);

	Chair* c = new Chair(0);
	AddObjectToScene(c);

	Chair* c1 = new Chair(1);
	AddObjectToScene(c1);

	Fan* f = new Fan();
	AddObjectToScene(f);

	Piano* p = new Piano();
	AddObjectToScene(p);
}

float ambient1[] = { 1.f, 0.83f, 0.65f, 0.5f };
float diffuse1[] = { 1.f, 1.0f, 1.0f, 1.0f };
float position1[] = { -1000.f, 500.0f, -1000.0f, 1.0f };
float mat_colour[] = { 1.f, 1.f, 1.f, 0.5f };
float mat_ambient[] = { 1.f, 1.f, 1.f, 0.5f };
float spot_direction[] = { 1.f, 1.f, 1.f };

void lighting() {
	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT0, GL_POSITION, position1);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.6);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 35.f);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.f);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1500.0);
}
