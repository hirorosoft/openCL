#include <stdio.h>
#include <stdarg.h>

#include "font.h"

#include "glm\glm.hpp"
#include "glut.h"

using namespace glm;

static vec2 position;
static float size = FONT_DEFAULT_SIZE;
static unsigned char color[3];


void fontBegin() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	// éÀâeÉÇÅ[Éh	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	gluOrtho2D(0, viewport[2], viewport[3], 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


}

void fontEnd() {
	glPopMatrix();
	glPopAttrib();
}


void fontSetPosition(float _x, float _y) {
	position = vec2(_x, _y);


}


void fontSetSize(float _size) {
	size = _size;
}

float fontGetSize() {
	return size;
}

void fontSetColor(unsigned char _red, unsigned char _green, unsigned char _blue) {
	color[0] = _red;
	color[1] = _green;
	color[2] = _blue;
}

void fontDraw(const char* _format, ...) {
	va_list argList;
	va_start(argList, _format);
	char str[256];

	vsprintf_s(str, _format, argList);
	va_end(argList);


	glColor3ub(color[0], color[1], color[2]);
	glPushMatrix();
	{
		glTranslatef(position.x, position.y + size, 0);
		float s = size / FONT_DEFAULT_SIZE;
		glScalef(s, -s, 1);
		for (char* p = str; *p != NULL; p++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);

	}
	glPopMatrix();


	//printf("%s\n", str);

}
