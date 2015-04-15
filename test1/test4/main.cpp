#include<windows.h>
#include <GL/glut.h>
#include <gl/gl.h>

//************************************
//�Ų�
//��Ĺ�ӰЧ��
//2010.5.10
//************************************

void init(void)
{
 GLfloat mat_sp[]={1.0,1.0,1.0,1.0};
 GLfloat mat_sh[]={50.0};
 GLfloat light_p[]={1,1,1,0};
 GLfloat yellow_l[]={1,1,0,1};
 GLfloat lmodel_a[]={0.1,0.1,0.1,1.0};
 glClearColor(0,0,0,0);
 glShadeModel(GL_SMOOTH);
 glMaterialfv(GL_FRONT,GL_SPECULAR,mat_sp);
 glMaterialfv(GL_FRONT,GL_SHININESS,mat_sh);
 glLightfv(GL_LIGHT0,GL_POSITION,light_p); //ָ����Դ��λ��
 glLightfv(GL_LIGHT0,GL_DIFFUSE,yellow_l);  //�趨������Ч��
 glLightfv(GL_LIGHT0,GL_SPECULAR,yellow_l); //�趨�߹ⷴ��Ч��
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_a); //�趨ȫ�ֻ�����

 glEnable(GL_LIGHTING); //���ù�Դ
 glEnable(GL_LIGHT0);   //ʹ��ָ���ƹ�
 glEnable(GL_DEPTH_TEST);

}

void myDisplay(void)
{
 glClearColor(1,1,1,0);  //���ñ���ɫ
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  //��������ɫ�����������Ȼ���
    glutSolidSphere(1.0,40,40); //��һ������
    glFlush();
}

void reshape(int w,int h)
{
 glViewport(0,0,(GLsizei) w,(GLsizei) h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if(w<=h)
  glOrtho(-1.5,1.5,-1.5*(GLfloat) h/(GLfloat) w,1.5*(GLfloat)h/(GLfloat)w,-10.0,10.0);
 else
  glOrtho(-1.5*(GLfloat)w/(GLfloat)h,1.5*(GLfloat) w/(GLfloat) h,-1.5,1.5,-10.0,10.0);

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowSize(500, 500);    //��ʾ���С
    glutInitWindowPosition(200,400); //ȷ����ʾ�����Ͻǵ�λ��
    glutCreateWindow("��Ĺ�ӰЧ�������Ų�");
 init();
    glutDisplayFunc(myDisplay);
 glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}