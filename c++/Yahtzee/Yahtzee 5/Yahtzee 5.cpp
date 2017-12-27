#include <fstream>
#include "dice.h"
#include "prompt.h"
#include  <iostream>

using namespace std;
const string direct = "directions.txt";
const int dienum = 5;

//		Name:	Cameron Cromer
//		Date:	4/21/2015
//		Project:Yahtzee 5 and finished 
//		Purpose: the purpose of this project is to score the die that are rolled after the user finshes their turn. it uses 
//				multiple different arrays to allow the user to select the areas they score. now with added intrusctions and 
//				prompt!
//				the addition of yahtzee scoring, and chance has been made
//				
//				Small and large straights are now possible, along with an improved scoreboard!
//				The Game is now complete with all features besides mulitplayer working

void grandtotal(int upperscore[])    //Art Work
{
	int grandtemp = 0;
	
	for (int i = 0; i < 15; i++)
	{
		grandtemp = grandtemp + upperscore[i];
	}

	cout << "  ********   **********          ******         ****    ****  ***********  " << endl;
	cout << " **          ***     **         **    **         ****    **    **      **  " << endl;
	cout << "**     ***   **      **        **      **        ** **   **    **      **  " << endl;
	cout << "**    ****   *********        ************       **  **  **    **      **  " << endl;
	cout << "***    ***   ***    **       **          **      **   ** **    **      **  " << endl;
	cout << " **     **   ***     **     **            **     **    ****    **      **  " << endl;
	cout << "  ********   ***      **   ***            ***   ****    ****  ***********  " << endl;
	cout << endl;
	cout << "***********     ******    ***********         ******         ***           " << endl;
	cout << "***********    **    **   ***********        **    **        ***           " << endl;
	cout << "    ***        **    **       ***           **      **       ***           " << endl;
	cout << "    ***        **    **       ***          ************      ***           " << endl;
	cout << "    ***        **    **       ***         **          **     ***           " << endl;
	cout << "    ***        **    **       ***        **            **    ***           " << endl;
	cout << "    ***         ******        ***       ***            ***   ************  " << endl << endl;

	cout << grandtemp << "       :)" << endl;
}

void yahtzeelogo()				//more art
{
	cout << "**    **      ***      ***   *** ********* ******** ******* ******* " << endl;
	cout << " **  **      ** **     ***   *** *********     ***  **      **      " << endl;
	cout << "  ****      **   **    *********    ***       ***   ******* ******* " << endl;
	cout << "   **      *********   *********    ***      ***    ******* ******* " << endl;
	cout << "   **     **       **  ***   ***    ***     ***     **      **      " << endl;
	cout << "   **    ***       *** ***   ***    ***    ******** ******* ******* " << endl << endl;
}

void scoreboard(int upperscore[], int diepass[], bool picked[])		//displays scoreboard
{
	int uppertemp = 0, lowertemp = 0;

	if (picked[0] == false)
	{
		cout << "1. Aces: " << endl;
	}
	else
	{
		cout << "1. Aces: " << upperscore[0] << endl;
	}

	if (picked[1] == false)
	{
		cout << "2. Twos: " << endl;
	}
	else
	{
		cout << "2. Twos: " << upperscore[1] << endl;
	}

	if (picked[2] == false)
	{
		cout << "3. Threes: " << endl;
	}
	else
	{
		cout << "3. Threes: " << upperscore[2] << endl;
	}

	if (picked[3] == false)
	{
		cout << "4. Fours: " << endl;
	}
	else
	{
		cout << "4. Fours: " << upperscore[3] << endl;
	}

	if (picked[4] == false)
	{
		cout << "5. Fives: " << endl;
	}
	else
	{
		cout << "5. Fives: " << upperscore[4] << endl;
	}

	if (picked[5] == false)
	{
		cout << "6. Sixes: " << endl;
	}
	else
	{
		cout << "6. Sixes: " << upperscore[5] << endl;
	}


	for (int i = 0; i < 6; i++)										//assignes to Upper Total score
	{
		uppertemp = uppertemp + upperscore[i];
	}

	if (uppertemp > 63)
	{
		uppertemp = uppertemp + 35;
	}

	cout << "Upper Total: " << uppertemp << endl;	
	cout << "____________________________________\n" << endl;

	if (picked[7] == false)
	{
		cout << "7. 3 of a kind: " << endl;
	}
	else
	{
		cout << "7. 3 of a kind: " << upperscore[7] << endl;
	}

	if (picked[8] == false)
	{
		cout << "8. 4 of a kind: " << endl;
	}
	else
	{
		cout << "8. 4 of a kind: " << upperscore[8] << endl;
	}

	if (picked[9] == false)
	{
		cout << "9. Full House: " << endl;
	}
	else
	{
		cout << "9. Full House: " << upperscore[9] << endl;	
	}
		
	if (picked[10] == false)
	{
		cout << "10. Sm. Straight: " << endl;
	}
	else
	{
		cout << "10. Sm. Straight: " << upperscore[10] << endl;
	}

	if (picked[11] == false)
	{
		cout << "11. Lg. Straight: " << endl;
	}
	else
	{
		cout << "11. Lg. Straight: " << upperscore[11] << endl;
	}

	if (picked[12] == false)
	{
		cout << "12. YAHTZEE: " << endl;
	}
	else
	{
		cout << "12. YAHTZEE: " << upperscore[12] << endl;
	}

	if (picked[13] == false)
	{
		cout << "13. Chance: " << endl;
	}
	else
	{
		cout << "13. Chance: " << upperscore[13] << endl;
	}
					
	cout << "YAHTZEE BONUSES " << upperscore[14] << endl;

	for (int i = 7; i < 15; i++)										//assignes to Upper Total score
	{
		lowertemp = lowertemp + upperscore[i];
	}
		lowertemp = lowertemp + uppertemp;
	cout << "Grand Total: " << lowertemp << endl;					
	cout << "____________________________________" << endl;
	cout << "Dies: " << endl;
	cout << diepass[0] << "   " << diepass[1] << "   " << diepass[2] << "   " << diepass[3] << "   " << diepass[4] << endl;



}			

void Sort(int diepass[])	//insertion sort
{
	int count, temp, idx;

	for (count = 1; count < dienum; count++)
	{
		temp = diepass[count];
		idx = count;

		while (idx > 0 && temp < diepass[idx - 1])
		{
			diepass[idx] = diepass[idx - 1];
			idx--;
		}

		diepass[idx] = temp;
	}

	//cout << diepass[0] << endl;
	//cout << diepass[1] << endl;
	//cout << diepass[2] << endl;
	//cout << diepass[3] << endl;
	//cout << diepass[4] << endl;

}

bool displayScore(int upperscore[], int diepass[], bool bonuskeeper, bool picked[])				//scoring choice and calculations
{
	cout << system("cls");

	int scoreChoice;
	bool bonuscheck = false;


	Sort(diepass);
	scoreboard(upperscore, diepass, picked);

	if (upperscore[12] != 0 || upperscore[12] != NULL)
	{
		if (diepass[0] == diepass[1] && diepass[1] == diepass[2] && diepass[2] == diepass[3] && diepass[3] == diepass[4])			// Scores Yahtzee bonuses
		{
			upperscore[14] = upperscore[14] + 100;
		}
	}

	scoreChoice = PromptRange("What would you like to score", 1, 13);



	while (1 == 1)
	{
		if (scoreChoice == 1)
		{
			if (upperscore[0] == NULL)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 1)									//    Assigns the scores on dice to 
					{														//    the score array.    1's
						upperscore[0] = upperscore[0] + diepass[i];			//
					}														//
				}
				picked[0] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
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
			if (upperscore[1] == NULL)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 2)									//    Assigns the scores on dice to 
					{														//    the score array.    2's
						upperscore[1] = upperscore[1] + diepass[i];			//
					}														//
				}
				picked[1] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
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
			if (upperscore[2] == NULL)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 3)									//    Assigns the scores on dice to 
					{														//    the score array.    3's
						upperscore[2] = upperscore[2] + diepass[i];			//
					}														//
				}
				picked[2] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
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
			if (upperscore[3] == NULL)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 4)									//    Assigns the scores on dice to 
					{														//    the score array.    4's
						upperscore[3] = upperscore[3] + diepass[i];			//
					}														//
				}
				picked[3] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
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
			if (upperscore[4] == NULL)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 5)									//    Assigns the scores on dice to 
					{														//    the score array.    5's
						upperscore[4] = upperscore[4] + diepass[i];			//
					}														//
				}
				picked[4] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
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
			if (upperscore[5] == NULL)
			{
				for (int i = 0; i < 5; i++)									//
				{															//  
					if (diepass[i] == 6)									//    Assigns the scores on dice to 
					{														//    the score array.    6's
						upperscore[5] = upperscore[5] + diepass[i];			//
					}														//
				}
				picked[5] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
				break;
			}
			else
			{
				cout << "Error, Six's have been scored already " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}

		}

		if (scoreChoice == 7)
		{
			if (upperscore[7] == 0)				//scores three of a kind
			{
				bool check = false;
				for (int i = 0; i < 3; i++)
				{
					if (diepass[i] == diepass[i+1] && diepass[i + 1] == diepass[i + 2])
					{
						//cout << "I MADE IT HERE" << endl;
						check = true;
						//system("pause");
					}

				}

				if (check == true)
				{
					for (int i = 0; i < 5; i++)
					{
						//cout << "I made it here" << endl;
						upperscore[7] = upperscore[7] + diepass[i];
						//system("Pause");
					}
				}
				picked[7] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
				break;
			}
			else
			{
				cout << "Error, Three of a kind has already been scored. " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}
		}


		if (scoreChoice == 8)
		{
			if (upperscore[8] == 0)				//scores three of a kind
			{
				bool check = false;
				for (int i = 0; i < 2; i++)
				{
					if (diepass[i] == diepass[i + 1] && diepass[i + 1] == diepass[i + 2] && diepass[i + 2] == diepass [i+3])
					{
						check = true;
					}

				}

				if (check == true)
				{
					for (int i = 0; i < 5; i++)
					{
						upperscore[8] = upperscore[8] + diepass[i];
					}
				}
				picked[8] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
				break;
			}
			else
			{
				cout << "Error, Four of a kind has already been scored. " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}
		}

		if (scoreChoice == 9)
		{
			if (upperscore[9] == 0)				//scores three of a kind
			{
				bool checkOne = false;
				bool checkTwo = false;
				int temp = 0;

				for (int i = 0; i < 3; i++)
				{
					if (diepass[i] == diepass[i + 1] && diepass[i + 1] == diepass[i + 2])
					{
						//cout << "I MADE IT HERE" << endl;
						checkOne = true;
						temp = diepass[i];
						//system("pause");
					}

				}

				for (int i = 0; i < 4; i++)
				{
					if (diepass[i] == diepass[i + 1] && diepass[i] != temp)
					{
						checkTwo = true;
					}

					if (diepass[0] == diepass[1] && diepass[1] == diepass[2] && diepass[2] == diepass[3] && diepass[3] == diepass[4])
					{
						checkTwo = true;
					}
				}

				if (checkOne == true && checkTwo == true)
				{
					upperscore[9] = 25;
				}
				picked[9] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
				break;
			}
			else
			{
				cout << "Error, Full House has already been scored. " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}
		}

		if (scoreChoice == 10)
		{																	//		
			if (upperscore[10] == NULL)										//small straight
			{																//	
				bool smallCheck[6];											//			
				
				for (int i = 0; i < 6; i++)
				{
					smallCheck[i] = false;
				}
				
				for (int i = 0; i < 5; i++)
				{
					if (diepass[i] == 1)
					{
						smallCheck[0] = true;
					}

					if (diepass[i] == 2)
					{
						smallCheck[1] = true;
					}

					if (diepass[i] == 3)
					{
						smallCheck[2] = true;
					}

					if (diepass[i] == 4)
					{
						smallCheck[3] = true;
					}

					if (diepass[i] == 5)
					{
						smallCheck[4] = true;
					}

					if (diepass[i] == 6)
					{
						smallCheck[5] = true;
					}
				}

				if (smallCheck[0] == true && smallCheck[1] == true && smallCheck[2] == true && smallCheck[3] == true)
				{
					upperscore[10] = 30;
				}

				if (smallCheck[1] == true && smallCheck[2] == true && smallCheck[3] == true && smallCheck[4] == true)
				{
					upperscore[10] = 30;
				}

				if (smallCheck[2] == true && smallCheck[3] == true && smallCheck[4] == true && smallCheck[5] == true)
				{
					upperscore[10] = 30;
				}

	
				picked[10] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
				break;
			}
			else
			{
				cout << "Error, Small Straight already scored " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}
		}

		if (scoreChoice == 11)
		{
			if (upperscore[11] == NULL)				// large striaght 
			{
				bool largeCheck = false;

				if (diepass[0] + 4 == diepass[0 + 4] && diepass[1] + 2 == diepass[1 + 2] && diepass [2] == 3)   
				{
					largeCheck = true;
				}

				if (largeCheck = true)
				{
					upperscore[11] = 40;
				}
				picked[11] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
				break;
			}
			else
			{
				cout << "Error, Large Straight already scored " << endl;
				scoreChoice = PromptRange("What would you like to score", 1, 13);
			}
		}



		if (scoreChoice == 12)
		{
			if (upperscore[12] == NULL)
			{
				if (diepass[0] == diepass[1] && diepass[1] == diepass[2] && diepass[2] == diepass[3] && diepass[3] == diepass[4])
				{
					
					upperscore[12] = upperscore[12] + 50;									//Yahtzee scoreing
				
				}
				else
				{
					upperscore[12] = 0;
				}
				picked[12] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
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
			if (upperscore[13] == NULL)
			{
				for (int i = 0; i < 5; i++)
				{
					upperscore[13] = upperscore[13] + diepass[i];
				}

				picked[13] = true;
				system("cls");
				scoreboard(upperscore, diepass, picked);
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
		scoreboard(upperscore, diepass, picked);
	}

	for (int i = 7; i < 15; i++)										//assignes to Grand Total score
	{
		upperscore[15] = upperscore[15] + upperscore[i];
		system("cls");
		scoreboard(upperscore, diepass, picked);
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
				scoreboard(upperscore, diepass, picked);
			}
		}
	}

	return bonuskeeper;
}

int *cheatMode(int diepass[])			//choice 4 ;)
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
				for (int counters = 0; counters < 5; counters++)     //Test functions
				{
					cin >> diepass[counters];
					cont++;
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

int *diceRoll(int diepass[])			//rolls die and rerolls for user
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
			cout << "Input Yes to reroll the corresponding die, and No to leave it unchanged" << endl;

			for (int cont = 0; cont < 2;)
			{
			
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

void direction()			//reads from direction file
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
	bool picked[16];
	int choice = 0;
	int diepass[dienum];							//Dice array
	int upperscore[16];						//Score array
	int contiue = 0;
	bool gamecontiue = false;					// gamecontiue[0] = upper range check, gamecontiue [1] = lower range check
	bool bonuskeeper = false;				// for bonus check



	for (int i = 0; i < 16; i++)				// score initializer
	{
		upperscore[i] = NULL;
		picked[i] = false;
	}

	
	yahtzeelogo();

	while (choice != 3)
	{
		choice = PromptRange(" 1: Play\n 2: Directions\n 3: Quit \n Input between", 1, 4);

		if (choice == 1)
		{
			while (gamecontiue == false)  //keeps game going until both all scores have been saved
			{
				diceRoll(diepass);																//dieroll call
				bonuskeeper = displayScore(upperscore, diepass, bonuskeeper, picked);			//score call
				contiue++;																		// turn counter

				if (contiue == 13)
				{
					gamecontiue = true;
					system("cls");
					grandtotal(upperscore);
				}
			}
			break;
		}

		if (choice == 2)
		{
			direction();
		}

		if (choice == 3)
		{
			return 0;
		}

		if (choice == 4)		//FunMode ;)
		{
			while (gamecontiue == false)  //keeps game going until both all scores have been saved
			{
				cheatMode(diepass);																			//Cheat call
				bonuskeeper = displayScore(upperscore, diepass, bonuskeeper, picked);			//score call
				contiue++;

				if (contiue == 13)
				{
					gamecontiue = true;
				}
			}
			break;
		}
	}

	
	return 0;
}