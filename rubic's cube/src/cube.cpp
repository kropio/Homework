
#include "cube.h"
 
cube::cube(){
}
 
cube::cube(double size, unsigned int *color) {
	clear(size, color);
}

void cube::fromFile(std::string s){
	std::ifstream fin(s);
	//short int check1[6];
	int i, j, k;
	for (i = 0; i < 6; ++i){
		for (j = 0; j < 3; ++j){
			for (k = 0; k < 3; ++k){
				fin >> statement[i][j][k];
			}
		}
	}
		
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++){
			a[i][j][2].set_color(0, statement[0][i][j]);
		}
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++){
			a[i][j][0].set_color(1, statement[1][i][j]);
		}
	for(k = 0; k < 3; k++)
		for(j = 0; j < 3; j++){
			a[j][0][k].set_color(2, statement[2][k][j]);
		}
	for(k = 0; k < 3; k++)
		for(j = 0; j < 3; j++){
			a[j][2][k].set_color(3, statement[3][k][j]);
		}
 
	for(i = 0; i < 3; i++)
		for(k = 0; k < 3; k++){
			a[0][k][i].set_color(4, statement[4][i][k]);
		}
 
	for(i = 0; i < 3; i++)
		for(k = 0; k < 3; k++){
			a[2][k][i].set_color(5, statement[5][i][k]);
		}
}
 
void cube::clear(double size, unsigned int *color) {
	this->size = size;
 
	int i, j, k;
	for(i = 0; i < 6; i++)
		this->color[i] = color[i];
 
	// верх
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++){
			a[i][j][2].set_color(0, color[0]);
			statement[0][i][j] = color[0];
		}
 
	// низ
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++){
			a[i][j][0].set_color(1, color[1]);
			statement[1][i][j] = color[1];
		}
 
	// спереди
	for(k = 0; k < 3; k++)
		for(j = 0; j < 3; j++){
			a[j][0][k].set_color(2, color[2]);
			statement[2][k][j] = color[2];
		}
 
	// сзади
	for(k = 0; k < 3; k++)
		for(j = 0; j < 3; j++){
			a[j][2][k].set_color(3, color[3]);
			statement[3][k][j] = color[3];
		}
 
	// слева
	for(i = 0; i < 3; i++)
		for(k = 0; k < 3; k++){
			a[0][k][i].set_color(4, color[4]);
			statement[4][i][k] = color[4];
		}
 
	// справа
	for(i = 0; i < 3; i++)
		for(k = 0; k < 3; k++){
			a[2][k][i].set_color(5, color[5]);
			statement[5][i][k] = color[5];
		}
 
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			for(k = 0; k < 3; k++)
				a[i][j][k].size = (size / 3.0) * 0.9;
}
 
void cube::draw(){
	const double K = 0.65;
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(((1.0 - K)/2)*size + K*size/2, ((1.0 - K)/2)*size + K*size/2, ((1.0 - K)/2)*size + K*size/2);
	glutSolidCube(size * K);
	glPopMatrix();
 
	
 
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
}

void cube::check_statement(){
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 3; ++k){
				std::cout << statement[i][j][k] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void cube::toFile(std::string s){
	std::ofstream fout(s);
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 3; ++k){
				fout << statement[i][j][k] << " ";
			}
		}
		fout << std::endl;
	}
}

void cube::rot90(int idx){
	int i, j, k;
	unsigned int tempo[3];
	if (idx == 0 || idx == 1)
	{
		// низ/верх
		k = (idx & 1) * 2;
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				tmp[j][2 - i] = a[i][j][k];
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				tmp[i][j].rotate_z(), a[i][j][k] = tmp[i][j];
		for(i = 0; i < 3; ++i){
			tempo[i] = statement[4][k][i];
			statement[4][k][i] = statement[2][k][2 - i];
			statement[2][k][2 - i] = statement[5][k][2 - i];
			statement[5][k][2 - i] = statement[3][k][i];
			statement[3][k][i] = tempo[i];
		}
		k = (k == 2 ? 0 : 1);
		j = statement[k][0][2];
		statement[k][0][2] = statement[k][0][0];
		statement[k][0][0] = statement[k][2][0];
		statement[k][2][0] = statement[k][2][2];
		statement[k][2][2] = j;
		j = statement[k][0][1];
		statement[k][0][1] = statement[k][1][0];
		statement[k][1][0] = statement[k][2][1];
		statement[k][2][1] = statement[k][1][2];
		statement[k][1][2] = j;
	}
	else if (idx == 2 || idx == 3)
	{
		// лево/право
		j = (idx & 1) * 2;
		for(i = 0; i < 3; i++)
			for(k = 0; k < 3; k++)
				tmp[k][2 - i] = a[i][j][k];
		for(i = 0; i < 3; i++)
			for(k = 0; k < 3; k++)
				tmp[i][k].rotate_x(), a[i][j][k] = tmp[i][k];
		for(i = 0; i < 3; ++i){
			tempo[i] = statement[5][2 - i][j];
			statement[5][2 - i][j] = statement[0][i][j];
			statement[0][i][j] = statement[4][i][j];
			statement[4][i][j] = statement[1][2 - i][j];
			statement[1][2 - i][j] = tempo[i];
		}
		j = (j == 2 ? 3 : 2);
		k = statement[j][0][2];
		statement[j][0][2] = statement[j][2][2];
		statement[j][2][2] = statement[j][2][0];
		statement[j][2][0] = statement[j][0][0];
		statement[j][0][0] = k;
		k = statement[j][0][1];
		statement[j][0][1] = statement[j][1][2];
		statement[j][1][2] = statement[j][2][1];
		statement[j][2][1] = statement[j][1][0];
		statement[j][1][0] = k;
		
	}
	else if (idx == 4 || idx == 5)
	{
		// впереди/сзади
		i = (idx & 1) * 2;
		for(j = 0; j < 3; j++)
			for(k = 0; k < 3; k++)
				tmp[k][2 - j] = a[i][j][k];
		for(j = 0; j < 3; j++)
			for(k = 0; k < 3; k++)
				tmp[j][k].rotate_y(), a[i][j][k] = tmp[j][k];
		for(j = 0; j < 3; ++j){
			tempo[j] = statement[3][2 - j][i];
			statement[3][2 - j][i] = statement[0][i][j];
			statement[0][i][j] = statement[2][j][i];
			statement[2][j][i] = statement[1][i][2 - j];
			statement[1][i][2 - j] = tempo[j];
		}
		i = (i == 2 ? 5 : 4);
		k = statement[i][0][2];
		statement[i][0][2] = statement[i][2][2];
		statement[i][2][2] = statement[i][2][0];
		statement[i][2][0] = statement[i][0][0];
		statement[i][0][0] = k;
		k = statement[i][0][1];
		statement[i][0][1] = statement[i][1][2];
		statement[i][1][2] = statement[i][2][1];
		statement[i][2][1] = statement[i][1][0];
		statement[i][1][0] = k;
	}
}

//                       белый     желтый  синий      зеленый   красный    салатовый
//unsigned int c[6] = {0xFFFFFF, 0xFFFF00, 0x0000FF, 0x00FF00, 0xFF0000, 	0xCCFA50};
