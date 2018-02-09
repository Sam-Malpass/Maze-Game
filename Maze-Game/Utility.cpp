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