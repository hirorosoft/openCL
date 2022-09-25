#include <stdio.h>

#include "glm\glm.hpp"
#include "glut.h"
#include "font.h"
#include "glWindow.h"
#include "glKeybord.h"
#include "audio.h"

int main(int argc, char* argv[]) {
	if (audioInit() != 0) {
		return -1;
	}
		
	initWindow(argc, argv);
	initKeybord();
	glutMainLoop();
}