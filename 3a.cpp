#include<stdlib.h>
#include<stdio.h>
#include<glut.h>

void disp()
{ glClear(GL_COLOR_BUFFER_BIT); 
glFlush(); 
}
void drawPoint(int x,int y)
{
int r=rand()%3;
int g=rand()%3;
int b=rand()%3;
glColor3f(r,g,b);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}
void myMouse(int b,int s,int x,int y)
{
	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN) 
	drawPoint(x,y); 
	if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN)
	disp();
}
void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,500,0);
glMatrixMode(GL_MODELVIEW);
}
int main()
{
glutInitWindowSize(500,500);
glutCreateWindow("Square");
glutDisplayFunc(disp);
glutMouseFunc(myMouse);
glutMotionFunc(drawPoint);
init();
glutMainLoop();
}
