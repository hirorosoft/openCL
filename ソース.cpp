#include <stdio.h>
#include "glut.h"

int windowWidth = 800;
int windowHeight = 600;

bool keys[256];


void display(void) {


	glClear(GL_COLOR_BUFFER_BIT);

	// 射影モード	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(windowWidth / 2, windowHeight / 2, 0);

	static float angle;
	//angle++;
	if (keys['d'])	angle++;
	if (keys['a'])	angle--;


	glRotatef(angle, 0, 0, 1);

	glScaled(256, 256, 1);


	glutWireTeapot(1);

	// glFlush()
	glutSwapBuffers();

}


// アイドル関数
void Idle(void) {
	glutPostRedisplay();

}

void timer(int value) {
	glutPostRedisplay();

	glutTimerFunc(1000 / 60, timer, 0);

}

// ウィンドウサイズが変わったら走る
void reshape(int width, int height) {
//	printf("reshape: width:%d height: %d", width, height);

	glViewport(0, 0, width, height);

	windowWidth = width;
	windowHeight = height;



}

void keyboard(unsigned char key, int x, int y) {
	if (key == 0x1b) exit(0);
	
	printf("keyboard: key:%c(%#x)\n", key, key);
	keys[key] = true;

}

void keyboardUp(unsigned char key, int x, int y) {

	printf("keyboardUp: key:%c(%#x)\n", key, key);
	keys[key] = false;

}


int main(int argc, char* argv[]) {

	// 初期化
	glutInit(&argc, argv);

	glutInitDisplayMode(GL_DOUBLE);

	// 以下、無くてもOK
	glutInitWindowPosition(640, 0);
	glutInitWindowSize(windowWidth, windowHeight);

	glutCreateWindow("Title");

	// コールバック関数登録
	glutDisplayFunc(display);
	//	glutIdleFunc(Idle);
	glutTimerFunc(0, timer, 0);

	glutReshapeFunc(reshape);

	// キーボードフック
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);

	glutIgnoreKeyRepeat(GL_TRUE);	// キーリピート抑制

	glutMainLoop();

}