#include "Chair.h"

Chair::Chair(int chairNumber) : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.2f) {
	chairNo = chairNumber;
}

void Chair::chairLegs()
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(0, 50, 100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(0, 50, -100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(-20, 50, -100);

	glTexCoord2f(0.f, 1.f);
	glVertex3d(-20, 50, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(0, 50, 100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(0, 0, 100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(-20, 0, 100);

	glTexCoord2f(0.f, 1.f);
	glVertex3d(-20, 50, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(0, 50, -100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(0, 0, -100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(-20, 0, -100);

	glTexCoord2f(0.f, 1.f);
	glVertex3d(-20, 50, -100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-20, 50, 100);

	glTexCoord2f(0.f, 1.f);
	glVertex3d(-20, 0, 100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(-20, 0, -100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(-20, 50, -100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(0, 50, 100);

	glTexCoord2f(0.f, 1.f);
	glVertex3d(0, 0, 100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(0, 0, -100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(0, 50, -100);
	glEnd();
}

void Chair::Display()
{
	glPushMatrix();

	int leatherTx = Scene::GetTexture("./Textures/leather.bmp");
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, leatherTx);

	if (chairNo == 0) {
		glTranslatef(200.0f, 0.0f, -50.0f);
	}
	else {
		glTranslatef(75.0f, 0.0f, -50.0f);
		glRotatef(180, 0.0f, 1.0f, 0.0f);
	}

	glColor3ub(255, 255, 255);

	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	glScalef(scale, scale, scale);

	glDisable(GL_CULL_FACE);

	// Chair seat
	glPushMatrix();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-100, -1, 100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(-100, -1, -100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(100, -1, -100);

	glTexCoord2f(1.f, 1.f);
	glVertex3d(100, -1, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-100, 30, 100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(-100, 30, -100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(100, 30, -100);

	glTexCoord2f(1.f, 1.f);
	glVertex3d(100, 30, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-100, -1, 100);

	glTexCoord2f(0.f, 1.f);
	glVertex3d(-100, 30, 100);

	glTexCoord2f(1.f, 1.f);
	glVertex3d(100, 30, 100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(100, -1, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-100, -1, -100);

	glTexCoord2f(0.f, 1.f);
	glVertex3d(-100, 30, -100);

	glTexCoord2f(1.f, 1.f);
	glVertex3d(100, 30, -100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(100, -1, -100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(100, -1, 100);

	glTexCoord2f(1.f, 1.f);
	glVertex3d(100, 30, 100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(100, 30, -100);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(100, -1, -100);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-100, -1, 100);

	glTexCoord2f(1.f, 1.f);
	glVertex3d(-100, 30, 100);

	glTexCoord2f(1.f, 0.f);
	glVertex3d(-100, 30, -100);

 	glTexCoord2f(0.f, 0.f);
	glVertex3d(-100, -1, -100);
	glEnd();

	//legs
	glPopMatrix();

	int legsTx = Scene::GetTexture("./Textures/legs.bmp");
	glBindTexture(GL_TEXTURE_2D, legsTx);

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

	glBindTexture(GL_TEXTURE_2D, leatherTx);

	// Back seat
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-100, 0, 0);

	glNormal3f(-100, 250, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-100, 250, 0);

	glNormal3f(100, 250, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(100, 250, 0);

	glNormal3f(100, 0, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(100, 0, 0);
	glEnd();

	glEnable(GL_CULL_FACE);

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void Chair::Update(const double& deltaTime)
{
}

void Chair::HandleKey(unsigned char key, int state, int x, int y)
{
}