#include "glut.h"


//void (GLUTCALLBACK* func)(void

void display(void) {
    glutWireTeapot(1);
    glFlush();

}

int main(int argc, char* argv[]) {
    
    glutInit(
        &argc,  // int *argcp
        argv);  // char **argv

    glutInitWindowPosition(640, 0);
    glutInitWindowSize(640, 640);

    glutCreateWindow("Title");
    glutDisplayFunc(display);
    glutMainLoop();

}