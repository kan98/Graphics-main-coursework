#include "Room.h"

Room::Room() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
}

void Room::lighting() {
	float mat_ambient[] = { 1.f, 0.83f, 0.65f, 0.5f };
	float mat_diffuse[] = { 1.f, 0.63f, 0.45f, 0.5f };
	float mat_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };

	float ambient1[] = { 1.f, 0.83f, 0.55f, 0.5f };
	float diffuse1[] = { 1.f, 1.f, 1.f, 1.0f };
	float specular1[] = { 1.f, 1.f, 1.f, 1.0f };
	float position1[] = { 0.0f, 700.0f, 0.0f, 1.0f };
	float position2[] = { 0.0f, 700.0f, 0.0f, 1.0f };
	float spot_direction[] = { 0.0f, -1.0f, 0.0f };

	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);
	glLightfv(GL_LIGHT0, GL_POSITION, position1);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.7);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 35);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0f);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
}

void Room::Display()
{
	glPushMatrix();

	glTranslatef(0.0f, -50.0f, 0.0f);
	glColor3ub(255, 255, 255);

	lighting();

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	int carpetTx = Scene::GetTexture("./Textures/carpet.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, carpetTx);

	for (int i = -200; i < 3000; i+=1600) {
		for (int j = -3000; j < 400; j += 1200) {
			glBegin(GL_QUADS);

			glNormal3f(0, 1, 0);
			glTexCoord2f(0.f, 0.f);
			glVertex3d(i, 0, j);

			glTexCoord2f(0.f, 1.f);
			glVertex3d(i + 1600, 0, j);

			glTexCoord2f(1.f, 1.f);
			glVertex3d(i + 1600, 0, j + 1200);

			glTexCoord2f(1.f, 0.f);
			glVertex3d(i, 0, j + 1200);

			glEnd();
		}
	}

	int brickTx = Scene::GetTexture("./Textures/brick.bmp");
	glBindTexture(GL_TEXTURE_2D, brickTx);

	for (int i = -200; i < 3000; i += 800) {
		for (int j = 0; j < 3000; j += 1000) {
			glBegin(GL_QUADS);

			glNormal3f(0, 0, 1);
			glTexCoord2f(0.f, 0.f);
			glVertex3d(i, j, -3000);

			glTexCoord2f(1.f, 0.f);
			glVertex3d(i + 800, j, -3000);

			glTexCoord2f(1.f, 1.f);
			glVertex3d(i + 800, j + 1000, -3000);

			glTexCoord2f(0.f, 1.f);
			glVertex3d(i, j + 1000, -3000);

			glEnd();
		}
	}

	for (int i = 0; i < 3000; i += 1000) {
		for (int j = -3000; j < 400; j += 1200) {
			glBegin(GL_QUADS);

			glNormal3f(0, 0, 1);
			glTexCoord2f(0.f, 0.f);
			glVertex3d(3000, i, j + 1200);

			glTexCoord2f(1.f, 0.f);
			glVertex3d(3000, i, j);

			glTexCoord2f(1.f, 1.f);
			glVertex3d(3000, i + 1000, j);

			glTexCoord2f(0.f, 1.f);
			glVertex3d(3000, i + 1000, j + 1200);

			glEnd();
		}
	}

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
