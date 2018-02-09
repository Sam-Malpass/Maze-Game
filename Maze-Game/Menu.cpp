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
/*Function Definition - Controls*/
void Controls()
{
	/*Clear Console Window*/
	system("cls");
	/*Open File*/
	ifstream Open("Controls.txt");
	/*Initializes a String with Data from Function Call*/
	string Controls = ReadFile(Open);
	/*Outputs String to Console*/
	cout << Controls << endl;
	/*Close File*/
	Open.close();
	/*Wait for User to Leave Page*/
	cout << "					    ";
	system("pause");
	/*Returns to the Main Menu*/
	return;
}
/*Function Definition - HowToPlay*/
void HowToPlay()
{
	/*Clear Console Window*/
	system("cls");
	/*Open File*/
	ifstream Open("How to Play.txt");
	/*Initializes a String with Data from Function Call*/
	string HowToPlay = ReadFile(Open);
	/*Outputs String to Console*/
	cout << HowToPlay << endl;
	/*Close File*/
	Open.close();
	/*Wait for User to Leave Page*/
	cout << "					    ";
	system("pause");
	/*Returns to the Main Menu*/
	return;
}