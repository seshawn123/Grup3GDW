
#include <iostream>
//#include "Source.h"
#include <conio.h>
#include <windows.h>
bool multiplayer;
char row1[7], row2[7], row3[7], row4[7], row5[7], row6[7];

bool gameEnd = false;
bool gameEndc = false;
bool player1 = true;
bool player2 = false;
int move1, check, tie, player2win, player1win;
char playagain;

using namespace std;
string outputBoard();

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int menu()
{
	while (1)
	{
		char response;
		//cout << "Connect 4\n\n";
		SetConsoleTextAttribute(console, 4);
		cout << "\t\t\t _____                                     _       ___ " << "\n"
			"\t\t\t/  __ \\                                   | |     /   |   _" << "\n"
			"\t\t\t| /  \\/    ___   _ __   _ __    ___   ___ | |_   / /| | _| |_" << "\n"
			"\t\t\t| |       / _ \\ |  _ \\ |  _ \\  / _ \\ / __|| __| / /_| ||_   _|" << "\n"
			"\t\t\t| \\__/\\  | (_) || | | || | | ||  __/| (__ | |_  \\___  |  |_|" << "\n"
			"\t\t\t \\____/   \\___/ |_| |_||_| |_| \\___| \\___| \\__|     |_/" << "\n\n";
		SetConsoleTextAttribute(console, 15);

		cout << "\t\t\tPlease enter\n\t\t\tS to Start\n\t\t\tI for Instructions\n\t\t\tE to exit\n\t\t\t";
		cin >> response;
		switch (response)
		{
		case 's':
		case 'S':
			//cout << "yes";
			Beep(659, 500);
			cin.ignore(1000, '\n');
			system("cls");
			return 1;
		case 'i':
		case 'I':
			Beep(659, 500);
			cin.ignore(1000, '\n');
			system("cls");
			return 2;
		case 'e':
		case 'E':
			Beep(659, 500);
			cin.ignore(1000, '\n');
			system("cls");
			return 3;
		default:
			Beep(659, 500);
			cout << "Please enter either Start, Instructions, or Exit\n";
			cin.ignore(1000, '\n');
			system("cls");
			continue;
		}
	}
}

int instruction()
{
	while (1)
	{
		char back;
		SetConsoleTextAttribute(console, 4);
		cout << "\t\t\t _____                                     _       ___ " << "\n"
			"\t\t\t/  __ \\                                   | |     /   |   _" << "\n"
			"\t\t\t| /  \\/    ___   _ __   _ __    ___   ___ | |_   / /| | _| |_" << "\n"
			"\t\t\t| |       / _ \\ |  _ \\ |  _ \\  / _ \\ / __|| __| / /_| ||_   _|" << "\n"
			"\t\t\t| \\__/\\  | (_) || | | || | | ||  __/| (__ | |_  \\___  |  |_|" << "\n"
			"\t\t\t \\____/   \\___/ |_| |_||_| |_| \\___| \\___| \\__|     |_/" << "\n\n";
		SetConsoleTextAttribute(console, 15);
		cout << "Goal - To connect four of your player specific pieces in a row.\nPlayer 1 has the X piece, and the 2nd player has the N piece.\n\nRules - Each player takes a turn in placing their pieces in the empty slots on the digital board.\nIn order to win, four of a players pieces must connect either horizontally, vertically or diagonally.\nIf the digital board is all filled up, the players have the option in either restarting or take it as a draw.\n\nMovement - Players select the numbered column where they want to place their piece\n\nCan play against the computer or with a friend.\n\n";
		cout << "Input B to go back to the main menu.\n";
		cin >> back;
		switch (back)
		{
		case 'b':
		case 'B':
			Beep(659, 500);
			//cout << "yes";
			cin.ignore(1000, '\n');
			system("cls");
			return 1;
		default:
			Beep(659, 500);
			cout << "Please enter Exit\n";
			cin.ignore(1000, '\n');
			system("cls");

		}
		system("cls");
	}

}

/*int exit()
{
	int exit = 8;
	if (move1 == exit)
	{
		return menu();
	}
	if (move1 == exit)
	{
		return menu();
	}
}*/


int main()
{
	while (1)
	{
		int choice = menu();

		switch (choice)
		{
		case 1:
			break;
		case 2:
			instruction();
			break;
		case 3:
			//exit program function or something
			return 0;
			break;
		}
		if (choice == 1)
		{
			int x;
			SetConsoleTextAttribute(console, 4);
			cout << "\t\t\t _____                                     _       ___ " << "\n"
				"\t\t\t/  __ \\                                   | |     /   |   _" << "\n"
				"\t\t\t| /  \\/    ___   _ __   _ __    ___   ___ | |_   / /| | _| |_" << "\n"
				"\t\t\t| |       / _ \\ |  _ \\ |  _ \\  / _ \\ / __|| __| / /_| ||_   _|" << "\n"
				"\t\t\t| \\__/\\  | (_) || | | || | | ||  __/| (__ | |_  \\___  |  |_|" << "\n"
				"\t\t\t \\____/   \\___/ |_| |_||_| |_| \\___| \\___| \\__|     |_/" << "\n\n";
			SetConsoleTextAttribute(console, 15);
			cout << "\t\t\tSingleplayer(1)\n\t\t\tMultiplayer(2)\n\t\t\t";
			cin >> x;
			Beep(659, 500);
			if (x == 1) {
				multiplayer = false;
			}
			else if (x == 2) {
				multiplayer = true;
			}
			while (x > 2) 
			{
				cout << "\t\t\t\tPlease enter a valid input: ";
				cin >> x;
				Beep(659, 500);
			}

			system("cls");
			break;
		}
		else
			continue;
	}

	player1win = 0;
	player2win = 0;
	tie = 0;

	//Row 1
	for (int i = 0; i < 7; i++)
		row1[i] = 'O';
	//Row 2
	for (int i = 0; i < 7; i++)
		row2[i] = 'O';
	//Row 3
	for (int i = 0; i < 7; i++)
		row3[i] = 'O';
	//Row 4
	for (int i = 0; i < 7; i++)
		row4[i] = 'O';
	//Row 5
	for (int i = 0; i < 7; i++)
		row5[i] = 'O';
	//Row 6
	for (int i = 0; i < 7; i++)
		row6[i] = 'O';


	while (gameEnd == false)
	{

		//Player 1
		if (gameEnd == false && player1 == true)
		{
			outputBoard();
			cout << "\t\t\t\t\t\tPlayer 1\n\t\t\t\t\t\tChoose a Column: ";
			cin >> move1;
			Beep(659, 500);

			while (cin.fail()) {
				SetConsoleTextAttribute(console, 4);
				cout << "\t\t\t\t\t\tPlease enter a valid input: ";
				SetConsoleTextAttribute(console, 15);
				cin.clear();
				cin.ignore(256, '\n');
				cin >> move1;
				Beep(659, 500);
			}

			for (int i = 0; i <= 7; i++)
			{
				//Column 1
				if (move1 == (i + 1))
				{
					//Row 6
					if (row6[i] == 'O')
					{
						row6[i] = 'X';
						player1 = false;
						player2 = true;
					}
					else
					{
						//Row 5
						if (row5[i] == 'O')
						{
							row5[i] = 'X';
							player1 = false;
							player2 = true;
						}

						else
						{
							//Row 4
							if (row4[i] == 'O')
							{
								row4[i] = 'X';
								player1 = false;
								player2 = true;
							}
							else
							{
								//Row 3
								if (row3[i] == 'O')
								{
									row3[i] = 'X';
									player1 = false;
									player2 = true;
								}
								else
								{
									//Row 2
									if (row2[i] == 'O')
									{
										row2[i] = 'X';
										player1 = false;
										player2 = true;
									}
									else
									{
										//Row 1
										if (row1[i] == 'O')
										{
											row1[i] = 'X';
											player1 = false;
											player2 = true;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		//Win Sequence
		if (gameEnd == false)
		{
			//Player 1
			check = 0;

			//Up and Down
			for (int i = 0; i < 7; i++)
			{
				if (row6[i] == 'X')
				{
					if (row5[i] == 'X')
					{
						if (row4[i] == 'X')
						{
							if (row3[i] == 'X')
							{
								player1win = 1;
								check = 1;
							}
						}
					}
				}
				if (row5[i] == 'X')
				{
					if (row4[i] == 'X')
					{
						if (row3[i] == 'X')
						{
							if (row2[i] == 'X')
							{
								check = 1;
							}
						}
					}
				}
				if (row4[i] == 'X')
				{
					if (row3[i] == 'X')
					{
						if (row2[i] == 'X')
						{
							if (row1[i] == 'X')
							{
								player1win = 1;
								check = 1;
							}
						}
					}
				}
			}

			//Side to Side
			for (int i = 0; i < 4; i++)
			{
				if ((row1[i] == 'X') && (row1[i + 1] == 'X') && (row1[i + 2] == 'X') && (row1[i + 3] == 'X'))
				{
					player1win = 1;
					check = 1;
				}
				if ((row2[i] == 'X') && (row2[i + 1] == 'X') && (row2[i + 2] == 'X') && (row2[i + 3] == 'X'))
				{
					player1win = 1;
					check = 1;
				}
				if ((row3[i] == 'X') && (row3[i + 1] == 'X') && (row3[i + 2] == 'X') && (row3[i + 3] == 'X'))
				{
					player1win = 1;
					check = 1;
				}
				if ((row4[i] == 'X') && (row4[i + 1] == 'X') && (row4[i + 2] == 'X') && (row4[i + 3] == 'X'))
				{
					player1win = 1;
					check = 1;
				}
				if ((row5[i] == 'X') && (row5[i + 1] == 'X') && (row5[i + 2] == 'X') && (row5[i + 3] == 'X'))
				{
					player1win = 1;
					check = 1;
				}
				if ((row6[i] == 'X') && (row6[i + 1] == 'X') && (row6[i + 2] == 'X') && (row6[i + 3] == 'X'))
				{
					player1win = 1;
					check = 1;
				}
			}

			//Diagonal
			for (int j = 0; j < 4; j++) {
				if ((row6[j] == 'X') && (row5[j + 1] == 'X') && (row4[j + 2] == 'X') && (row3[j + 3] == 'X')) {
					player1win = 1;
					check = 1;
				}
				if ((row5[j] == 'X') && (row4[j + 1] == 'X') && (row3[j + 2] == 'X') && (row2[j + 3] == 'X')) {
					player1win = 1;
					check = 1;
				}
				if ((row4[j] == 'X') && (row3[j + 1] == 'X') && (row2[j + 2] == 'X') && (row1[j + 3] == 'X')) {
					player1win = 1;
					check = 1;
				}
				if ((row6[j + 3] == 'X') && (row5[j + 2] == 'X') && (row4[j + 1] == 'X') && (row3[j] == 'X')) {
					player1win = 1;
					check = 1;
				}
				if ((row5[j + 3] == 'X') && (row4[j + 2] == 'X') && (row3[j + 1] == 'X') && (row2[j] == 'X')) {
					player1win = 1;
					check = 1;
				}
				if ((row4[j + 3] == 'X') && (row3[j + 2] == 'X') && (row2[j + 1] == 'X') && (row1[j] == 'X')) {
					player1win = 1;
					check = 1;
				}

			}

			//Tie Sequence
			if (((row1[1] == 'X') || (row1[1] == 'N')) && ((row1[2] == 'X') || (row1[2] == 'N')) && ((row1[3] == 'X') || (row1[3] == 'N')) && ((row1[4] == 'X') || (row1[4] == 'N')) && ((row1[5] == 'X') || (row1[5] == 'N')) && ((row1[6] == 'X') || (row1[6] == 'N')))
			{
				tie = 1;
				check = 1;
			}

			//Tie Sequence

		}
		system("CLS");


		//Player 2
		if (gameEnd == false && player2 == true && check != 1)
		{
			outputBoard();
			cout << "\t\t\t\t\t\tPlayer 2\n\t\t\t\t\t\tChoose a Column: ";
			if (multiplayer == true) 
			{ 
				cin >> move1; 
			Beep(659, 500);
			}
			if (multiplayer == false) 
			{
				move1 = rand() % 7 + 1; 
			}
			while (cin.fail()) {
				SetConsoleTextAttribute(console, 4);
				cout << "\t\t\t\t\t\tPlease enter a valid input: ";
				SetConsoleTextAttribute(console, 15);
				cin.clear();
				cin.ignore(256, '\n');
				cin >> move1;
				Beep(659, 500);
			}



			for (int i = 0; i <= 7; i++)
			{
				//Column 1
				if (move1 == (i + 1))
				{
					//Row 6
					if (row6[i] == 'O')
					{
						row6[i] = 'N';
						player1 = true;
						player2 = false;
					}
					else
					{
						//Row 5
						if (row5[i] == 'O')
						{
							row5[i] = 'N';
							player1 = true;
							player2 = false;
						}

						else
						{
							//Row 4
							if (row4[i] == 'O')
							{
								row4[i] = 'N';
								player1 = true;
								player2 = false;
							}
							else
							{
								//Row 3
								if (row3[i] == 'O')
								{
									row3[i] = 'N';
									player1 = true;
									player2 = false;
								}
								else
								{
									//Row 2
									if (row2[i] == 'O')
									{
										row2[i] = 'N';
										player1 = true;
										player2 = false;
									}
									else
									{
										//Row 1
										if (row1[i] == 'O')
										{
											row1[i] = 'N';
											player1 = true;
											player2 = false;
										}
									}
								}
							}
						}
					}
				}


			}

		}

		//Win Sequence
		if (gameEnd == false)
		{
			//Player 2
			//Up and Down
			for (int i = 0; i < 7; i++)
			{
				if (row6[i] == 'N')
				{
					if (row5[i] == 'N')
					{
						if (row4[i] == 'N')
						{
							if (row3[i] == 'N')
							{
								check = 1;
								player2win = 1;
							}
						}
					}
				}
				if (row5[i] == 'N')
				{
					if (row4[i] == 'N')
					{
						if (row3[i] == 'N')
						{
							if (row2[i] == 'N')
							{
								check = 1;
								player2win = 1;
							}
						}
					}
				}
				if (row4[i] == 'N')
				{
					if (row3[i] == 'N')
					{
						if (row2[i] == 'N')
						{
							if (row1[i] == 'N')
							{
								check = 1;
								player2win = 1;
							}
						}
					}
				}
			}

			//Side to Side
			for (int i = 0; i < 4; i++)
			{
				if ((row1[i] == 'N') && (row1[i + 1] == 'N') && (row1[i + 2] == 'N') && (row1[i + 3] == 'N'))
				{
					check = 1;
					player2win = 1;
				}
				if ((row2[i] == 'N') && (row2[i + 1] == 'N') && (row2[i + 2] == 'N') && (row2[i + 3] == 'N'))
				{
					check = 1;
					player2win = 1;
				}
				if ((row3[i] == 'N') && (row3[i + 1] == 'N') && (row3[i + 2] == 'N') && (row3[i + 3] == 'N'))
				{
					check = 1;
					player2win = 1;
				}
				if ((row4[i] == 'N') && (row4[i + 1] == 'N') && (row4[i + 2] == 'N') && (row4[i + 3] == 'N'))
				{
					check = 1;
					player2win = 1;
				}
				if ((row5[i] == 'N') && (row5[i + 1] == 'N') && (row5[i + 2] == 'N') && (row5[i + 3] == 'N'))
				{
					check = 1;
					player2win = 1;
				}
				if ((row6[i] == 'N') && (row6[i + 1] == 'N') && (row6[i + 2] == 'N') && (row6[i + 3] == 'N'))
				{
					check = 1;
					player2win = 1;
				}
			}

			//Tie Sequence
			if (((row1[1] == 'X') || (row1[1] == 'N')) && ((row1[2] == 'X') || (row1[2] == 'N')) && ((row1[3] == 'X') || (row1[3] == 'N')) && ((row1[4] == 'X') || (row1[4] == 'N')) && ((row1[5] == 'X') || (row1[5] == 'N')) && ((row1[6] == 'X') || (row1[6] == 'N')))
			{
				tie = 1;
				check = 1;
			}

			//Diagonal
			for (int j = 0; j < 4; j++) {
				if ((row6[j] == 'N') && (row5[j + 1] == 'N') && (row4[j + 2] == 'N') && (row3[j + 3] == 'N')) {
					player2win = 1;
					check = 1;
				}
				if ((row5[j] == 'N') && (row4[j + 1] == 'N') && (row3[j + 2] == 'N') && (row2[j + 3] == 'N')) {
					player2win = 1;
					check = 1;
				}
				if ((row4[j] == 'N') && (row3[j + 1] == 'N') && (row2[j + 2] == 'N') && (row1[j + 3] == 'N')) {
					player2win = 1;
					check = 1;
				}
				if ((row6[j + 3] == 'N') && (row5[j + 2] == 'N') && (row4[j + 1] == 'N') && (row3[j] == 'N')) {
					player2win = 1;
					check = 1;
				}
				if ((row5[j + 3] == 'N') && (row4[j + 2] == 'N') && (row3[j + 1] == 'N') && (row2[j] == 'N')) {
					player2win = 1;
					check = 1;
				}
				if ((row4[j + 3] == 'N') && (row3[j + 2] == 'N') && (row2[j + 1] == 'N') && (row1[j] == 'N')) {
					player2win = 1;
					check = 1;
				}

			}
		}
		system("CLS");

		//Reset Game
		if (check == 1)
		{
			outputBoard();
			if (player1win == 1)
			{
				cout << "Player 1 wins";
			}
			else if (player2win == 1)
			{
				cout << "Player 2 wins";
			}
			else if (tie == 1)
			{
				cout << "It's a tie";
			}
			cout << ", play Again?....\nY for Yes, N for No: ";
			cin >> playagain;
			if ((playagain == 'N') || (playagain == 'n'))
			{
				gameEnd = true;
			}
			else if ((playagain == 'Y') || (playagain == 'y'))
			{
				system("CLS");
				//Row 1
				for (int i = 0; i < 7; i++)
					row1[i] = 'O';
				//Row 2
				for (int i = 0; i < 7; i++)
					row2[i] = 'O';
				//Row 3
				for (int i = 0; i < 7; i++)
					row3[i] = 'O';
				//Row 4
				for (int i = 0; i < 7; i++)
					row4[i] = 'O';
				//Row 5
				for (int i = 0; i < 7; i++)
					row5[i] = 'O';
				//Row 6
				for (int i = 0; i < 7; i++)
					row6[i] = 'O';


				gameEndc = false;
			}
		}

	}

}

string outputBoard()
{
	//Output
		//Num Col
	cout << "\t\t\t\t\t\t 1 2 3 4 5 6 7" << endl;
	cout << "\t\t\t\t\t\t---------------" << endl;
	cout << "\t\t\t\t\t\t";
	//Row 1
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		if (row1[i] == 'X')
		{
			SetConsoleTextAttribute(console, 4);
		}
		if (row1[i] == 'N')
		{
			SetConsoleTextAttribute(console, 3);
		}
		cout << row1[i];
		SetConsoleTextAttribute(console, 15);
	}
	cout << "|" << endl;

	//Row 2
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		if (row2[i] == 'X')
		{
			SetConsoleTextAttribute(console, 4);
		}
		if (row2[i] == 'N')
		{
			SetConsoleTextAttribute(console, 3);
		}
		cout << row2[i];
		SetConsoleTextAttribute(console, 15);
	}
	cout << "|" << endl;

	//Row 3
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		if (row3[i] == 'X')
		{
			SetConsoleTextAttribute(console, 4);
		}
		if (row3[i] == 'N')
		{
			SetConsoleTextAttribute(console, 3);
		}
		cout << row3[i];
		SetConsoleTextAttribute(console, 15);
	}
	cout << "|" << endl;

	//Row 4
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		if (row4[i] == 'X')
		{
			SetConsoleTextAttribute(console, 4);
		}
		if (row4[i] == 'N')
		{
			SetConsoleTextAttribute(console, 3);
		}
		cout << row4[i];
		SetConsoleTextAttribute(console, 15);
	}
	cout << "|" << endl;

	//Row 5
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		if (row5[i] == 'X')
		{
			SetConsoleTextAttribute(console, 4);
		}
		if (row5[i] == 'N')
		{
			SetConsoleTextAttribute(console, 3);
		}
		cout << row5[i];
		SetConsoleTextAttribute(console, 15);
	}
	cout << "|" << endl;

	//Row 6
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		if (row6[i] == 'X')
		{
			SetConsoleTextAttribute(console, 4);
		}
		if (row6[i] == 'N')
		{
			SetConsoleTextAttribute(console, 3);
		}
		cout << row6[i];
		SetConsoleTextAttribute(console, 15);
	}
	cout << "|" << endl;
	cout << "\t\t\t\t\t\t---------------" << endl;
	return("");
}