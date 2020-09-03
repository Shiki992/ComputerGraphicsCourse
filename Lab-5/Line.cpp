#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
using namespace std;
int xx1,xx2,yy1,yy2;

void line5 (void) 
{ 
	
	float m,b,q,j;
	float i1,j1;
	
	if(xx1!=xx2)
	{
		m = (yy2-yy1)/(xx2-xx1);
		b=yy2-(m*xx2);
	}
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+5)
	     		{
	     			j=yy1;
				i1=round(i);
				j1=round(j);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
	     		if(yy1>yy2)
			{
				t1=yy2;
				t2=yy1;
			}
			else
			{
				t1=yy1;
				t2=yy2;
			}
	     		for(int i=t1;i<t2;i=i+5)
	     		{
	     			j=xx1;
				i1=round(j);
				j1=round(i);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		
     	}
     	else
     	{
		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
		else
			{
				t1=xx1;
				t2=xx2;
			}
		for(int i=t1;i<t2;i=i+5)
		{
			j=(m*i)+b;
			i1=round(i);
			j1=round(j);
			
			glVertex2f(i1,j1);
		}
 	}
      glEnd();
	
	glFlush(); 
} 



void line4 (void) 
{ 
	
	float m,b,q,j;
	float i1,j1;
	
	if(xx1!=xx2)
	{
		m = (yy2-yy1)/(xx2-xx1);
		b=yy2-(m*xx2);
	}
	
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+4)
	     		{
	     			j=yy1;
				i1=round(i);
				j1=round(j);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
	     		if(yy1>yy2)
			{
				t1=yy2;
				t2=yy1;
			}
			else
			{
				t1=yy1;
				t2=yy2;
			}
	     		for(int i=t1;i<t2;i=i+4)
	     		{
	     			j=xx1;
				i1=round(j);
				j1=round(i);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		
     	}
     	else
     	{
		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
		else
			{
				t1=xx1;
				t2=xx2;
			}
		for(int i=t1;i<t2;i=i+4)
		{
			j=(m*i)+b;
			i1=round(i);
			j1=round(j);
			
			glVertex2f(i1,j1);
		}
 	}
      glEnd();
      glFlush(); 
}

void line3 (void) 
{ 
	
	float m,b,q,j;
	float i1,j1;
	
	if(xx1!=xx2)
	{
		m = (yy2-yy1)/(xx2-xx1);
		b=yy2-(m*xx2);
	}
	
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+3)
	     		{
	     			j=yy1;
				i1=round(i);
				j1=round(j);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
	     		if(yy1>yy2)
			{
				t1=yy2;
				t2=yy1;
			}
			else
			{
				t1=yy1;
				t2=yy2;
			}
	     		for(int i=t1;i<t2;i=i+3)
	     		{
	     			j=xx1;
				i1=round(j);
				j1=round(i);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		
     	}
     	else
     	{
		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
		else
			{
				t1=xx1;
				t2=xx2;
			}
		for(int i=t1;i<t2;i=i+3)
		{
			j=(m*i)+b;
			i1=round(i);
			j1=round(j);
			
			glVertex2f(i1,j1);
		}
 	}
      glEnd(); 
               glFlush(); 
}


void line2 (void) 
{ 
	float m,b,q,j;
	float i1,j1;
	
	if(xx1!=xx2)
	{
		m = (yy2-yy1)/(xx2-xx1);
		b=yy2-(m*xx2);
	}
	
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+2)
	     		{
	     			j=yy1;
				i1=round(i);
				j1=round(j);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
	     		if(yy1>yy2)
			{
				t1=yy2;
				t2=yy1;
			}
			else
			{
				t1=yy1;
				t2=yy2;
			}
	     		for(int i=t1;i<t2;i=i+2)
	     		{
	     			j=xx1;
				i1=round(j);
				j1=round(i);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		
     	}
     	else
     	{
		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
		else
			{
				t1=xx1;
				t2=xx2;
			}
		for(int i=t1;i<t2;i=i+2)
		{
			j=(m*i)+b;
			i1=round(i);
			j1=round(j);
			
			glVertex2f(i1,j1);
		}
 	}
      glEnd();
      glFlush(); 
}

void line1 (void) 
{ 
	float m,b,q,j;
	float i1,j1;
	
	if(xx1!=xx2)
	{
		m = (yy2-yy1)/(xx2-xx1);
		b=yy2-(m*xx2);
	}
	
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+1)
	     		{
	     			j=yy1;
				i1=round(i);
				j1=round(j);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
	     		if(yy1>yy2)
			{
				t1=yy2;
				t2=yy1;
			}
			else
			{
				t1=yy1;
				t2=yy2;
			}
	     		for(int i=t1;i<t2;i=i+1)
	     		{
	     			j=xx1;
				i1=round(j);
				j1=round(i);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		
     	}
     	else
     	{
		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
		else
			{
				t1=xx1;
				t2=xx2;
			}
		for(int i=t1;i<t2;i=i+1)
		{
			j=(m*i)+b;
			i1=round(i);
			j1=round(j);
			
			glVertex2f(i1,j1);
		}
 	}
      glEnd();
      glFlush(); 
}

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	xx1=atoi(argv[1]);
	yy1=atoi(argv[2]);
	xx2=atoi(argv[3]);
	yy2=atoi(argv[4]);
	
	float m,b,q,j;

	glutInitWindowSize(1366, 768);  
	glutInitWindowPosition(0, 0); 	
	

	glutCreateWindow("line"); 			//step size = 5
	glutDisplayFunc(line5); 
	
	glutCreateWindow("line1"); 			//step size = 4	
	glutDisplayFunc(line4); 
	
	glutCreateWindow("line2"); 			//step size = 3
	glutDisplayFunc(line3); 
	
	glutCreateWindow("line3"); 			//step size = 2
	glutDisplayFunc(line2);
	
	glutCreateWindow("line4"); 			//step size = 1
	glutDisplayFunc(line1);  
	
	
	glutMainLoop(); 
} 

