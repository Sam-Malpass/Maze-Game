/*Header Files*/
#include "MazeGenerator.h"
/*Variable Declaration*/
extern char Maze[HEIGHT][WIDTH];
/*Function Definition - Generator*/
void Generator()
{
	/*Variable Declaration*/
	int Direction = 0, NumberGood = 0, LocationX = 1, LocationY = 1;
	stack<int> HeightValues;
	stack<int> WidthValues;
	bool Start = false, End = false;
	/*For Each Character on Y-Axis*/
	for (int IteratorY = 0; IteratorY < HEIGHT; IteratorY++)
	{
		/*For Each Character on X-Axis*/
		for (int IteratorX = 0; IteratorX < WIDTH; IteratorX++)
		{
			/*Fill with Wall Character*/
			Maze[IteratorY][IteratorX] = 219;
		}
	}
	srand(time(0));
	/*Move from Co-Ordinate to Co-Ordinate and Carve Out a Path*/
	do
	{
		/*For 'N' Good Moves*/
		for (int MoveIterator = 0; MoveIterator < 4; MoveIterator++)
		{
			if (IsGenerationGood(LocationX, LocationY, MoveIterator, Maze))
			{
				NumberGood++;
			}
		}
		/*If There is Only One Good Move to Make, Take it*/
		if (NumberGood == 1)
		{
			if (IsGenerationGood(LocationX, LocationY, UP, Maze))
			{
				/*Changes Y Coordinate*/
				LocationY = GenerateUpDown(UP, LocationY);
			}
			/*If that Movement is Good*/
			else if (IsGenerationGood(LocationX, LocationY, LEFT, Maze))
			{
				/*Changes X Coordinate*/
				LocationX = GenerateLeftRight(LEFT, LocationX);
			}
			/*If that Movement is Good*/
			else if (IsGenerationGood(LocationX, LocationY, DOWN, Maze))
			{
				/*Changes Y Coordinate*/
				LocationY = GenerateUpDown(DOWN, LocationY);
			}
			else if (IsGenerationGood(LocationX, LocationY, RIGHT, Maze))
			{
				/*Changes X Coordinate*/
				LocationX = GenerateLeftRight(RIGHT, LocationX);
			}
		}
		/*If There are no Good Moves, Move Back Through the Stack*/
		else if (NumberGood == 0)
		{
			/*Set Locations to be Top Elements in Stack*/
			LocationY = HeightValues.top();
			LocationX = WidthValues.top();
			/*Remove Top Elements*/
			HeightValues.pop();
			WidthValues.pop();
		}
		/*If There is More than One Good Move, Push the Stack*/
		else if (NumberGood > 1)
		{
			/*Puts Current Locations Into the Stacks*/
			HeightValues.push(LocationY);
			WidthValues.push(LocationX);
			do
			{
				/*Randomly Choosing Move to Make*/
				Direction = rand() % 4;
			} while (!IsGenerationGood(LocationX, LocationY, Direction, Maze));
			LocationY = GenerateUpDown(Direction, LocationY);
			LocationX = GenerateLeftRight(Direction, LocationX);
		}
		/*Change Current Location to Path*/
		Maze[LocationY][LocationX] = ' ';
		/*Reset Number of Good Moves for Next Loop*/
		NumberGood = 0;
	} while (!WidthValues.empty());
	/*While End Point is Undetermined*/
	while (End == false)
	{
		/*Variable Declaration*/
		int X = rand() % WIDTH, Y = rand() % HEIGHT;
		/*If the Co-Ordinates are Path, Set it to End Point*/
		if (Maze[Y][X] == ' ')
		{
			Maze[Y][X] = 'X';
			/*Flag End Point as Determined*/
			End = true;
		}
	}
	/*While Start Point is Undetermined*/
	while (Start == false)
	{
		/*Variable Declaration*/
		int X = rand() % WIDTH, Y = rand() % HEIGHT;
		/*If the Co-Ordinates are Path, Set it to Start Point*/
		if (Maze[Y][X] == ' ')
		{
			Maze[Y][X] = 'O';
			/*Flag Start Point as Determined*/
			Start = true;
		}
	}
	return;
}
/*Function Definition - GenerateLeftRight*/
int GenerateLeftRight(int Direction, int X)
{
	/*Move the Generator Right by an X Co-Ordinate*/
	if (Direction == RIGHT)
	{
		return X + 1;
	}
	/*Move the Generator Left by an X Co-Ordinate*/
	else if (Direction == LEFT)
	{
		return X - 1;
	}
	/*Otherwise Just Return Current X Co-Ordinate*/
	else
	{
		return X;
	}
}
/*Function Definition - GenerateUpDown*/
int GenerateUpDown(int Direction, int Y)
{
	/*Move the Generator Up by a Y Co-Ordinate*/
	if (Direction == UP)
	{
		return Y - 1;
	}
	/*Move the Generator Down by a Y Co-Ordinate*/
	else if (Direction == DOWN)
	{
		return Y + 1;
	}
	/*Otherwise Just Return Current Y Co-Ordinate*/
	else
	{
		return Y;
	}
}