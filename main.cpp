#include <GL/gl.h>
#include <GL/glut.h>

void display_callback();
void reshape_callback(int, int);

void init() {
  glClearColor(1.0, 1.0, 0.5, 1.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(500, 500);
  glutCreateWindow("AVALIA��O 2 SNAKE GAME");
  glutDisplayFunc(display_callback);
  glutReshapeFunc(reshape_callback);
  init();
  glutMainLoop();
  return 0;
}

void display_callback() {
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}
void reshape_callback(int width, int height) {
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Definindo os limites no plano de 0 a 40 para X e Y
  glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}
