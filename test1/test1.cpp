#include<windows.h>
//#include "stdafx.h"
#include <GL\glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> 

int mian(int argc, char ** argv)
{
//	InitGL();						//��ʼ�����ڣ�
	glClearColor(0.0, 0.0, 0.0 ,0.0);	//�ñ�����ɫΪ��ɫ��
	glClear(GL_COLOR_BUFFER_BIT);		//�����ɫ�������� GL_COLOR_BUFFER_BITλ��ɫ��������
	glColor3f(1.0, 1.0, 1.0);			//����������ɫΪ��ɫ��
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