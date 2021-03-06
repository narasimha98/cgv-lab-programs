#include <stdio.h>
#include <math.h>
#include < glut.h>
float house[3][9]={{100.0,100.0,175.0,250.0,250.0,150.0,150.0,200.0,200.0},
{100.0,300.0,400.0,300.0,100.0,100.0,150.0,150.0,100.0},
{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}};
float h=100; // Pivot point
float k=100;
float theta;
void drawhouse()
{ 
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(house[0][0],house[1][0]);
glVertex2f(house[0][1],house[1][1]);
glVertex2f(house[0][3],house[1][3]);
glVertex2f(house[0][4],house[1][4]);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(house[0][5],house[1][5]);
glVertex2f(house[0][6],house[1][6]);
glVertex2f(house[0][7],house[1][7]);
glVertex2f(house[0][8],house[1][8]);
glEnd();
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(house[0][1],house[1][1]);
glVertex2f(house[0][2],house[1][2]);
glVertex2f(house[0][3],house[1][3]);
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
drawhouse();
glTranslatef(h,k,0);
glRotatef(theta,0,0,1);
glTranslatef(-h,-k,0);
drawhouse();
glFlush();
}
void myinit()
{
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
glMatrixMode(GL_MODELVIEW);
}
void main()
{
printf("Enter the rotation angle\n");
scanf("%f",&theta);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("house rotation");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}