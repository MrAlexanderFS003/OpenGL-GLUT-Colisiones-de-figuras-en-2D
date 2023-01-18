#include "Circulo.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void Circulo::RellenoCirculo() {
	glPushMatrix();
	glColor3ub(255,0,0);
	glTranslatef(posX, posY, 0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 20; i += 0.1f) {
		posXC = radio * cos(i);
		posYC = radio * sin(i);
		glVertex2f(posXC, posYC);
	}
	glEnd();
	glPopMatrix();
}

void Circulo::Dibuja() {
	if (pinta == false) {
		glPushMatrix();
		glColor3ub(255, 255, 255);
		glTranslatef(posX, posY, 0);
		glBegin(GL_LINE_STRIP);
		for (float i = 0; i < 20; i += 0.1f) {
			posXC = radio * cos(i);
			posYC = radio * sin(i);
			glVertex2f(posXC, posYC);
		}
		glEnd();
		glPopMatrix();
	}
	else { RellenoCirculo(); }

}

void Circulo::Actualiza() {
	glutPostRedisplay();
}