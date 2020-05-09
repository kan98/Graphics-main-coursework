#include "Chair.h"

Chair::Chair() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
}

void Chair::chairLegs() {
	glBegin(GL_POLYGON);
	glVertex3d(0, 50, 100);
	glVertex3d(0, 50, -100);
	glVertex3d(-20, 50, -100);
	glVertex3d(-20, 50, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(0, 50, 100);
	glVertex3d(0, 0, 100);
	glVertex3d(-20, 0, 100);
	glVertex3d(-20, 50, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(0, 50, -100);
	glVertex3d(0, 0, -100);
	glVertex3d(-20, 0, -100);
	glVertex3d(-20, 50, -100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(-20, 50, 100);
	glVertex3d(-20, 0, 100);
	glVertex3d(-20, 0, -100);
	glVertex3d(-20, 50, -100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(0, 50, 100);
	glVertex3d(0, 0, 100);
	glVertex3d(0, 0, -100);
	glVertex3d(0, 50, -100);
	glEnd();
}

void Chair::Display()
{
	glPushMatrix();

	glTranslatef(150.0f, 0.0f, -50.0f);
	glColor3ub(0, 0, 0);

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	// Where you sit on
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3d(-100, -1, 100);
	glVertex3d(-100, -1, -100);
	glVertex3d(100, -1, -100);
	glVertex3d(100, -1, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(-100, 30, 100);
	glVertex3d(-100, 30, -100);
	glVertex3d(100, 30, -100);
	glVertex3d(100, 30, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(-100, -1, 100);
	glVertex3d(-100, 30, 100);
	glVertex3d(100, 30, 100);
	glVertex3d(100, -1, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(-100, -1, -100);
	glVertex3d(-100, 30, -100);
	glVertex3d(100, 30, -100);
	glVertex3d(100, -1, -100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(100, -1, 100);
	glVertex3d(100, 30, 100);
	glVertex3d(100, 30, -100);
	glVertex3d(100, -1, -100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(-100, -1, 100);
	glVertex3d(-100, 30, 100);
	glVertex3d(-100, 30, -100);
	glVertex3d(-100, -1, -100);
	glEnd();

	//legs
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(100, 50, 100);
	chairLegs();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(-80, 50, 100);
	chairLegs();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(100, -100, 100);
	chairLegs();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(-80, -100, 100);
	chairLegs();
	glPopMatrix();

	glTranslated(100, 30, 0);
	glRotated(-15, 0, 0, 1);
	glRotated(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3d(-100, 0, 0);
	glVertex3d(-100, 250, 0);
	glVertex3d(100, 250, 0);
	glVertex3d(100, 0, 0);
	glEnd();

	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void Chair::Update(const double& deltaTime)
{
	//zrot += 10.0f * static_cast<float>(deltaTime);
}

void Chair::HandleKey(unsigned char key, int state, int x, int y)
{
	switch (key)
	{
	case 'i':
		scale += 0.1f;
		break;
	case 'k':
		scale -= 0.1f;
		break;
	default:
		break;
	}
}