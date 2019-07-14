#include "OpenGL.h"



using namespace std;


int main(int argc,char** argv) 
{
	

	glutInit(&argc, argv);
	//����� �����������
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	//��������� ������� ����
	glutInitWindowPosition(0, 0);
	//������ ����
	glutInitWindowSize(g_width, g_height);
	//�������� ����
	glutCreateWindow("Tic_Tac_Toe");
	//���� ������� (�� RGB +- �����)
	glClearColor(0.6f, 0.6f, 0.6f, 1);
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();

	gluOrtho2D(0, g_width, g_height, 0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	//��������� ������� ������� �������� ��� ������� ������ ����
	glutMouseFunc(Click);

	//������� ����������� �������
	glutDisplayFunc(Display);

	//������� ������������� ��� ������� �������
	glutSpecialFunc(KeyClick);

	glutMainLoop();
	//��������� ������� ������� ����� �������
	glutTimerFunc(100, Timer, 0);
	
	

	return 0;
}