#include<windows.h>
#include<GL/glut.h>

static float theta = 0;
static float rotate = 0;
static float aerfa = 1;

// 绘制立方体


// 将立方体的八个顶点保存到一个数组里面

static const GLfloat vertex_list[][3] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
};

// 将要使用的顶点的序号保存到一个数组里面

static const  index_list[][4] = {
    0, 2, 3, 1,
    0, 4, 6, 2,
    0, 1, 5, 4,
    4, 5, 7, 6,
    1, 3, 7, 5,
    2, 6, 7, 3,
};

// 绘制立方体

void DrawCube(void)
{
    int i,j;
	glBegin(GL_QUADS);
	for(i=0; i<6; ++i)         // 有六个面，循环六次
		for(j=0; j<4; ++j)  // 每个面有四个顶点，循环四次
		{
		//	glColor3f(0, i, j);
			glVertex3fv(vertex_list[index_list[i][j]]);
		}
    glEnd();
	
	glPopMatrix();
    glutSwapBuffers();
}

void init(void)
{
 GLfloat mat_sp[]={1.0,1.0,1.0,1.0};
 GLfloat mat_sh[]={50.0};
 GLfloat light_p[]={1,1,1,0};
 GLfloat yellow_l[]={1,0,1,1};
 GLfloat lmodel_a[]={0.1,0.1,0.1,1.0};
 glClearColor(0,0,0,0);
 glShadeModel(GL_SMOOTH);
 glMaterialfv(GL_FRONT,GL_SPECULAR,mat_sp);
 glMaterialfv(GL_FRONT,GL_SHININESS,mat_sh);
 glLightfv(GL_LIGHT0,GL_POSITION,light_p); //指定光源的位置
 glLightfv(GL_LIGHT0,GL_DIFFUSE,yellow_l);  //设定漫反射效果
 glLightfv(GL_LIGHT0,GL_SPECULAR,yellow_l); //设定高光反射效果
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_a); //设定全局环境光
 glEnable(GL_LIGHTING); //启用光源
 glEnable(GL_LIGHT0);   //使用指定灯光
 glEnable(GL_DEPTH_TEST);
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
void myKeyboard(unsigned char key,  int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
	if(key == 'a' || key == 'A')
		theta += 5.0;
	if(key == 's' || key == 'S')
		theta -= 5.0;
	if(key == 'z' || key == 'Z')
		rotate -= 0.1;
	if(key == 'x' || key == 'X')
		rotate += 0.1;
	if(key == 'q' || key == 'Q')
		aerfa += 0.1;
	if(key == 'w' || key == 'W')
		aerfa -= 0.1;
    if(key == 'c' || key == 'C')
		exit(0);

    glRotatef(theta, 0, 1, 0);
	glRotatef(theta, 1, 0, 0);
	glTranslatef(rotate, 0, 0);
	glScalef(aerfa, aerfa, aerfa);
	DrawCube();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("王必伟 2012211744");
    glutDisplayFunc(DrawCube);
	init();
	glutKeyboardFunc( myKeyboard);
    glutReshapeFunc(reshape);
	glutMainLoop();
}