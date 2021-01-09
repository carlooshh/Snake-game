#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;

void timer_callback(int);
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(int, int, int);

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  initGrid(COLUMNS, ROWS);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(500, 500);
  glutCreateWindow("AVALIA��O 2 SNAKE GAME");
  glutDisplayFunc(display_callback);
  glutReshapeFunc(reshape_callback);
  glutTimerFunc(0, timer_callback, 0);
  glutSpecialFunc(keyboard_callback);
  init();
  glutMainLoop();
  return 0;
}

int index =0;
void display_callback() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawGrid();
  drawSnake();
  glutSwapBuffers();
}
void reshape_callback(int width, int height) {
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Definindo os limites no plano de 0 a 40 para X e Y
  glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int) {
  glutPostRedisplay();
  glutTimerFunc(1000/FPS, timer_callback, 0);
}

void keyboard_callback(int key, int, int) {
  switch(key){
  case GLUT_KEY_UP:
    if(sDirection != GLUT_KEY_DOWN)
      sDirection = UP;
    break;
  case GLUT_KEY_DOWN:
    if(sDirection != GLUT_KEY_UP)
      sDirection= DOWN;
    break;
  case GLUT_KEY_RIGHT:
    if(sDirection != GLUT_KEY_LEFT)
      sDirection= RIGHT;
    break;
  case GLUT_KEY_LEFT:
    if(sDirection != GLUT_KEY_RIGHT)
      sDirection= LEFT;
    break;
  }
}
