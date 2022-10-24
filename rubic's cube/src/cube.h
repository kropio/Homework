#ifndef _CUBE_H
#define _CUBE_H
#include <fstream>
#include <iostream>
#include <vector>
#include "lilcube.h"
#include <string>
class cube
{
	
	lil_Cube a[3][3][3];
	unsigned int statement[6][3][3];
	double size;
	unsigned int color[6];
 
public:
	cube();
	cube(double size, unsigned int *color);
	void fromFile(std::string s);
	void clear(double size, unsigned int *color);
	void draw();
 
	void check_statement();
	void rot90(int idx);
	void toFile(std::string s);
	
private:
	int _angle[4];
	lil_Cube tmp[4][4];
};
 
#endif;
