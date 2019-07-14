#include "OpenGL.h"



using namespace std;


int main(int argc,char** argv) 
{
	

	glutInit(&argc, argv);
	//режим отображения
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	//начальная позиция окна
	glutInitWindowPosition(0, 0);
	//размер окна
	glutInitWindowSize(g_width, g_height);
	//создание окна
	glutCreateWindow("Tic_Tac_Toe");
	//цвет заливки (по RGB +- серый)
	glClearColor(0.6f, 0.6f, 0.6f, 1);
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();

	gluOrtho2D(0, g_width, g_height, 0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	//Указываем функцию которая работает при нажатии кнопки мыши
	glutMouseFunc(Click);

	//Функция отображения графики
	glutDisplayFunc(Display);

	//Функция срабатывающая при нажатии клавиши
	glutSpecialFunc(KeyClick);

	glutMainLoop();
	//указываем функцию которая будет таймера
	glutTimerFunc(100, Timer, 0);
	
	

	return 0;
}