#ifndef OPENGL_H
#define OPENGL_H

#include "variables.h"
#include <GL/glut.h>
#include "WinCondition.h"

void drawStrokeText(GLfloat x, GLfloat y, GLfloat width, GLfloat length, const char* Win)
{
	if (WinnerO)
	{
		glColor3f(0.6f, 0.0f, 0.0f);
	}
	else if (WinnerX)
	{
		glColor3f(0.0f, 0.6f, 0.0f);
	}
	else if (Draw)
	{
		glColor3f(0.0f, 0.0f, 0.6f);
	}
	glLineWidth(5);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(width, length, 0);
	while (*Win)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *Win++);

	}

	glPopMatrix();
}

void DrawCrossingLine(int x1, int y1, int x2, int y2)
{
	glColor3f(0.0f, 0.0f, 0.0f);

	glLineWidth(4.0);

	glBegin(GL_LINES);

	glVertex2i(x1, y1);
	glVertex2i(x2, y2);

	glEnd();
}

//Функция для отрисовки ноликов
void DrawCircle(int x, int y, float r, int amountSegments)
{
	glLineWidth(2.0);
	glColor3f(0.5f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0f * 3.1415926f * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}
//Функция для отрисовки крестиков
void DrawXmark(const int col, const int row)
{
	glLineWidth(2.0);
	glColor3f(0.0f, 0.5f, 0.0f);

	glBegin(GL_LINES);


	glVertex2i(col * g_Scale + g_Scale / 8, row * g_Scale + g_Scale / 8);
	glVertex2i(col * g_Scale + g_Scale - g_Scale / 8, row * g_Scale + g_Scale - g_Scale / 8);
	glVertex2i(col * g_Scale + g_Scale / 8, row * g_Scale + g_Scale - g_Scale / 8);
	glVertex2i(col * g_Scale + g_Scale - g_Scale / 8, row * g_Scale + g_Scale / 8);

	glEnd();
}

void KeyClick(int button, int x, int y)
{
	if (button == GLUT_KEY_F1)
	{
		if (g_cell.counter == 0)
		{
			Player = !Player;
		}
	}
}


//Функция реагирующая на нажатие клавиш мыши
void Click(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (WinnerX || WinnerO || Draw)
		{
			exit(0);
		}

		row = y / g_Scale;
		col = x / g_Scale;


		if (g_cell.value[row][col] == '0')
		{
			if (Player)
			{
				//Записываем крестик в массив
				g_cell.value[row][col] = 'X';
				g_cell.counter++;
			}
			else
			{
				//Записываем нолик в массив
				g_cell.value[row][col] = 'O';
				g_cell.counter++;
			}
			CheckHorizontal();

			CheckVertical();

			CheckMainDiagonal();

			CheckSecondaryDiagonal();
			//Меняем игрока
			Player = !Player;
		}
		else
		{
			return;
		}
	}
}

//Функция которая отрисовывает нужный символ(Х или О)
void FillBoxes()
{
	for (int i = 0; i < g_proportions; i++)

		for (int j = 0; j < g_proportions; j++)

		{
			if (g_cell.value[i][j] == 'X')
			{
				DrawXmark(j, i);
			}
			else if (g_cell.value[i][j] == 'O')
			{
				DrawCircle(j * g_Scale + g_Scale / 2, i * g_Scale + g_Scale / 2, 50, 30);
			}
		}
}


void Display(void)
{
	glLineWidth(1.0);
	//цвет линии
	glColor3f(0.0, 0.0, 0.0);
	//очистка буфера цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINES);
	for (int i = 0; i < g_width; i += g_Scale)
	{
		//вертикальная разметка
		glVertex2i(i, 0);
		glVertex2i(i, g_height);
		//горизонтальная разметка
		glVertex2i(0, i);
		glVertex2i(g_width, i);


	}
	glEnd();

	FillBoxes();




	if (WinStateXHor)
	{
		DrawCrossingLine(g_Scale / 4, row * g_Scale + g_Scale / 2, g_Scale * g_proportions - g_Scale / 4, row * g_Scale + g_Scale / 2);

		WinnerX = true;
	}

	else if (WinStateOHor)
	{
		DrawCrossingLine(g_Scale / 4, row * g_Scale + g_Scale / 2, g_Scale * g_proportions - g_Scale / 4, row * g_Scale + g_Scale / 2);

		WinnerO = true;
	}

	else if (WinStateXVer)
	{
		DrawCrossingLine(g_Scale * col + g_Scale / 2, g_Scale * g_proportions - g_Scale / 4, g_Scale * col + g_Scale / 2, g_Scale / 4);

		WinnerX = true;
	}

	else if (WinStateOVer)
	{
		DrawCrossingLine(g_Scale * col + g_Scale / 2, g_Scale * g_proportions - g_Scale / 4, g_Scale * col + g_Scale / 2, g_Scale / 4);

		WinnerO = true;
	}

	else if (WinStateXMainD)
	{
		DrawCrossingLine(g_Scale / 4, g_Scale / 4, g_Scale * g_proportions - g_Scale / 4, g_Scale * g_proportions - g_Scale / 4);

		WinnerX = true;
	}

	else if (WinStateOMainD)
	{
		DrawCrossingLine(g_Scale / 4, g_Scale / 4, g_Scale * g_proportions - g_Scale / 4, g_Scale * g_proportions - g_Scale / 4);

		WinnerO = true;
	}

	else if (WinStateXSecD)
	{
		DrawCrossingLine(g_Scale / 4, g_Scale * g_proportions - g_Scale / 4, g_Scale * g_proportions - g_Scale / 4, g_Scale / 4);

		WinnerX = true;
	}

	else if (WinStateOSecD)
	{
		DrawCrossingLine(g_Scale / 4, g_Scale * g_proportions - g_Scale / 4, g_Scale * g_proportions - g_Scale / 4, g_Scale / 4);

		WinnerO = true;
	}

	if (WinnerX)
	{
		drawStrokeText(30, 160, 0.60f, -0.59f, "X WINS");
		drawStrokeText(0, 260, 0.26f, -0.25f, "LEFT CLICK TO EXIT");
	}
	else if (WinnerO)
	{
		drawStrokeText(30, 160, 0.60f, -0.59f, "O WINS");
		drawStrokeText(0, 260, 0.26f, -0.25f, "LEFT CLICK TO EXIT");
	}

	if (g_cell.counter == 9 && WinnerX == false && WinnerO == false)
	{
		Draw = true;
		drawStrokeText(60, 160, 0.60f, -0.59f, "DRAW");
		drawStrokeText(0, 260, 0.26f, -0.25f, "LEFT CLICK TO EXIT");

	}

	//заменяем буфера после отрисовки
	glutSwapBuffers();
}

//обновление картинки
void Timer(int)
{

	Display();
	glutTimerFunc(100, Timer, 0);
}

#endif