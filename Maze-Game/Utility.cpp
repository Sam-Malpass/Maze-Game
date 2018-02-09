/*Header Files*/
#include "Utility.h"
/*Variable Declarations*/
bool PreDisplayed = false;
/*Function Definition - ReadFile*/
string ReadFile(ifstream & GenericFile)
{
	/*Initialize Empty String*/
	string FileBits = "";
	/*Then if the File Exists*/
	if (GenericFile)
	{
		/*While No Error States Occur Within the Stream*/
		while (GenericFile.good())
		{
			/*Initialize Another New String*/
			string ConstructionString;
			/*Write a Line of the File to ConstructionString*/
			getline(GenericFile, ConstructionString);
			/*Add a Newline Character*/
			ConstructionString = ConstructionString + "\n";
			/*Add the Line in ConstructionString to FileBits*/
			FileBits = FileBits + ConstructionString;
		}
		/*Return FileBits, now Loaded with the Data from the File*/
		return FileBits;
	}
	/*Otherwise, if the File Doesn't Exist*/
	else
	{
		/*Return Error Message*/
		return "ERROR : UNABLE TO READ FILE";
	}
}
/*Function Definition - PrintMaze*/
void PrintMaze(char Maze[HEIGHT][WIDTH], int Score)
{
	/*Initialize an Empty String*/
	string Printer = "";
	/*For each Character on Y-Axis*/
	for (int IteratorY = 0; IteratorY < HEIGHT; IteratorY++)
	{
		/*For each Character on X-Axis*/
		for (int IteratorX = 0; IteratorX < WIDTH; IteratorX++)
		{
			/*Store Character in String*/
			Printer = Printer + Maze[IteratorY][IteratorX];
		}
	}
	/*If Maze has Already Been Displayed Once*/
	if (PreDisplayed == true)
	{
		/*Output the Entire Maze with Scoring*/
		printf("\n%s\nScore: %d", Printer.c_str(), Score);
	}
	/*If this is the First Print*/
	else
	{
		/*Output the Entire Maze with Scoring (No Newline)*/
		printf("%s\nScore: %d", Printer.c_str(), Score);
		/*Flag that the Maze has now Been Displayed*/
		PreDisplayed = true;
	}
}