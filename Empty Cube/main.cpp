#include <stdio.h>
#include <GL/glut.h>
#include <cmath>
#include <vector>


int WindW, WindH;
int i;
int alpha, beta, gamma;
std::vector<float> vex = {-0.77f, -0.27f, 0.79f, -0.79f, 0.52f};


void Reshape(int width, int height) // Reshape function
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);

  WindW = width;
  WindH = height;
}

void camera_move(int key, int x, int y) {

	switch(key){
		case(GLUT_KEY_UP):
			alpha -= 4;
			break;
		case(GLUT_KEY_DOWN):
			alpha += 4;
			break;
		case(GLUT_KEY_RIGHT):
			beta += 4;
			break;
		case(GLUT_KEY_LEFT):
			beta -= 4;
			break;
		case(GLUT_KEY_PAGE_UP):
			gamma += 4;
			break;
		case(GLUT_KEY_PAGE_DOWN):
			gamma -= 4;
			break;
	}

}

void Draw(void) // Window redraw function
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glColor3f(255.0f, 255.0f, 255.0f);

  glPushMatrix();
  glTranslatef(0, 0, -3.5);
  glRotatef(alpha, 1.0f, 0.0f, 0.0f);
  glRotatef(beta, 0.0f, 1.0f, 0.0f);
  glRotatef(gamma, 0.0f, 0.0f, 1.0f);
  //alpha += 4;
  //if (alpha > 359) alpha = 0;
  glBegin(GL_QUADS);

  for(int i = 0; i < 3; ++i){
	  for(int j = 0; j < 3; ++j){
		  glVertex3f(vex[0] + i * vex[4], vex[1] + j * vex[4], vex[3]);
	      glVertex3f(vex[1] + i * vex[4], vex[1] + j * vex[4], vex[3]);
	      glVertex3f(vex[1] + i * vex[4], vex[0] + j * vex[4], vex[3]);
	      glVertex3f(vex[0] + i * vex[4], vex[0] + j * vex[4], vex[3]);
	      glVertex3f(vex[0] + i * vex[4], vex[1] + j * vex[4], vex[2]);
  	      glVertex3f(vex[1] + i * vex[4], vex[1] + j * vex[4], vex[2]);
  	      glVertex3f(vex[1] + i * vex[4], vex[0] + j * vex[4], vex[2]);
  	      glVertex3f(vex[0] + i * vex[4], vex[0] + j * vex[4], vex[2]);
	  }
  }for(int i = 0; i < 3; ++i){
	  for(int j = 0; j < 3; ++j){
		  glVertex3f(vex[0] + i * vex[4], vex[2], vex[1] + j * vex[4]);
	      glVertex3f(vex[1] + i * vex[4], vex[2], vex[1] + j * vex[4]);
	      glVertex3f(vex[1] + i * vex[4], vex[2], vex[0] + j * vex[4]);
	      glVertex3f(vex[0] + i * vex[4], vex[2], vex[0] + j * vex[4]);
	      glVertex3f(vex[0] + i * vex[4], vex[3], vex[1] + j * vex[4]);
  	      glVertex3f(vex[1] + i * vex[4], vex[3], vex[1] + j * vex[4]);
  	      glVertex3f(vex[1] + i * vex[4], vex[3], vex[0] + j * vex[4]);
  	      glVertex3f(vex[0] + i * vex[4], vex[3], vex[0] + j * vex[4]);
	  }
  }for(int i = 0; i < 3; ++i){
	  for(int j = 0; j < 3; ++j){
		  glVertex3f(vex[2], vex[0] + i * vex[4], vex[1] + j * vex[4]);
	      glVertex3f(vex[2], vex[1] + i * vex[4], vex[1] + j * vex[4]);
	      glVertex3f(vex[2], vex[1] + i * vex[4], vex[0] + j * vex[4]);
	      glVertex3f(vex[2], vex[0] + i * vex[4], vex[0] + j * vex[4]);
	      glVertex3f(vex[3], vex[0] + i * vex[4], vex[1] + j * vex[4]);
  	      glVertex3f(vex[3], vex[1] + i * vex[4], vex[1] + j * vex[4]);
  	      glVertex3f(vex[3], vex[1] + i * vex[4], vex[0] + j * vex[4]);
  	      glVertex3f(vex[3], vex[0] + i * vex[4], vex[0] + j * vex[4]);
	  }
  }
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex3f(vex[0] + 0.01f, vex[0] + 0.01f, vex[2] - 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[0] + 0.01f, vex[2] - 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[0] + 1.53f, vex[2] - 0.01f);
  glVertex3f(vex[0] + 0.01f, vex[0] + 1.53f, vex[2] - 0.01f);

  glVertex3f(vex[0] + 0.01f, vex[0] + 0.01f, vex[3] + 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[0] + 0.01f, vex[3] + 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[0] + 1.53f, vex[3] + 0.01f);
  glVertex3f(vex[0] + 0.01f, vex[0] + 1.53f, vex[3] + 0.01f);

  glVertex3f(vex[0] + 0.01f, vex[2] - 0.01f, vex[0] + 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[2] - 0.01f, vex[0] + 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[2] - 0.01f, vex[0] + 1.53f);
  glVertex3f(vex[0] + 0.01f, vex[2] - 0.01f, vex[0] + 1.53f);

  glVertex3f(vex[0] + 0.01f, vex[3] + 0.01f, vex[0] + 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[3] + 0.01f, vex[0] + 0.01f);
  glVertex3f(vex[0] + 1.53f, vex[3] + 0.01f, vex[0] + 1.53f);
  glVertex3f(vex[0] + 0.01f, vex[3] + 0.01f, vex[0] + 1.53f);

  glVertex3f(vex[2] - 0.01f, vex[0] + 0.01f, vex[0] + 0.01f);
  glVertex3f(vex[2] - 0.01f, vex[0] + 1.53f, vex[0] + 0.01f);
  glVertex3f(vex[2] - 0.01f, vex[0] + 1.53f, vex[0] + 1.53f);
  glVertex3f(vex[2] - 0.01f, vex[0] + 0.01f, vex[0] + 1.53f);

  glVertex3f(vex[3] + 0.01f, vex[0] + 0.01f, vex[0] + 0.01f);
  glVertex3f(vex[3] + 0.01f, vex[0] + 1.53f, vex[0] + 0.01f);
  glVertex3f(vex[3] + 0.01f, vex[0] + 1.53f, vex[0] + 1.53f);
  glVertex3f(vex[3] + 0.01f, vex[0] + 0.01f, vex[0] + 1.53f);
  glEnd();

  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void Visibility(int state) // Visibility function
{
  if (state == GLUT_NOT_VISIBLE) printf("Window not visible!\n");
  if (state == GLUT_VISIBLE) printf("Window visible!\n");
}

void timf(int value) // Timer function
{
  glutPostRedisplay();  // Redraw windows
  glutTimerFunc(40, timf, 0); // Setup next timer
}

int main(int argc, char *argv[])
{
  WindW = 500;
  WindH = 500;
  alpha = 0;

  glutInit(&argc, argv);
  glutInitWindowSize(WindW, WindH);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  (void)glutCreateWindow("cube");
  glEnable(GL_DEPTH_TEST);
  glFrustum(-1,1, -1,1, 2,30);
  glutReshapeFunc(Reshape); // Set up reshape function
  glutDisplayFunc(Draw);    // Set up redisplay function
  glutTimerFunc(40, timf, 0); // Set up timer for 40ms, about 25 fps
  glutVisibilityFunc(Visibility); // Set up visibility funtion
  glClearColor(0, 0, 0, 0);
  glutSpecialFunc(camera_move);

  glutMainLoop();

  return 0;
}
