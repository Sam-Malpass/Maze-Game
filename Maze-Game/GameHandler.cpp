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
/*Function Definiton - MovementCheck*/
bool MovementCheck(char Maze[HEIGHT][WIDTH], int Y, int X, char Key)
{
	/*Begin by Re-Checking Which Key was Entered*/
	if (Key == 'w' || Key == 'W')
	{
		/*Check if Moving to Completion of Maze*/
		if (Maze[Y - 1][X] == 'X')
		{
			/*Clears Console Window*/
			system("cls");
			/*Opens Data File*/
			ifstream Open("Level Complete.txt");
			/*Initializes the String with Data From Function Call*/
			string LevelComplete = ReadFile(Open);
			/*Outputs the Data*/
			cout << LevelComplete << endl;
			/*Closes File*/
			Open.close();
			/*Wait for Set Period of Time*/
			Sleep(1500);
			/*Score Sorting*/
			ScoreHandling();
			/*Reset Game*/
			IsFinished = true;
			/*Add to Move Number*/
			Moves++;
			return true;
		}
		/*Check if Movement Will Lead to Wall*/
		if (Maze[Y - 1][X] != ' ')
		{
			/*Return Movement Isn't Possible*/
			return false;
		}
	}
	if (Key == 'a' || Key == 'A')
	{
		/*Check if Moving to Completion of Maze*/
		if (Maze[Y][X - 1] == 'X')
		{
			/*Clears Console Window*/
			system("cls");
			/*Opens Data File*/
			ifstream Open("Level Complete.txt");
			/*Initializes the String with Data From Function Call*/
			string LevelComplete = ReadFile(Open);
			/*Outputs the Data*/
			cout << LevelComplete << endl;
			/*Closes File*/
			Open.close();
			/*Wait for Set Period of Time*/
			Sleep(1500);
			/*Score Sorting*/
			ScoreHandling();
			/*Reset Game*/
			IsFinished = true;
			/*Add to Move Number*/
			Moves++;
			return true;
		}
		/*Check if Movement Will Lead to Wall*/
		if (Maze[Y][X - 1] != ' ')
		{
			/*Return Movement Isn't Possible*/
			return false;
		}
	}
	if (Key == 's' || Key == 'S')
	{
		/*Check if Moving to Completion of Maze*/
		if (Maze[Y + 1][X] == 'X')
		{
			/*Clears Console Window*/
			system("cls");
			/*Opens Data File*/
			ifstream Open("Level Complete.txt");
			/*Initializes the String with Data From Function Call*/
			string LevelComplete = ReadFile(Open);
			/*Outputs the Data*/
			cout << LevelComplete << endl;
			/*Closes File*/
			Open.close();
			/*Wait for Set Period of Time*/
			Sleep(1500);
			/*Score Sorting*/
			ScoreHandling();
			/*Reset Game*/
			IsFinished = true;
			/*Add to Move Number*/
			Moves++;
			return true;
		}
		/*Check if Movement Will Lead to Wall*/
		if (Maze[Y + 1][X] != ' ')
		{
			/*Return Movement Isn't Possible*/
			return false;
		}
	}
	if (Key == 'd' || Key == 'D')
	{
		/*Check if Moving to Completion of Maze*/
		if (Maze[Y][X + 1] == 'X')
		{
			/*Clears Console Window*/
			system("cls");
			/*Opens Data File*/
			ifstream Open("Level Complete.txt");
			/*Initializes the String with Data From Function Call*/
			string LevelComplete = ReadFile(Open);
			/*Outputs the Data*/
			cout << LevelComplete << endl;
			/*Closes File*/
			Open.close();
			/*Wait for Set Period of Time*/
			Sleep(1500);
			/*Score Sorting*/
			ScoreHandling();
			/*Reset Game*/
			IsFinished = true;
			/*Add to Move Number*/
			Moves++;
			return true;
		}
		/*Check if Movement Will Lead to Wall*/
		if (Maze[Y][X + 1] != ' ')
		{
			/*Return Movement Isn't Possible*/
			return false;
		}
	}
	/*Add to Move Number*/
	Moves++;
	/*After All Checks Have Been Passed, Returns that Movement is Possible*/
	return true;
}
/*Function Definition - ScoreHandling*/
void ScoreHandling()
{
	/*If Number of Moves is Low*/
	if (Moves <= LOW)
	{
		Score = Score + 100;
	}
	/*If Number of Moves is Average*/
	else if (Moves > LOW && Moves <= MED)
	{
		Score = Score + 75;
	}
	/*If Number of Moves is High*/
	else if (Moves > MED && Moves <= HIGH)
	{
		Score = Score + 50;
	}
	/*If Number of Moves is Extremely High*/
	else if (Moves > HIGH && Moves <= MAX)
	{
		Score = Score + 25;
	}
	/*Otherwise Don't Increase Score*/
	else
	{
		Score = Score + 0;
	}
	return;
}