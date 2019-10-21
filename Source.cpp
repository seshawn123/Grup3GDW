//
//
//
#include <conio.h>
#include <iostream>;
//#include "Source.h"
#include <windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int menu()
{
	while (1)
	{
		char response;
		cout << "Connect 4\n\n";
		cout << "Start\n";
		cout << "Instructions \n";
		cout << "Exit\n\n";
		cout << "Please enter your input as seen above\n";
		cin >> response;
		switch (response) 
		{
		case 's':
		case 'S':
			//cout << "yes";
			cin.ignore(1000, '\n');
			system("cls");
			return 1;
		case 'i':
		case 'I':
			cin.ignore(1000, '\n');
			system("cls");
			return 2;
		case 'e':
		case 'E':
			cin.ignore(1000, '\n');
			system("cls");
			return 3;
		default:
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
		cout << "Enter input: Start.\nPlayer 1 and two are prompt in order to input the line corresponding to the row the Player wants to put their piece in.\n";
		cout << "Input Back to go back to the main menu.\n";
		cin >> back;
		switch (back)
		{
		case 'b':
		case 'B':
			//cout << "yes";
			cin.ignore(1000, '\n');
			system("cls");
			return 1;
		default:
			cout << "Please enter Exit\n";
			cin.ignore(1000, '\n');
			system("cls");

		}
		system("cls");
	}
	
}


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
			break;
		}
		else
			continue;
	} 

	bool gameEnd = false;
	bool gameEndc = false;
	bool player1 = true;
	bool player2 = false;
	int move1, check, tie;
	char playagain;
	char row1[7];
	char row2[7];
	char row3[7];
	char row4[7];
	char row5[7];
	char row6[7];

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

	//Output
	//Num Col
	cout << " 1 2 3 4 5 6 7" << endl;
	cout << "---------------" << endl;
	//Row 1
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		cout << row1[i];
	}
	cout << "|" << endl;
	//Row 2
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		cout << row2[i];
	}
	cout << "|" << endl;
	//Row 3
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		cout << row3[i];
	}
	cout << "|" << endl;
	//Row 4
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		cout << row4[i];
	}
	cout << "|" << endl;
	//Row 5
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		cout << row5[i];
	}
	cout << "|" << endl;
	//Row 6
	for (int i = 0; i < 7; i++)
	{
		cout << "|";
		cout << row6[i];
	}
	cout << "|" << endl;
	cout << "---------------" << endl;

	while (gameEnd == false)
	{

		//Player 1
		if (gameEnd == false && player1 == true)
		{
			cout << "Player 1\nChoose a Column: ";
			cin >> move1;

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
				system("cls");
			}

			//Output
			//Num Col
			cout << " 1 2 3 4 5 6 7" << endl;
			cout << "---------------" << endl;
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
					SetConsoleTextAttribute(console, 1);
				}
				cout << row1[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 2
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row2[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row2[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row2[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 3
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row3[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row3[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row3[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 4
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row4[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row4[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row4[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 5
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row5[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row5[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row5[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 6
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row6[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row6[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row6[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			cout << "---------------" << endl;

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
					check = 1;
				}
				if ((row2[i] == 'X') && (row2[i + 1] == 'X') && (row2[i + 2] == 'X') && (row2[i + 3] == 'X'))
				{
					check = 1;
				}
				if ((row3[i] == 'X') && (row3[i + 1] == 'X') && (row3[i + 2] == 'X') && (row3[i + 3] == 'X'))
				{
					check = 1;
				}
				if ((row4[i] == 'X') && (row4[i + 1] == 'X') && (row4[i + 2] == 'X') && (row4[i + 3] == 'X'))
				{
					check = 1;
				}
				if ((row5[i] == 'X') && (row5[i + 1] == 'X') && (row5[i + 2] == 'X') && (row5[i + 3] == 'X'))
				{
					check = 1;
				}
				if ((row6[i] == 'X') && (row6[i + 1] == 'X') && (row6[i + 2] == 'X') && (row6[i + 3] == 'X'))
				{
					check = 1;
				}
			}

			//Diagonal

		}

		//Player 2
		if (gameEnd == false && player2 == true && check != 1)
		{
			cout << "Player 2\nChoose a Column: ";
			cin >> move1;

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
				system("cls");

			}

			//Output
			//Num Col
			cout << " 1 2 3 4 5 6 7" << endl;
			cout << "---------------" << endl;
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
					SetConsoleTextAttribute(console, 1);
				}
				cout << row1[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 2
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row2[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row2[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row2[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 3
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row3[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row3[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row3[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 4
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row4[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row4[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row4[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 5
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row5[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row5[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row5[i];
				SetConsoleTextAttribute(console, 15);
			}
			cout << "|" << endl;
			//Row 6
			for (int i = 0; i < 7; i++)
			{
				cout << "|";
				if (row6[i] == 'X')
				{
					SetConsoleTextAttribute(console, 4);
				}
				if (row6[i] == 'N')
				{
					SetConsoleTextAttribute(console, 1);
				}
				cout << row6[i];
				SetConsoleTextAttribute(console, 15);
			}

			cout << "|" << endl;
			cout << "---------------" << endl;

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
				}
				if ((row2[i] == 'N') && (row2[i + 1] == 'N') && (row2[i + 2] == 'N') && (row2[i + 3] == 'N'))
				{
					check = 1;
				}
				if ((row3[i] == 'N') && (row3[i + 1] == 'N') && (row3[i + 2] == 'N') && (row3[i + 3] == 'N'))
				{
					check = 1;
				}
				if ((row4[i] == 'N') && (row4[i + 1] == 'N') && (row4[i + 2] == 'N') && (row4[i + 3] == 'N'))
				{
					check = 1;
				}
				if ((row5[i] == 'N') && (row5[i + 1] == 'N') && (row5[i + 2] == 'N') && (row5[i + 3] == 'N'))
				{
					check = 1;
				}
				if ((row6[i] == 'N') && (row6[i + 1] == 'N') && (row6[i + 2] == 'N') && (row6[i + 3] == 'N'))
				{
					check = 1;
				}
			}
		}

		//Tie Sequence
		if (gameEnd == false)
		{
			cout<<("Tie");
		}

		//Reset Game
		if (check == 1)
		{
			cout << "Play Again?....\nY for Yes, N for No: ";
			cin >> playagain;
			if (playagain == 'N')
			{
				gameEnd = true;
			}
			else if (playagain == 'Y')
			{
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

				//Output
		//Num Col
				cout << " 1 2 3 4 5 6 7" << endl;
				cout << "---------------" << endl;
				//Row 1
				for (int i = 0; i < 7; i++)
				{
					cout << "|";
					cout << row1[i];
				}
				cout << "|" << endl;
				//Row 2
				for (int i = 0; i < 7; i++)
				{
					cout << "|";
					cout << row2[i];
				}
				cout << "|" << endl;
				//Row 3
				for (int i = 0; i < 7; i++)
				{
					cout << "|";
					cout << row3[i];
				}
				cout << "|" << endl;
				//Row 4
				for (int i = 0; i < 7; i++)
				{
					cout << "|";
					cout << row4[i];
				}
				cout << "|" << endl;
				//Row 5
				for (int i = 0; i < 7; i++)
				{
					cout << "|";
					cout << row5[i];
				}
				cout << "|" << endl;
				//Row 6
				for (int i = 0; i < 7; i++)
				{
					cout << "|";
					cout << row6[i];
				}
				cout << "|" << endl;
				cout << "---------------" << endl;

				gameEndc = false;
			}
		}

	}



}

	