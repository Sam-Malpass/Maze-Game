#pragma once
/*Header Files*/
#include <conio.h>
#include "Utility.h"
#include "MazeGenerator.h"
/*Function Declaration*/
void StartGame();
int FindStartY(char Maze[HEIGHT][WIDTH]);
int FindStartX(char Maze[HEIGHT][WIDTH]);
void Inputting(char Maze[HEIGHT][WIDTH], int Y, int X);
bool MovementCheck(char Maze[HEIGHT][WIDTH], int Y, int X, char Key);
void ScoreHandling();
