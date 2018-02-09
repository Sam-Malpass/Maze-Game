/*Header Files*/
#include "GameHandler.h"
/*Variable Declaration*/
char Maze[HEIGHT][WIDTH];
int Score = 0, Moves;
bool IsFinished, IsEscaped;
/*Function Definition - StartGame*/
void StartGame()
{
	/*Variable Declaration*/
	int StartX, StartY;
	IsEscaped = false;
	/*While Escape Key not Pressed*/
	while (IsEscaped == false)
	{
		/*Generate Maze*/
		Generator();
		/*Print Maze*/
		PrintMaze(Maze, Score);
		/*Determine Starting Co-ordinates*/
		StartY = FindStartY(Maze);
		StartX = FindStartX(Maze);
		/*Begin Accepting Inputs*/
		Inputting(Maze, StartY, StartX);
	}
	/*Return when Finished*/
	return;
}