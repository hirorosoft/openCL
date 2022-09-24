#include <stdio.h>
#include <stdlib.h>

#include "glut.h"
#include "glKeybord.h"

 bool keys[256];


void keyboard(unsigned char key, int x, int y) {
	if (key == 0x1b) exit(0);

	//printf("keyboard: key:%c(%#x)\n", key, key);
	keys[key] = true;

}

void keyboardUp(unsigned char key, int x, int y) {

	//printf("keyboardUp: key:%c(%#x)\n", key, key);
	keys[key] = false;

}

void initKeybord() {

	// キーボードフック
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);

	glutIgnoreKeyRepeat(GL_TRUE);	// キーリピート抑制

}


