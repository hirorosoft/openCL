#pragma once

#define FONT_DEFAULT_SIZE (100.0)

void fontBegin();
void fontEnd();

void fontSetPosition(float _x, float _y);
void fontSetSize(float _size);
float fontGetSize();


void fontSetColor(unsigned char _red, unsigned char _green, unsigned char _blue);

void fontDraw(const char *_format, ...);
