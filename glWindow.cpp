#include <stdio.h>

#include "glm\glm.hpp"
#include "glut.h"
#include "font.h"

#include "glKeybord.h"
#include "glWindow.h"
#include "Rect.h"

ivec2 windowSize = { 800, 600 };

Rect rect = Rect(vec2(100,100), vec2(100,100));

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// 射影モード	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, windowSize.x, windowSize.y, 0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(windowSize.x / 2.0, windowSize.y / 2.0, 0);

	static float angle;
	if (keys['d'])	angle++;
	if (keys['a'])	angle--;

	//glRotatef(angle, 0, 0, 1);
	//glScaled(256, -256, 1);
	//glutWireTeapot(1);

	rect.Draw();


	fontSetColor(0, 0xff, 0);
	fontBegin();
	fontSetPosition(0, windowSize.y - fontGetSize() * 1.5);
	fontSetSize(FONT_DEFAULT_SIZE / 2);
	fontDraw("angle:%f", angle);
	fontEnd();

	// glFlush()
	glutSwapBuffers();

}

// アイドル関数
//void Idle(void) {
//	glutPostRedisplay();
//}

void timer(int value) {
	float f = 2;
	if (keys['w'])	rect.m_pos.y -= f;
	if (keys['s'])	rect.m_pos.y += f;
	if (keys['a'])	rect.m_pos.x -= f;
	if (keys['d'])	rect.m_pos.x += f;


	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

// ウィンドウサイズが変わったら走る
void reshape(int width, int height) {
	//	printf("reshape: width:%d height: %d", width, height);

	glViewport(0, 0, width, height);

	windowSize = ivec2(width, height);

	//	windowWidth = width;
	//	windowHeight = height;
}


void initWindow(int argc, char* argv[]) {

	// 初期化
	glutInit(&argc, argv);

	glutInitDisplayMode(GL_DOUBLE);

	// 以下、無くてもOK
	glutInitWindowPosition(640, 0);
	glutInitWindowSize(windowSize.x, windowSize.y);

	glutCreateWindow("Title");

	// コールバック関数登録
	glutDisplayFunc(display);

	//	glutIdleFunc(Idle);
	glutTimerFunc(0, timer, 0);

	glutReshapeFunc(reshape);

}


