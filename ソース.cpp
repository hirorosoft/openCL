#include <stdio.h>

#include "glm\glm.hpp"
#include "glut.h"
#include "font.h"
#include "glWindow.h"
#include "glKeybord.h"

int main(int argc, char* argv[]) {
	initWindow(argc, argv);
	initKeybord();
	glutMainLoop();
}