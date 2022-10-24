#ifndef _LIL_CUBE_H
#define _LIL_CUBE_H
 
#include "gl\glut.h" 

class lil_Cube{
public:
	unsigned int color[6]; 
	unsigned char comp_color[4];
	
	double size;
 
	lil_Cube();
 
	void rotate_z();
	void rotate_y();
	void rotate_x();
 
	void set_color(int i, int color);
	
	void draw();
	void draw(double x, double y, double z);

	
	unsigned char *at(int i);
};
 
 
#endif;