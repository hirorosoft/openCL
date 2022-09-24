#include <stdio.h>

#include "glm\glm.hpp"
#include "glut.h"
#include "font.h"

#include "glKeybord.h"
#include "glWindow.h"

ivec2 windowSize = { 800, 600 };


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// �ˉe���[�h	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, windowSize.x, windowSize.y, 0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(windowSize.x / 2, windowSize.y / 2, 0);

	static float angle;

	//angle++;
	if (keys['d'])	angle++;
	if (keys['a'])	angle--;


	glRotatef(angle, 0, 0, 1);

	glScaled(256, 256, 1);


	glutWireTeapot(1);
	fontSetColor(0, 0xff, 0);
	fontBegin();
	fontSetPosition(0, windowSize.y - fontGetSize() * 1.5);
	fontSetSize(FONT_DEFAULT_SIZE / 2);
	fontDraw("angle:%f", angle);
	fontEnd();

	// glFlush()
	glutSwapBuffers();

}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

// �E�B���h�E�T�C�Y���ς�����瑖��
void reshape(int width, int height) {
	//	printf("reshape: width:%d height: %d", width, height);

	glViewport(0, 0, width, height);

	windowSize = ivec2(width, height);

	//	windowWidth = width;
	//	windowHeight = height;
}


void initWindow(int argc, char* argv[]) {

	// ������
	glutInit(&argc, argv);

	glutInitDisplayMode(GL_DOUBLE);

	// �ȉ��A�����Ă�OK
	glutInitWindowPosition(640, 0);
	glutInitWindowSize(windowSize.x, windowSize.y);

	glutCreateWindow("Title");

	// �R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);

	//	glutIdleFunc(Idle);
	glutTimerFunc(0, timer, 0);

	glutReshapeFunc(reshape);

}


