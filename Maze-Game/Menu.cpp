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
/*Function Definition - PlayGame*/
void PlayGame()
{
	/*Clear the Console Window*/
	system("cls");
	/*Call StartGame*/
	StartGame();
	return;
}
/*Function Definition - MainMenu*/
void MainMenu()
{
	/*Variable Declaration*/
	char UserOption;
	bool RunMenuInfinitely = true;
	/*Plays Music by Kevin Macleod*/
	PlaySoundA(("Menu.WAV"), NULL, SND_ASYNC | SND_LOOP);
	/*Displays Menu Indefinitely*/
	while (RunMenuInfinitely)
	{
		/*Clear Console Window*/
		system("cls");
		/*Open File*/
		ifstream Open("Title.txt");
		/*Initializes a String with Data from Function Call*/
		string Menu = ReadFile(Open);
		/*Outputs String to Console*/
		cout << Menu << endl;
		/*Close File*/
		Open.close();
		/*Prints UserOption Input Field*/
		cout << "						    Option:    ";
		/*Takes the User's Input and Stores it in UserOption*/
		cin >> UserOption;
		/*Compares Input to See if Operation is Performed*/
		switch (UserOption)
		{
			/*Runs the Game*/
		case '1':
			PlayGame();
			break;
			/*Displays Controls*/
		case '2':
			Controls();
			break;
			/*Displays How To Play*/
		case '3':
			HowToPlay();
			break;
			/*Displays Credits*/
		case '4':
			Credits();
			break;
			/*Exits Game*/
		case '5':
			exit(0);
			break;
			/*Refreshes Menu with Invalid Input*/
		default:
			break;
		}
	}
}