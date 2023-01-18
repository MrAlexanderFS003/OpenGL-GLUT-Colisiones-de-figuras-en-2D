
/*
	Hecho por Max Flores Saldaña , Usando la programación orientada a Objetos en C++.
	Si desea ver la documentacion de GLUT: https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
*/

/// CODIGO REUTILIZADO DE https://github.com/MrAlexanderFS003/OpenGL-GLUT-Movimiento-de-la-figura-con-raton

#include "Circulo.h"
#include "Texto.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

// Variables que usaremos para calcular la posicion de raton y el tamaño de la ventana
#define ANCHO 800
#define ALTO 600

//Crea Objetos
Circulo cir;
Texto txt;

//Variables usadas para almacenar los calculos obtenidos
float objX = 0.0f, objY = 0.0f, MobjX = 0.0f, MobjY = 0.0f;
int valor = 0;

//Varibles para la creacion del circulo y calculos
float posX2 = 0.0f, posY2 = 0.0f;
int radio2 = 5;
bool pinta2;
float distancia = 0.0f;

//Variables para convertir numeros a texto
int dist = 0;
string temp;
const char* txtDist;

void Iniciar() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
}

void SegunCircRelleno() {
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 20; i += 0.1f) {
		posX2 = radio2 * cos(i);
		posY2 = radio2 * sin(i);
		glVertex2f(posX2, posY2);
	}
	glEnd();

	glColor3ub(255,255,255);
	//Centro a Centro
	glBegin(GL_LINES);
	glVertex2f(cir.getPosX(), cir.getPosY());
	glVertex2f(0, 0); // En este caso la posicion del 2do ciruclo esta en el origen de las coordenadas
	glEnd();
	glPopMatrix();
}

void SegundoCirculo() {
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINE_STRIP);
	for (float i = 0; i < 20; i += 0.1f) {
		posX2 = radio2 * cos(i);
		posY2 = radio2 * sin(i);
		glVertex2f(posX2, posY2);
	}
	glEnd();

	//Centro a Centro
	glBegin(GL_LINES);
	glVertex2f(cir.getPosX(),cir.getPosY());
	glVertex2f(0,0); // En este caso la posicion del 2do ciruclo esta en el origen de las coordenadas
	glEnd();
	glPopMatrix();
}

void InformacionPantalla() {
	glPushMatrix();
	glColor3ub(255,255,255);
	txt.printw(2,-30,40,0," Radio 1 = 5  Radio 2 = 5");

	dist = distancia;
	temp = "Distancia: " + to_string(dist);
	txtDist = temp.c_str();
	txt.printw(2,5,40,0,txtDist);
	glPopMatrix();
}

void Dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);
	cir.Dibuja();
	InformacionPantalla();
	if (pinta2 == false) { SegundoCirculo(); }
	else { SegunCircRelleno(); }
	glutSwapBuffers();
}

void Actualiza() {
	//Colision
	//Calculando la distancia entre dos puntos
	distancia = sqrt(pow(cir.getPosX() - 0, 2) + pow(cir.getPosY() - 0,2));
	if (distancia <= 10) {
		cir.setPinta(true);
		pinta2 = true;
	}
	else {
		cir.setPinta(false);
		pinta2 = false;
	}
	glutPostRedisplay();
}

//Posicion del raton
void Raton(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		objX = (x - (ANCHO / 2)) * 100 / ANCHO;
		objY = ((ALTO / 2) - y) * 100 / ALTO;
		cir.setPosX(objX);
		cir.setPosY(objY);
		MobjX = objX;
		MobjY = objY;
		valor = state;
	}
}

//Movimiento de la figura en base al raton
void MoverRaton(int x, int y) {
	if (valor) {
		cir.setPosX(MobjX);
		cir.setPosY(MobjY);
	}
	MobjX = (x - (ANCHO / 2)) * 100 / ANCHO;
	MobjY = ((ALTO / 2) - y) * 100 / ALTO;
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("COLISION 2D");

	Iniciar();
	glutDisplayFunc(Dibuja);
	glutMouseFunc(Raton); // Posicion del raton
	glutMotionFunc(MoverRaton); // Movimiento del raton
	glutIdleFunc(Actualiza); 
	glutMainLoop();
	return 0;
}