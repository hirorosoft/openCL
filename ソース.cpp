#include "glut.h"

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(1, 0, 0, 1);
	glutWireTeapot(1);

	// glFlush()
	glutSwapBuffers();

}


// アイドル関数
void Idle(void) {
	glutPostRedisplay();

}


int main(int argc, char* argv[]) {

	// 初期化
	glutInit(&argc, argv);

	glutInitDisplayMode(GL_DOUBLE);

	// 以下、無くてもOK
	glutInitWindowPosition(640, 0);
	glutInitWindowSize(640, 640);

	glutCreateWindow("Title");

	// コールバック関数登録
	glutDisplayFunc(display);
	glutIdleFunc(Idle);


	glutMainLoop();

}