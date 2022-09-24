#pragma once

#include <stdio.h>

#include "glm\glm.hpp"


using namespace glm;


extern  ivec2 windowSize;


void display(void);
void timer(int value);
void initWindow(int argc, char* argv[]);
void reshape(int width, int height);