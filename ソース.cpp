#include <stdio.h>
#include "glut.h"

int windowWidth = 800;
int windowHeight = 600;


void display(void) {


	glClear(GL_COLOR_BUFFER_BIT);

	// �ˉe���[�h	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(windowWidth / 2, windowHeight / 2, 0);

	static float angle;
	angle++;


	glRotatef(angle, 0, 0, 1);

	glScaled(256, 256, 1);


	glutWireTeapot(1);

	// glFlush()
	glutSwapBuffers();

}


// �A�C�h���֐�
void Idle(void) {
	glutPostRedisplay();

}

void timer(int value) {
	glutPostRedisplay();

	glutTimerFunc(1000 / 60, timer, 0);

}

// �E�B���h�E�T�C�Y���ς�����瑖��
void reshape(int width, int height) {
	printf("reshape: width:%d height: %d", width, height);

	glViewport(0, 0, width, height);

	windowWidth = width;
	windowHeight = height;



}

int main(int argc, char* argv[]) {

	// ������
	glutInit(&argc, argv);

	glutInitDisplayMode(GL_DOUBLE);

	// �ȉ��A�����Ă�OK
	glutInitWindowPosition(640, 0);
	glutInitWindowSize(windowWidth, windowHeight);

	glutCreateWindow("Title");

	// �R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);
	//	glutIdleFunc(Idle);
	glutTimerFunc(0, timer, 0);

	glutReshapeFunc(reshape);
	glutMainLoop();

}