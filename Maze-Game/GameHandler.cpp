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
/*Function Definition - FindStartY*/
int FindStartY(char Maze[HEIGHT][WIDTH])
{
	/*For each Character on Y-Axis*/
	for (int IteratorY = 0; IteratorY < HEIGHT; IteratorY++)
	{
		/*For Each Character on X-Axis*/
		for (int IteratorX = 0; IteratorX < WIDTH; IteratorX++)
		{
			/*If Character is Player*/
			if (Maze[IteratorY][IteratorX] == 'O')
			{
				/*Return Y Co-Ordinate*/
				return IteratorY;
			}
		}
	}
}
/*Function Definition - FindStartX*/
int FindStartX(char Maze[HEIGHT][WIDTH])
{
	/*For Each Character on Y-Axis*/
	for (int IteratorY = 0; IteratorY < HEIGHT; IteratorY++)
	{
		/*For Each Character on X-Axis*/
		for (int IteratorX = 0; IteratorX < WIDTH; IteratorX++)
		{
			/*If Character is Player*/
			if (Maze[IteratorY][IteratorX] == 'O')
			{
				/*Return X Co-Ordinate*/
				return IteratorX;
			}
		}
	}
}
/*Function Definition - Inputting*/
void Inputting(char Maze[HEIGHT][WIDTH], int Y, int X)
{
	/*Variable Setting*/
	IsFinished = false;
	Moves = 0;
	/*While Maze is Unfinished*/
	while (IsFinished == false)
	{
		/*Variable Declaration*/
		bool Able = false;
		char Key;
		/*Get User's Input Without Enter*/
		Key = _getch();
		/*Checks Key and Performs Completion Check*/
		if (Key == 'w' || Key == 'W')
		{
			/*Determines Whether Movement is Possible*/
			Able = MovementCheck(Maze, Y, X, Key);
			/*Checks if Able*/
			if (Able == true)
			{
				/*Sets the Postion Being Moved to as the Player Counter*/
				Maze[Y - 1][X] = 'O';
				/*Changes Current Positon to Path*/
				Maze[Y][X] = ' ';
				/*Changes Coordinates for Current Position*/
				Y = Y - 1;
				/*Refreshes the Output*/
				PrintMaze(Maze, Score);
			}
		}
		/*Checks Key and Performs Completion Check*/
		if (Key == 'a' || Key == 'A')
		{
			/*Determines Whether Movement is Possible*/
			Able = MovementCheck(Maze, Y, X, Key);
			/*Checks if Able*/
			if (Able == true)
			{
				/*Sets the Postion Being Moved to as the Player Counter*/
				Maze[Y][X - 1] = 'O';
				/*Changes Current Positon to Path*/
				Maze[Y][X] = ' ';
				/*Changes Coordinates for Current Position*/
				X = X - 1;
				/*Refreshes the Output*/
				PrintMaze(Maze, Score);
			}
		}
		/*Checks Key and Performs Completion Check*/
		if (Key == 's' || Key == 'S')
		{
			/*Determines Whether Movement is Possible*/
			Able = MovementCheck(Maze, Y, X, Key);
			/*Checks if Able*/
			if (Able == true)
			{
				/*Sets the Postion Being Moved to as the Player Counter*/
				Maze[Y + 1][X] = 'O';
				/*Changes Current Positon to Path*/
				Maze[Y][X] = ' ';
				/*Changes Coordinates for Current Position*/
				Y = Y + 1;
				/*Refreshes the Output*/
				PrintMaze(Maze, Score);
			}
		}
		/*Checks Key and Performs Completion Check*/
		if (Key == 'd' || Key == 'D')
		{
			/*Determines Whether Movement is Possible*/
			Able = MovementCheck(Maze, Y, X, Key);
			/*Checks if Able*/
			if (Able == true)
			{
				/*Sets the Postion Being Moved to as the Player Counter*/
				Maze[Y][X + 1] = 'O';
				/*Changes Current Positon to Path*/
				Maze[Y][X] = ' ';
				/*Changes Coordinates for Current Position*/
				X = X + 1;
				/*Refreshes the Output*/
				PrintMaze(Maze, Score);
			}
		}
		/*If Escape Key Pressed*/
		if (Key == 27)
		{
			/*Change Boolean Variables*/
			IsFinished = true;
			IsEscaped = true;
			/*Return Through Functions to Menu*/
			return;
		}
	}
}