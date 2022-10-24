#include "lilcube.h"

 
lil_Cube::lil_Cube(){
	size = 0.0;
}
 
void lil_Cube::rotate_z(){
	unsigned int tmp = color[5];
	color[5] = color[3];
	color[3] = color[4];
	color[4] = color[2];
	color[2] = tmp;
}
 
void lil_Cube::rotate_y(){
	unsigned int tmp = color[2];
	color[2] = color[1];
	color[1] = color[3];
	color[3] = color[0];
	color[0] = tmp;
}
 
void lil_Cube::rotate_x(){
	unsigned int tmp = color[0];
	color[0] = color[4];
	color[4] = color[1];
	color[1] = color[5];
	color[5] = tmp;
}
 
void lil_Cube::set_color(int i, int color){
	this->color[i] = color;
}
 

void lil_Cube::draw()
{
	glPushMatrix();
	glBegin(GL_QUADS);
 
	// верх
	glColor3ubv(at(0));
	glVertex3f(size, size, size);          
	glVertex3f(0, size, size);          
	glVertex3f(0, 0, size);          
	glVertex3f(size, 0, size);      
 
	// низ
	glColor3ubv(at(1));
	glVertex3f(size, 0, 0);
	glVertex3f(0, 0, 0);   
	glVertex3f(0, size, 0);  
	glVertex3f(size, size, 0);
 
	// перед
	glColor3ubv(at(2));
	glVertex3f(size, 0, size);
	glVertex3f(0, 0, size);   
	glVertex3f(0, 0, 0);      
	glVertex3f(size, 0, 0); 
 
	// зад
	glColor3ubv(at(3));
	glVertex3f(size, size, 0);   
	glVertex3f(0, size, 0);      
	glVertex3f(0, size, size);   
	glVertex3f(size, size, size);
 
	// лево
	glColor3ubv(at(4));
	glVertex3f(0, size, size);   
	glVertex3f(0, size, 0);      
	glVertex3f(0, 0, 0);         
	glVertex3f(0, 0, size);      
 
	// право
	glColor3ubv(at(5));
	glVertex3f(size, size, 0);
	glVertex3f(size, size, size);
	glVertex3f(size, 0, size);   
	glVertex3f(size, 0, 0);      
 
	glEnd();
	glPopMatrix();
}

unsigned char *lil_Cube::at(int i){
	comp_color[0] = color[i] >> 16;
	comp_color[1] = color[i] >>  8;
	comp_color[2] = color[i];
	return comp_color;
}
 
void lil_Cube::draw(double x, double y, double z)
{
	glPushMatrix();
	glTranslated(x, y, z);
	draw();
	glPopMatrix();
}
 
