#define GL_SILENCE_DEPRECATION
#include<bits/stdc++.h>
using namespace std;
#include <GL/glut.h>

int xstart, ystart, xend, yend;
int n;
vector<pair<int, int>> lines1, lines2;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

void DrawPoint(int x, int y) {

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();

}

void DrawLine(pair<int, int> p1, pair<int, int> p2) {
	glBegin(GL_LINES);
	glVertex2i(p1.first, p1.second);
	glVertex2i(p2.first, p2.second);
	glEnd();
}
void helper() {
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(xstart, ystart);
	glVertex2i(xend, ystart);
	glVertex2i(xend, ystart);
	glVertex2i(xend, yend);
	glVertex2i(xend, yend);
	glVertex2i(xstart, yend);
	glVertex2i(xstart, yend);
	glVertex2i(xstart, ystart);
	glEnd();
}

int codehelper(int x, int y) {
	int code = 0;
	if (y > yend) 
		code |= (1<<3);
	if (y < ystart) 
		code |= (1<<2);
	if (x > xend)
		code |= (1<<1);
	if (x < xstart)
		code |= 1;
	return code;
}
void helper2(pair<int, int> &p1, pair<int, int> &p2) {
	int x1 = p1.first, x2 = p2.first, y1 = p1.second, y2 = p2.second;
	int rep1 = codehelper(x1, y1);
	int rep2 = codehelper(x2, y2);

	int check = 0;

	while(1) {
		if (rep1 == 0 && rep2 == 0) {
			check = 1;
			break;
		}
		else if (rep1 & rep2) {
			break;
		}
		else {
			int temp;
			float tempx, tempy;

			if (rep1 != 0)
				temp = rep1;
			else 
				temp = rep2;

			if (temp & (1<<3)) {
				tempx = x1 + (x2 - x1) * (yend - y1) / (y2 - y1);
				tempy = yend;
			}
			else if (temp & (1<<2)) {
				tempx = x1 + (x2 - x1) * (ystart - y1) / (y2 - y1);
				tempy = ystart;
			}
			else if (temp & (1<<1)) {
				tempx = xend;
				tempy = y1 + (y2 - y1) * (xend - x1) / (x2 - x1); 
			}
			else if (temp & 1) {
				tempx = xstart;
				tempy = y1 + (y2 - y1) * (xstart - x1) / (x2 - x1); 	
			}

			if (temp == rep1) {
				x1 = (int) tempx;
				y1 = (int) tempy;
				rep1 = codehelper(x1, y1);
			}
			else {
				x2 = (int) tempx;
				y2 = (int) tempy;
				rep2 = codehelper(x2, y2);
			}
		}

	}

	if (check) {
		glColor3f(1.0, 0.0, 0.0);
		DrawLine(make_pair(x1, y1), make_pair(x2, y2));
		glColor3f(0.0, 0.0, 0.0);
	}




}
void driver() {
	helper();
	for (int i = 0; i < n; i++) {
		DrawLine(lines1[i], lines2[i]);
		helper2(lines1[i], lines2[i]);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	driver();
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	
	freopen("input2.txt", "r", stdin);
	cin >> xstart >> ystart >> xend >> yend;
	cin >> n;
	lines1.resize(n);
	lines2.resize(n);
	for (int i = 0; i < n; i++) {
		int tempx1, tempy1, tempx2, tempy2;
		cin >> tempx1 >> tempy1 >> tempx2 >> tempy2;
		lines1[i] = make_pair(tempx1, tempy1);
		lines2[i] = make_pair(tempx2, tempy2);

	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Cohen Sutherland");
	init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}