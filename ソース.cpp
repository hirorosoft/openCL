#include "glut.h"

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(1, 0, 0, 1);
	glutWireTeapot(1);

	// glFlush()
	glutSwapBuffers();

}


// �A�C�h���֐�
void Idle(void) {
	glutPostRedisplay();

}


int main(int argc, char* argv[]) {

	// ������
	glutInit(&argc, argv);

	glutInitDisplayMode(GL_DOUBLE);

	// �ȉ��A�����Ă�OK
	glutInitWindowPosition(640, 0);
	glutInitWindowSize(640, 640);

	glutCreateWindow("Title");

	// �R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);
	glutIdleFunc(Idle);


	glutMainLoop();

}