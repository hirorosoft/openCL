#include <stdio.h>
#include <stdlib.h>

#include "glut.h"
#include "glKeybord.h"

#include "audio.h"


bool keys[256];

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 0x1b:
		exit(9);
		break;
	case 'p':
		audioPlay();
		break;
	case 's':
		audioStop();
		break;
	}

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


