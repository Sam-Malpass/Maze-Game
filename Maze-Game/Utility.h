#pragma once
/*Header Files*/
#include <fstream>
#include <string>
#include "Definitions.h"
/*Namespace Declaration*/
using namespace std;
/*Function Declaration*/
string ReadFile(ifstream& GenericFile);
void PrintMaze(char Maze[HEIGHT][WIDTH], int Score);
