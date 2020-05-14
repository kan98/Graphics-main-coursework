#include "Table.h"
#include <Utility\VectorMath.h>

Table::Table() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
}

void Table::cylinder(float h, float r)
{
	float res = 0.1 * M_PI;
	float x = r, z = 0.f;
	float t = 0.f;

	do
	{
		glBegin(GL_QUADS);

		glNormal3f(x, h, z);    // top
		glTexCoord2f(0.f, 1.f);
		glVertex3f(x, h, z);

		glNormal3f(x, 0.f, z);  // bottom
		glTexCoord2f(0.f, 0.f);
		glVertex3f(x, 0.f, z);

		// Iterate around circle
		const float tc = (t / (float)(2 * M_PI));

		t += res;               // add increment to angle
		x = r * cos(t);           // move x and z around circle
		z = r * sin(t);
		// Close quad
		glNormal3f(x, 0.f, z);  // bottom
		glTexCoord2f(tc, 0.f);
		glVertex3f(x, 0.f, z);

		glNormal3f(x, h, z);    // top
		glTexCoord2f(tc, 1.f);
		glVertex3f(x, h, z);
		glEnd();
	} while (t <= 2 * M_PI);        // for 360 degrees
}

void Table::Display()
{
	glPushMatrix();

	glTranslatef(135.0f, 20.0f, -60.0f);
	glColor3ub(255, 255, 255);

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	int tableTx = Scene::GetTexture("./Textures/table-wood.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, tableTx);

	glBegin(GL_QUADS);
	glNormal3f(250, 0, 400);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(250, 0, 400);

	glNormal3f(250, 0, -400);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(250, 0, -400);

	glNormal3f(-250, 0, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-250, 0, -400);

	glNormal3f(-250, 0, 400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-250, 0, 400);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-250, 0, 400);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-250, 70, 400);

	glNormal3f(-250, 0, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-250, 70, -400);

	glNormal3f(250, 0, -400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(250, 70, -400);

	glNormal3f(250, 0, 400);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(250, 70, 400);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-250, 70, 400);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-250, 70, 400);

	glNormal3f(-250, 0, 400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-250, 0, 400);

	glNormal3f(250, 0, 400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(250, 0, 400);

	glNormal3f(250, 70, 400);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(250, 70, 400);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-250, 70, -400);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-250, 70, -400);

	glNormal3f(-250, 0, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-250, 0, -400);

	glNormal3f(250, 0, -400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(250, 0, -400);

	glNormal3f(250, 70, -400);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(250, 70, -400);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(250, 70, -400);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(250, 70, -400);

	glNormal3f(250, 0, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(250, 0, -400);

	glNormal3f(250, 0, 400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(250, 0, 400);

	glNormal3f(250, 70, 400);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(250, 70, 400);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-250, 70, -400);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-250, 70, -400);

	glNormal3f(-250, 0, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-250, 0, -400);

	glNormal3f(-250, 0, 400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-250, 0, 400);

	glNormal3f(-250, 70, 400);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-250, 70, 400);
	glEnd();

	int legsTx = Scene::GetTexture("./Textures/legs.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, legsTx);

	glPushMatrix();
	glTranslatef(200.0f, 0.0f, 350.0f);
	cylinder(-300, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-200.0f, 0.0f, 350.0f);
	cylinder(-300, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0f, 0.0f, -350.0f);
	cylinder(-300, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-200.0f, 0.0f, -350.0f);
	cylinder(-300, 30);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void Table::Update(const double& deltaTime)
{
}

void Table::HandleKey(unsigned char key, int state, int x, int y)
{
}