#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int h,k,r;
void scanline(int,int);
void circle(void);
void Axes(void);
 void display(void)
 {
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 0.0, 0.0);
 glBegin(GL_POINTS);
 circle();
 glEnd();
 glFlush();
 }
 void scanline(int ax, int by)
{
 int varx;
 for(varx=h+ax ; varx>=(h-ax) ; varx--)
 glVertex2s(varx,by);
} 
void circle(void)
{
 double XEnd,J;
 int i,j; 
 XEnd=(r/1.414);
 for( i=0 ; i<=XEnd ; i++)
 { 
 J=sqrt(r*r - i*i);
 j=(int)(J);
 scanline(i, j);
 scanline(j, i);
 scanline(j,-i);
 scanline(i,-j);
 }
//  Axes();
 glVertex3s(h,k,-25);
} 
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 printf("Enter the center of circle:\n");
 scanf("%d %d",&h,&k);
 printf("Enter the radius:\n");
 scanf("%d",&r);
 glutCreateWindow ("Circle : Scanline Filling Method ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}