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
	glNormal3f(-700, -400, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-700, -400, -400);

	glNormal3f(-700, 400, -400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-700, 400, -400);

	glNormal3f(-700, 400, -500);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-700, 400, -500);

	glNormal3f(-700, -400, -500);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-700, -400, -500);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(700, -400, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(700, -400, -400);

	glNormal3f(700, 400, -400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(700, 400, -400);

	glNormal3f(700, 400, -500);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(700, 400, -500);

	glNormal3f(700, -400, -500);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(700, -400, -500);
	glEnd();

	//Top bit
	glPushMatrix();
	glTranslatef(0.f, 1000.f, 0.f);
	glBegin(GL_QUADS);
	glNormal3f(-900, 30, 0);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-900, 30, 0);

	glNormal3f(-900, 30, -600);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-900, 30, -600);

	glNormal3f(900, 30, -600);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(900, 30, -600);

	glNormal3f(900, 30, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(900, 30, 0);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-900, 0, -600);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-900, 0, -600);

	glNormal3f(-900, 30, -600);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-900, 30, -600);

	glNormal3f(900, 30, -600);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(900, 30, -600);

	glNormal3f(900, 0, -600);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(900, 0, -600);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(900, 0, 0);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(900, 0, 0);

	glNormal3f(900, 0, -600);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(900, 0, -600);

	glNormal3f(900, 30, -600);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(900, 30, -600);

	glNormal3f(900, 30, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(900, 30, 0);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-900, 0, 0);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-900, 0, 0);

	glNormal3f(-900, 0, -600);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-900, 0, -600);

	glNormal3f(-900, 30, -600);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-900, 30, -600);

	glNormal3f(-900, 30, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-900, 30, 0);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-900, 0, 0);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-900, 0, 0);

	glNormal3f(-900, 0, -600);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-900, 0, -600);

	glNormal3f(900, 0, -600);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(900, 0, -600);

	glNormal3f(900, 0, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(900, 0, 0);
	glEnd();

	glPopMatrix();

	// Pedals
	glPushMatrix();
	glTranslatef(0.f, -350.f, -400.f);
	int pedalTx = Scene::GetTexture("./Textures/pedal.bmp");
	glBindTexture(GL_TEXTURE_2D, pedalTx);

	glPushMatrix();
	glTranslatef(-150.f, 0.f, 0.f);
	pedal();
	glPopMatrix();

	pedal();

	glPushMatrix();
	glTranslatef(150.f, 0.f, 0.f);
	pedal();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, pianoTx);
	glPopMatrix();

	//Middle bit
	glPushMatrix();
	glTranslatef(0.f, 400.f, 0.f);

	glBegin(GL_QUADS);
	glNormal3f(-800, 600, -200);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, 600, -200);

	glNormal3f(-800, 0, -400);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, 0, -400);

	glNormal3f(800, 0, -400);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(800, 0, -400);

	glNormal3f(800, 600, -200);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(800, 600, -200);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-800, 0, -700);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, 0, -700);

	glNormal3f(-800, -200, -700);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, -200, -700);

	glNormal3f(800, -200, -700);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(800, -200, -700);

	glNormal3f(800, 0, -700);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(800, 0, -700);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-800, 0, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, 0, 0);

	glNormal3f(-800, 0, -700);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, 0, -700);

	glNormal3f(800, 0, -700);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(800, 0, -700);

	glNormal3f(800, 0, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(800, 0, 0);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-800, -200, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, -200, 0);

	glNormal3f(-800, -200, -700);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, -200, -700);

	glNormal3f(800, -200, -700);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(800, -200, -700);

	glNormal3f(800, -200, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(800, -200, 0);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(800, 0, -500);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(800, 0, -500);

	glNormal3f(800, 0, -700);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(800, 0, -700);

	glNormal3f(800, -200, -700);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(800, -200, -700);

	glNormal3f(800, -200, -500);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(800, -200, -500);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-800, 0, -500);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-800, 0, -500);

	glNormal3f(-800, 0, -700);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-800, 0, -700);

	glNormal3f(-800, -200, -700);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-800, -200, -700);

	glNormal3f(-800, -200, -500);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-800, -200, -500);
	glEnd();

	keys();

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void keys() {
	int keysTx = Scene::GetTexture("./Textures/piano-keys.bmp");
	glBindTexture(GL_TEXTURE_2D, keysTx);

	glBegin(GL_QUADS);
	glNormal3f(-750, 20, -500);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-750, 20, -500);

	glNormal3f(-750, 20, -675);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-750, 20, -675);

	glNormal3f(750, 20, -675);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(750, 20, -675);

	glNormal3f(750, 20, -500);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(750, 20, -500);
	glEnd();
}

void pedal() {
	glBegin(GL_QUADS);
	glNormal3f(-40, 0, -150);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-40, 0, -150);

	glNormal3f(-30, 0, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-30, 0, 0);

	glNormal3f(30, 0, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(30, 0, 0);

	glNormal3f(40, 0, -150);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(40, 0, -150);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-40, -20, -150);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-40, -20, -150);

	glNormal3f(-30, 0, -150);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-30, 0, -150);

	glNormal3f(-30, 0, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(-30, 0, 0);

	glNormal3f(-40, -20, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(-40, -20, 0);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(40, -20, -150);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(40, -20, -150);

	glNormal3f(30, 0, -150);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(30, 0, -150);

	glNormal3f(30, 0, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(30, 0, 0);

	glNormal3f(40, -20, 0);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(40, -20, 0);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-40, -20, -150);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-40, -20, -150);

	glNormal3f(-40, 0, -150);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-40, 0, -150);

	glNormal3f(40, 0, -150);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(40, 0, -150);

	glNormal3f(40, -20, -150);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(40, -20, -150);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-40, -20, -150);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(-40, -20, -150);

	glNormal3f(-30, -20, 0);
	glTexCoord2f(0.f, 1.f);
	glVertex3d(-30, -20, 0);

	glNormal3f(30, -20, 0);
	glTexCoord2f(1.f, 1.f);
	glVertex3d(30, -20, 0);

	glNormal3f(40, -20, -150);
	glTexCoord2f(1.f, 0.f);
	glVertex3d(40, -20, -150);
	glEnd();
}

void Piano::Update(const double& deltaTime)
{
}

void Piano::HandleKey(unsigned char key, int state, int x, int y)
{
}