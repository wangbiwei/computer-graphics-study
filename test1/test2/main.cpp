#include <GL/glut.h>
#include <gl/gl.h>

void  display()
{
     glClearColor(0.0,0.0,0.0,0.0);			//设置背景颜色为黑色；
     glClear(GL_COLOR_BUFFER_BIT);			//清除颜色缓冲区；

//     glColor4f(1.0,0.0,0.0,1.0);     // set the quad color
	glBegin(GL_POINTS);			//如果为GL_LINES,则自动取前两点；

/*	glVertex2f(-0.5, -0.5);				
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
  */
//	glColor3f(1.0, 1.0 ,1.0);			//红、绿、蓝
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
     glutInitWindowPosition(100, 100);			//？设置glut程序要产生的窗口的大小和位置（左上角）。以像素为单位
     glutInitWindowSize(400, 400);				//设置窗口大小；
     glutCreateWindow("第一个OpenGL程序");		//设置窗口名；
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;

}

/*
Question:
1.当为GL_QUAD_STRIP ,出来的图形不能理解；
*/