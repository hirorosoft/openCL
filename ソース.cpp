#include <stdio.h>

#include "glm\glm.hpp"
#include "glut.h"
#include "font.h"
#include "glWindow.h"
#include "glKeybord.h"

//using namespace glm;


// �A�C�h���֐�
void Idle(void) {
	glutPostRedisplay();

}



int main(int argc, char* argv[]) {

	initWindow(argc, argv);
	initKeybord();

	glutMainLoop();

}