#include "Piano.h"

Piano::Piano() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
}

void Piano::Display()
{
	glPushMatrix();

	glTranslatef(550.0f, 30.0f, -200.0f);
	glColor3ub(255, 255, 255);

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	glRotatef(90, 0.0f, 1.0f, 0.0f);

	int pianoTx = Scene::GetTexture("./Textures/piano-black.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, pianoTx);

	//Back Surface
	glBegin(GL_QUADS);
	glNormal3f(-800, -400, 0);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, -400, 0);

	glNormal3f(-800, 1000, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, 1000, 0);

	glNormal3f(800, 1000, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(800, 1000, 0);

	glNormal3f(800, -400, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(800, -400, 0);
	glEnd();


	//Side Pieces
	glBegin(GL_QUADS);
	glNormal3f(-800, -400, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, -400, 0);

	glNormal3f(-800, 1000, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-800, 1000, 0);

	glNormal3f(-800, 1000, -500);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-800, 1000, -500);

	glNormal3f(-800, -400, -500);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, -400, -500);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(800, -400, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(800, -400, 0);

	glNormal3f(800, 1000, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(800, 1000, 0);

	glNormal3f(800, 1000, -500);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(800, 1000, -500);

	glNormal3f(800, -400, -500);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(800, -400, -500);
	glEnd();

	//Middle Bottom
	glBegin(GL_QUADS);
	glNormal3f(-700, -400, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-700, -400, -400);

	glNormal3f(-700, 400, -400);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-700, 400, -400);

	glNormal3f(700, 400, -400);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(700, 400, -400);

	glNormal3f(700, -400, -400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(700, -400, -400);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-800, -400, -500);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, -400, -500);

	glNormal3f(-800, 400, -500);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, 400, -500);

	glNormal3f(-700, 400, -500);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-700, 400, -500);

	glNormal3f(-700, -400, -500);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-700, -400, -500);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(800, -400, -500);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(800, -400, -500);

	glNormal3f(800, 400, -500);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(800, 400, -500);

	glNormal3f(700, 400, -500);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(700, 400, -500);

	glNormal3f(700, -400, -500);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(700, -400, -500);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(-700, -400, -400);
	glVertex3d(-700, 400, -400);
	glVertex3d(-700, 400, -500);
	glVertex3d(-700, -400, -500);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(700, -400, -400);
	glVertex3d(700, 400, -400);
	glVertex3d(700, 400, -500);
	glVertex3d(700, -400, -500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void Piano::Update(const double& deltaTime)
{
	//zrot += 10.0f * static_cast<float>(deltaTime);
}

void Piano::HandleKey(unsigned char key, int state, int x, int y)
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