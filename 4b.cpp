#include <glut.h>
float vertices[ ] = {-1,-1,-1,1,-1,-1,1,1,-1, -1,1,-1, -1,-1,1, 1,-1,1, 1,1,1, -1,1,1};
float colors[ ] = {0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,1};
unsigned char cubeIndices[ ]={0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4};
float theta[ ] = {0,0,0};
int axis = 2;
void display(void)
{
/* display callback, clear frame buffer and z buffer, rotate cube and draw, swap buffers */
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glRotatef(theta[0], 1,0,0);
glRotatef(theta[1], 0,1,0);
glRotatef(theta[2], 0,0,1);
glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
glutSwapBuffers();
}
void spinCube()
{
/* Idle callback, spin cube .1 degrees about selected axis */
theta[axis] += .1;
glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y)
{
/* mouse callback, selects an axis about which to rotate */
if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}
void myReshape(int w, int h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w <= h)
glOrtho(-2, 2, -2 * (float)h/(float)w,2 * (float) h /(float) w, -10,10);
else
glOrtho(-2 * (float) w / (float) h, 2 * (float) w / (float) h, -2, 2, -10,10);
glMatrixMode(GL_MODELVIEW);
}
void main()
{
/* need both double buffering and z buffer */
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutCreateWindow("colorcube");
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glutIdleFunc(spinCube);
glutMouseFunc(mouse);
glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
glEnableClientState(GL_COLOR_ARRAY);
glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3, GL_FLOAT, 0, vertices);
glColorPointer(3,GL_FLOAT, 0, colors);
glClearColor(1,1,1,1);
glColor3f(1,1,1);
glutMainLoop();
}