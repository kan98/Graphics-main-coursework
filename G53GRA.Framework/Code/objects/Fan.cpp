#include "Fan.h"
#include "Table.h"
#include "Sphere.h"

Fan::Fan() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
}

void Fan::Display()
{
	glPushMatrix();

	glTranslatef(50.0f, -40.0f, -300.0f);
	glColor3ub(255, 255, 255);

	int metalTx = Scene::GetTexture("./Textures/metal.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, metalTx);

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	glRotatef(90, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	drawCircle(100, GL_POLYGON);
	glPopMatrix();

	Table table;
	table.cylinder(700, 30);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glColor3ub(55, 55, 55);

	glTranslatef(10.0f, 725.0f, 35.f);
	Sphere sphere(50);
	sphere.Display();
	
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);

	glLineWidth(2);

	drawCircle(225, GL_LINE_STRIP);

	glPushMatrix();

	for (int i = 0; i < 4; i++) {
		glBegin(GL_LINE_STRIP);
		for (float j = 0; j < 225 * 1000; j++) {
			float zValue = j;
			if (zValue > (225 * 1000) / 2) {
				zValue = (225 * 1000) - j;
			}

			float ratio = zValue / 112500;
			zValue *= 1 - (0.5 * ratio);

			glVertex3f(0, j / 1000, -zValue / 700);
		}
		glEnd();
		glRotatef(90, 0.0f, 0.0f, 1.0f);
	}

	glPopMatrix();

	glPushMatrix();

	for (int i = 0; i < 4; i++) {
		glBegin(GL_LINE_STRIP);
		for (float j = 0; j < 225 * 1000; j++) {
			float zValue = j;
			if (zValue > (225 * 1000) / 2) {
				zValue = (225 * 1000) - j;
			}

			float ratio = zValue / 112500;
			zValue *= 1 - (0.5 * ratio);

			glVertex3f(0, j / 1000, zValue / 700);
		}
		glEnd();
		glRotatef(90, 0.0f, 0.0f, 1.0f);
	}

	glPopMatrix();

	glLineWidth(1);

	int bladeTx = Scene::GetTexture("./Textures/plastic.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, bladeTx);

	glColor3ub(255, 255, 255);

	// Fan Blades
	glRotatef(time, 0.0f, 0.0f, 1.0f);
	for (int i = 0; i < 6; i++) {
		glRotatef(60, 0.0f, 0.0f, 1.0f);
		fanBlade();
	}
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void fanBlade() {
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	glNormal3f(35, 35, 0);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(35, 35, 0);

	glNormal3f(150, 75, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(150, 75, 0);

	glNormal3f(75, 150, 0);
	glTexCoord2f(0.0f, 1.f);
	glVertex3d(75, 150, 0);
	glEnd();

	glTranslatef(112.5f, 112.5f, 0.0f);

	drawCircle(50, GL_POLYGON);

	glPopMatrix();
}

void drawCircle(int scale, GLenum drawType)
{
	glBegin(drawType);
	for (int i = 0; i <= 300; i++) {
		double theta = 2 * 3.1415 * i / 300;
		float tx = (scale * cos(theta)) * 0.5 + 0.5;
		float ty = (scale * sin(theta)) * 0.5 + 0.5;
		glTexCoord2f(tx, ty);
		glVertex2d(scale * cos(theta), scale * sin(theta));
	}
	glEnd();
}

void Fan::Update(const double& deltaTime)
{
	time += speed;
}

void Fan::HandleKey(unsigned char key, int state, int x, int y)
{
	switch (key)
	{
	case 'i':
		if (speed < 20.f) {
			speed += 0.5f;
		}
		break;
	case 'k':
		if (speed > 0.f) {
			speed -= 0.5f;
		}
		break;
	default:
		break;
	}
}