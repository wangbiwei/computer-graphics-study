#include <GL/glut.h>
#include <gl/gl.h>

void  display()
{
     glClearColor(0.0,0.0,0.0,0.0);			//���ñ�����ɫΪ��ɫ��
     glClear(GL_COLOR_BUFFER_BIT);			//�����ɫ��������

//     glColor4f(1.0,0.0,0.0,1.0);     // set the quad color
	glBegin(GL_POINTS);			//���ΪGL_LINES,���Զ�ȡǰ���㣻

/*	glVertex2f(-0.5, -0.5);				
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
  */
//	glColor3f(1.0, 1.0 ,1.0);			//�졢�̡���
//	glVertex2f(-0.5, -0.5);
//	glVertex2f(-0.5, 0.5);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex2f(0.5, 0.5);
	glPointSize(0.001);
	glVertex2f(0.5, -0.5);
	glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//?
     glutInitWindowPosition(100, 100);			//������glut����Ҫ�����Ĵ��ڵĴ�С��λ�ã����Ͻǣ���������Ϊ��λ
     glutInitWindowSize(400, 400);				//���ô��ڴ�С��
     glutCreateWindow("��һ��OpenGL����");		//���ô�������
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;

}

/*
Question:
1.��ΪGL_QUAD_STRIP ,������ͼ�β�����⣻
*/