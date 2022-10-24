#include "cube.h"
#include <time.h>
#include <stdlib.h>
 
#define CUBE_SIZE 13
#define TIMER 30

//                    (верх,      низ,   впереди,   сзади,    лево,      право)
unsigned int c[6] = {0xFFFFFF, 0xFFFF00, 0x0000FF, 0x00FF00, 0xFF0000, 	0xCCFA50};
  
int xRot = 24, yRot = 34, zRot = 0;
double translateZ = -35.0;
cube cube;
int timerOn = 0;
 
void display()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, translateZ);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glTranslatef(CUBE_SIZE / -2.0, CUBE_SIZE / -2.0, CUBE_SIZE / -2.0);
	cube.draw();
	glPopMatrix();
	glutSwapBuffers();
}
 
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat fAspect = (GLfloat)w/(GLfloat)h;
    gluPerspective(60, fAspect, 1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
 
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	
	srand(time(0));
 
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_DEPTH_TEST);
 
	cube.clear(CUBE_SIZE, c);
}
 
void specialKeys(int key, int, int)
{
	if (key == GLUT_KEY_DOWN)
	{
		xRot += 3;
		if (xRot >= 360)
			xRot -= 360;
		glutPostRedisplay();
	}
 
	if (key == GLUT_KEY_UP)
	{
		xRot -= 3;
		if (xRot < 0)
			xRot += 360;
		glutPostRedisplay();
	}
 
	if (key == GLUT_KEY_RIGHT)
	{
		yRot += 3;
		if (yRot >= 360)
			yRot -= 360;
		glutPostRedisplay();
	}
 
	if (key == GLUT_KEY_LEFT)
	{
		yRot -= 3;
		if (yRot < 0)
			yRot += 360;
		glutPostRedisplay();
	}
 
	if (key == GLUT_KEY_HOME)
	{
		translateZ += 5;
		glutPostRedisplay();
	}
 
	if (key == GLUT_KEY_END)
	{
		translateZ -= 5;
		glutPostRedisplay();
	}
 
	if (key == GLUT_KEY_F1)
	{
		cube.clear(CUBE_SIZE, c);
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_F2)
	{
		cube.toFile("statement.txt");
	}
	if (key == GLUT_KEY_F3)
	{
		cube.fromFile("statement.txt");
	}
	if (key == GLUT_KEY_F4){
		cube.check_statement();
	}
	/*if (key == GLUT_KEY_F5){
		cube.solve();
	}*/
}
 
void keys(unsigned char key, int, int)
{
	if (key >= '0' && key < '6')
	{
		cube.rot90(key - '0');
		display();
	}
}
 
void mouse(int key, int state, int, int)
{
	if (key == GLUT_RIGHT_BUTTON)
	{
		timerOn = 1 - timerOn;
	}
}
 
void timer(int)
{
	glutTimerFunc(TIMER, timer, 0);
	if (timerOn)
	{
		keys(rand() % 6 + '0', 0, 0);
	}
	display();
}
 
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(1, 1);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	glutTimerFunc(TIMER, timer, 0);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}