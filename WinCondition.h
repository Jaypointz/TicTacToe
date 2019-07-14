#ifndef WINCONDITION_H
#define WINCONDITION_H

#include "variables.h"

//проверка победы по горизонтали
void CheckHorizontal()
{
	for (int i = 0; i < g_proportions; i++)
	{
		if (Player)
		{
			if (g_cell.value[row][i] == 'X')
			{
				WinStateXHor = true;
			}
			else
			{
				WinStateXHor = false;
				break;
			}
		}
		else
		{
			if (g_cell.value[row][i] == 'O')
			{
				WinStateOHor = true;
			}
			else
			{
				WinStateOHor = false;
				break;
			}
		}
	}

}

//проверка победы по вертикали
void CheckMainDiagonal()
{


	for (int i = 0; i < g_proportions; i++)
	{
		if (Player)
		{
			if (g_cell.value[i][i] == 'X')
			{
				WinStateXMainD = true;
			}
			else
			{
				WinStateXMainD = false;
				break;
			}
		}
		else
		{
			if (g_cell.value[i][i] == 'O')
			{
				WinStateOMainD = true;
			}
			else
			{
				WinStateOMainD = false;
				break;
			}
		}
	}


}

//проверка победы по главной диагонали
void CheckSecondaryDiagonal()
{

	for (int i = 0, j = g_proportions - 1; i < g_proportions; i++, j--)
	{
		if (Player)
		{
			if (g_cell.value[i][j] == 'X')
			{
				WinStateXSecD = true;
			}
			else
			{
				WinStateXSecD = false;
				break;
			}
		}
		else
		{
			if (g_cell.value[i][j] == 'O')
			{
				WinStateOSecD = true;
			}
			else
			{
				WinStateOSecD = false;
				break;
			}
		}
	}

}

//проверка победы по побочной диагонали
void CheckVertical()
{

	for (int i = 0; i < g_proportions; i++)
	{
		if (Player)
		{
			if (g_cell.value[i][col] == 'X')
			{
				WinStateXVer = true;
			}
			else
			{
				WinStateXVer = false;
				break;
			}
		}
		else
		{
			if (g_cell.value[i][col] == 'O')
			{
				WinStateOVer = true;
			}
			else
			{
				WinStateOVer = false;
				break;
			}
		}
	}

}

#endif