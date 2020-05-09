#include "Table.h"
#include <Utility\VectorMath.h>

Table::Table() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
}

void Table::cylinder(float h, float r)
{
	float res = 0.1 * M_PI;           // resolution (in radians: equivalent to 18 degrees)
	float x = r, z = 0.f;           // initialise x and z on right of cylinder centre
	float t = 0.f;                  // initialise angle as 0

	do
	{
		glBegin(GL_QUADS);          // new QUAD
			// Create first points
		glVertex3f(x, h, z);    // top
		glVertex3f(x, 0.f, z);  // bottom
		// Iterate around circle
		t += res;               // add increment to angle
		x = r * cos(t);           // move x and z around circle
		z = r * sin(t);
		// Close quad
		glVertex3f(x, 0.f, z);  // bottom
		glVertex3f(x, h, z);    // top
		glEnd();                    // end shape
	} while (t <= 2 * M_PI);        // for a full circle (360 degrees)
}

void Table::Display()
{
	glPushMatrix();

	glTranslatef(70.0f, 0.0f, -60.0f);
	glColor3ub(150, 150, 150);

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	int tableTx = Scene::GetTexture("./Textures/table-wood.bmp");
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

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

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glColor3ub(0, 0, 0);

	glPushMatrix();
	glTranslatef(200.0f, 0.0f, 350.0f);
	cylinder(-200, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-200.0f, 0.0f, 350.0f);
	cylinder(-200, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0f, 0.0f, -350.0f);
	cylinder(-200, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-200.0f, 0.0f, -350.0f);
	cylinder(-200, 30);
	glPopMatrix();

	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void Table::Update(const double& deltaTime)
{
	//zrot += 10.0f * static_cast<float>(deltaTime);
}

void Table::HandleKey(unsigned char key, int state, int x, int y)
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