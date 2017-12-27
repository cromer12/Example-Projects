#include <fstream>
#include "dice.h"
#include "prompt.h"
#include  <iostream>

using namespace std;
const string direct = "directions.txt";

//		Name:	Cameron Cromer
//		Date:	4/10/2015
//		Project:Yahtzee 4
//		Purpose: the purpose of this project is to score the die that are rolled after the user finshes their turn. it uses 
//				multiple different arrays to allow the user to select the areas they score. now with added intrusctions and 
//				prompt!
//				the addition of yahtzee scoring, and chance has been made

void scoreboard(int upperscore[], int diepass [])
{																		// Array postion;
	cout << "1. Aces: "		 << upperscore [0] << endl;					// 0
	cout << "2. Twos: "		 << upperscore [1] << endl;					// 1
	cout << "3. Threes: "		 << upperscore [2] << endl;				// 2
	cout << "4. Fours: "		 << upperscore [3] << endl;				// 3
	cout << "5. Fives: "		 << upperscore [4] <<	endl;			// 4
	cout << "6. Sixes: "		 << upperscore [5] << endl;				// 5
	cout << "Upper Total: "  << upperscore [6] << endl;					// 6
	cout << "____________________________________\n" << endl;
	cout << "7. 3 of a kind: "   << upperscore [7]  << endl;			// 7			
	cout << "8. 4 of a kind: "   << upperscore [8]  << endl;				// 8
	cout << "9. Full House: "    << upperscore [9]  << endl;				// 9
	cout << "10. Sm. Straight: "  << upperscore [10] << endl;				// 10
	cout << "11. Lg. Straight: "  << upperscore [11] << endl;				// 11
	cout << "12. YAHTZEE: "       << upperscore [12] << endl;				// 12
	cout << "13. Chance: "        << upperscore [13] << endl;				// 13
	cout << "YAHTZEE BONUSES " << upperscore [14] << endl;				// 14
	cout << "Grand Total: " << upperscore[15] << endl;					// 15
	cout << "____________________________________" << endl;
	cout << "Dies: " << endl;
	cout << diepass[0] << "   " << diepass[1] << "   " << diepass[2] << "   " << diepass[3] << "   " << diepass[4] << endl;



}

bool displayScore(int upperscore[], int diepass[], bool gamecontiue[], bool bonuskeeper)				//first shot at what the scoreboard will look like
{
	int scoreChoice;
	bool bonuscheck = false;

	scoreboard(upperscore, diepass);

	scoreChoice = PromptRange("What would you like to score", 1, 13);

	if (upperscore[12] != 0)
	{
		if (diepass[0] == diepass[1] == diepass[2] == diepass[3] == diepass[4])			// Scores Yahtzee bonuses
		{
			upperscore[14] = upperscore[14] + 100;
		}
	}

	while (1 == 1)
	{
		if (scoreChoice == 1)
		{
			if (upperscore[0] == 0)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 1)									//    Assigns the scores on dice to 
					{														//    the score array.    1's
						upperscore[0] = upperscore[0] + diepass[i];			//
					}														//
				}
				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else
			{
				cout << "Error, One's have been scored already " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}

		}


		if (scoreChoice == 2)
		{
			if (upperscore[1] == 0)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 2)									//    Assigns the scores on dice to 
					{														//    the score array.    2's
						upperscore[1] = upperscore[1] + diepass[i];			//
					}														//
				}
				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else
			{
				cout << "Error, Two's have been scored already " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}

		}


		if (scoreChoice == 3)
		{
			if (upperscore[2] == 0)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 3)									//    Assigns the scores on dice to 
					{														//    the score array.    3's
						upperscore[2] = upperscore[2] + diepass[i];			//
					}														//
				}
				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else
			{
				cout << "Error, Three's have been scored already " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}

		}


		if (scoreChoice == 4)
		{
			if (upperscore[3] == 0)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 4)									//    Assigns the scores on dice to 
					{														//    the score array.    4's
						upperscore[3] = upperscore[3] + diepass[i];			//
					}														//
				}
				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else
			{
				cout << "Error, Four's have been scored already " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}

		}

		if (scoreChoice == 5)
		{
			if (upperscore[4] == 0)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 5)									//    Assigns the scores on dice to 
					{														//    the score array.    5's
						upperscore[4] = upperscore[4] + diepass[i];			//
					}														//
				}
				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else
			{
				cout << "Error, Five's have been scored already ";
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}

		}

		if (scoreChoice == 6)
		{
			if (upperscore[5] == 0)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 6)									//    Assigns the scores on dice to 
					{														//    the score array.    6's
						upperscore[5] = upperscore[5] + diepass[i];			//
					}														//
				}
				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else
			{
				cout << "Error, Six's have been scored already " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}

		}

		if (scoreChoice == 12)
		{
			if (upperscore[12] == 0)
			{
				if (diepass[0] == diepass[1] == diepass[2] == diepass[3] == diepass[4])
				{
					upperscore[12] = upperscore[12] + 50;									//Yahtzee scoreing
				}
				else
				{
					upperscore[12] = 0;
				}

				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else 
			{
				cout << "Error, Yahtzee already scored " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}
		}

		if (scoreChoice == 13)										//scores chance
		{
			if (upperscore[13] == 0)
			{
				for (int i = 0; i < 5; i++)
				{
					upperscore[13] = upperscore[13] + diepass[i];
				}
				system("cls");
				scoreboard(upperscore, diepass);
				break;
			}
			else
			{
				cout << "Error, Chance already scored " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}
			
		}
	}

		for (int i = 0; i < 6; i++)										//assignes to Upper Total score
		{
			upperscore[6] = upperscore[6] + upperscore[i];
			system("cls");
			scoreboard(upperscore, diepass);
		}

		for (int i = 0; i < 15; i++)										//assignes to Grand Total score
		{
			upperscore[15] = upperscore[15] + upperscore[i];
			system("cls");
			scoreboard(upperscore, diepass);
		}

		if (upperscore[6] >= 63)
		{
			bonuscheck = true;
		}

		if (bonuscheck == false)			//used to keep bonus from being scored twice
		{
			if (bonuscheck == true)
			{
				if (upperscore[6] >= 63)
				{
					upperscore[6] = upperscore[6] + 63;
					bonuskeeper = true;
					system("cls");
					scoreboard(upperscore, diepass);
				}
			}
		}
	//end game one
		if (upperscore[0] != 0 && upperscore[1] != 0 && upperscore[2] != 0 && upperscore[3] != 0 && upperscore[4] != 0 && upperscore[5] != 0 && upperscore[6] != 0 && upperscore[7] != 0 && upperscore[8] != 0 && upperscore[9] != 0 && upperscore[10] != 0 && upperscore[11] != 0 && upperscore[12] != 0 && upperscore[13] != 0)
	{
		gamecontiue[0] = true;
	}

	return bonuskeeper;
}

int *diceRoll(int diepass[])
{
	Dice die(6);

	int counter = 0;
	bool quit = 0;
	bool reroll[5];

	for (int i = 0; i < 5; i++)
	{
		reroll[i] = false;
	}


	for (int i = 0; i < 5; i++)
	{
		diepass[i] = die.Roll();
	}

	cout << "Die One: " << diepass[0] << endl;
	cout << "Die Two: " << diepass[1] << endl;
	cout << "Die Three: " << diepass[2] << endl;
	cout << "Die Four: " << diepass[3] << endl;
	cout << "Die Five: " << diepass[4] << endl;




	while (counter < 2)								//two turn counter
	{

		quit = PromptYesNo("Would like to reroll? ");

		if (quit == false)
		{
			break;
		}

		if (quit == true)
		{
			cout << "Input a true to reroll the corresponding die, and false to leave it unchanged" << endl;

			for (int cont = 0; cont < 2;)
			{
				//				for (int counters = 0; counters < 5; counters++)     //Test functions
				//				{
				//					cin >> diepass[counters];
				//				}
				for (int cnt = 0; cnt < 5; cnt++)							//checks to see which die to re-roll.
				{

					if (cnt == 0)
					{
						reroll[0] = PromptYesNo("Die One: ");
					}

					if (cnt == 1)
					{
						reroll[1] = PromptYesNo("Die Two: ");
					}

					if (cnt == 2)
					{
						reroll[2] = PromptYesNo("Die Three: ");
					}

					if (cnt == 3)
					{
						reroll[3] = PromptYesNo("Die Four: ");
					}

					if (cnt == 4)
					{
						reroll[4] = PromptYesNo("Die Five: ");
					}

					cont++;
				}


				if (reroll[0] == true)
				{
					diepass[0] = die.Roll();
				}

				if (reroll[1] == true)
				{
					diepass[1] = die.Roll();
					// all of these reroll die, dependin upon user input
				}

				if (reroll[2] == true)
				{
					diepass[2] = die.Roll();
				}

				if (reroll[3] == true)
				{
					diepass[3] = die.Roll();
				}

				if (reroll[4] == true)
				{
					diepass[4] = die.Roll();
				}

				system("cls");

				cout << "Die One: " << diepass[0] << endl;
				cout << "Die Two: " << diepass[1] << endl;
				cout << "Die Three: " << diepass[2] << endl;
				cout << "Die Four: " << diepass[3] << endl;
				cout << "Die Five: " << diepass[4] << endl << endl;

			}


		}
		counter++;
	}

	system("cls");

	return diepass;

}

void direction()
{
	ifstream directions(direct);
	string line;

	system("cls");

	while (getline(directions, line))
	{
		cout << line << endl;
		line = ' ';
	}

	directions.close();





}

int main()
{
	int choice = 0;
	int diepass[5];							//Dice array
	int upperscore[16];						//Score array
	bool gamecontiue[2];					// gamecontiue[0] = upper range check, gamecontiue [1] = lower range check
	bool bonuskeeper = false;

	for (int i = 0; i < 2; i++)
	{
		gamecontiue[i] = false;				//contiue initilizer
	}

	for (int i = 0; i < 16; i++)				// score initializer
	{
		upperscore[i] = 0;
	}

	while (choice != 3)
	{
		choice = PromptRange(" 1: Play\n 2: Directions\n 3: Quit \n Input between", 1, 3);

		if (choice == 1)
		{
			while (gamecontiue[0] == false)  //keeps game going until both all scores have been saved
			{
				diceRoll(diepass);										//dieroll call
				bonuskeeper = displayScore(upperscore, diepass, gamecontiue, bonuskeeper);			//score call
			}
		}

		if (choice == 2)
		{
			direction();
		}

		if (choice == 3)
		{
			return 0;
		}
	}
	return 0;
}