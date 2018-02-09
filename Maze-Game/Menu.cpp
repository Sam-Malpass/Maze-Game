/*Header Files*/
#include "Menu.h"
/*Function Definition - Credits*/
void Credits()
{
	/*Clear Console Window*/
	system("cls");
	/*Open File*/
	ifstream Open("Credits.txt");
	/*Initializes a String with Data from Function Call*/
	string Credits = ReadFile(Open);
	/*Outputs String to Console*/
	cout << Credits << endl;
	/*Close File*/
	Open.close();
	/*Wait for a Set Perion of Time*/
	Sleep(2500);
	/*Returns to the Main Menu*/
	return;
}