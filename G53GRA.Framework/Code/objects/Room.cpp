#include "Room.h"

Room::Room() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
}

void Room::Display()
{
	glPushMatrix();

	glTranslatef(0.0f, -50.0f, 0.0f);
	glColor3ub(255, 255, 255);

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	int carpetTx = Scene::GetTexture("./Textures/carpet.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, carpetTx);

	for (int i = -200; i < 3000; i+=100) {
		for (int j = -3000; j < 600; j += 100) {
			glBegin(GL_QUADS);

			glNormal3f(i, 0, j);
			glTexCoord2f(0.f, 0.f);
			glVertex3d(i, 0, j);

			glNormal3f(i + 100, 0, j);
			glTexCoord2f(0.f, 1.f);
			glVertex3d(i + 100, 0, j);

			glNormal3f(i + 100, 0, j + 100);
			glTexCoord2f(1.f, 1.f);
			glVertex3d(i + 100, 0, j + 100);

			glNormal3f(i, 0, j + 100);
			glTexCoord2f(1.f, 0.f);
			glVertex3d(i, 0, j + 100);

			glEnd();
		}
	}

	int brickTx = Scene::GetTexture("./Textures/brick.bmp");
	glBindTexture(GL_TEXTURE_2D, brickTx);

	glBegin(GL_QUADS);
	glNormal3f(3000, 0, -3000);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(3000, 0, -3000);

	glNormal3f(-200, 0, -3000);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-200, 0, -3000);

	glNormal3f(-200, 3000, -3000);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-200, 3000, -3000);

	glNormal3f(3000, 3000, -3000);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(3000, 3000, -3000);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(3000, 0, 600);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(3000, 0, 600);

	glNormal3f(3000, 0, -3000);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(3000, 0, -3000);

	glNormal3f(3000, 3000, -3000);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(3000, 3000, -3000);

	glNormal3f(3000, 3000, 600);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(3000, 3000, 600);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void Room::Update(const double& deltaTime)
{
}

void Room::HandleKey(unsigned char key, int state, int x, int y)
{
}
