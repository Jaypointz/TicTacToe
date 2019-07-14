#ifndef VARIABLES_H
#define VARIABLES_H
#include <math.h>
#include <iostream>

const short int g_proportions = 3;
const int g_Scale = 120;
const int g_height = g_proportions * g_Scale;
const int g_width = g_proportions * g_Scale;

//—труктура, котора€ имеет в себе пол€ - двумерный массив char (который будет хранить в себе значени€ ’ и ќ - крестиков и ноликов соответственно) и счетчик дл€ подсчета ходов
struct GamePlay
{
	int counter;
	char value[g_proportions][g_proportions];
	GamePlay() :value(), counter(0)
	{
		for (int i = 0; i < g_proportions; i++)
			for (int j = 0; j < g_proportions; j++)
			{
				value[i][j] = '0';
			}
	}
};
GamePlay g_cell;

int col;
int row;

bool Player = true;

bool WinnerX = false;
bool WinnerO = false;
bool Draw = false;

bool WinStateXHor = false;
bool WinStateOHor = false;

bool WinStateXVer = false;
bool WinStateOVer = false;

bool WinStateXMainD = false;
bool WinStateOMainD = false;

bool WinStateXSecD = false;
bool WinStateOSecD = false;

#endif