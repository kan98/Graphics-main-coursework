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
	glClearColor(0.f, 0.f, 0.f, 1.f);

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

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1500.0);
}
