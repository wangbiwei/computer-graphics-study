#include<windows.h>
//#include "stdafx.h"
#include <GL\glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> 

int mian(int argc, char ** argv)
{
//	InitGL();						//初始化窗口；
	glClearColor(0.0, 0.0, 0.0 ,0.0);	//置背景颜色为黑色；
	glClear(GL_COLOR_BUFFER_BIT);		//清除颜色缓冲区； GL_COLOR_BUFFER_BIT位颜色缓冲区；
	glColor3f(1.0, 1.0, 1.0);			//设置像素颜色为白色；
	glMatrixMode(GL_PROJECTION);		//?
	glLoadIdentity();					//?
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glEnd();
	glFlush();
	return 0;
}; 