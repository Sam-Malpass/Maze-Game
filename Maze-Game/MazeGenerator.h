#pragma once
/*Header Files*/
#include <iostream>
#include <stack>
#include <ctime>
#include <Windows.h>
#include "GameHandler.h"
#include "Utility.h"
/*Function Declaration*/
int GenerateLeftRight(int Direction, int X);
int GenerateUpDown(int Direction, int Y);
bool IsGenerationGood(int X, int Y, int Direction, char Maze[HEIGHT][WIDTH]);
void Generator();
/*Inspired by this Algorithm http://stackoverflow.com/questions/8820993/recursive-backtracker-maze-generation-algorithm-stack-loop */