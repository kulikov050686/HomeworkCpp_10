#include "FieldofDreams.h"

void FieldofDreams::Run(const std::string word)
{
	this->word = word;

	Init();
	GameProcess();
	ResultGame();
}

void FieldofDreams::Init()
{
	gamer[0].name = "Gamer 1";
	gamer[0].opportunityToMakeMove = true;

	gamer[1].name = "Gamer 2";
	gamer[1].opportunityToMakeMove = false;

	gamer[2].name = "Gamer 3";
	gamer[2].opportunityToMakeMove = false;
		
	str = std::vector<char>(word.length());

	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = '*';
	}
}

void FieldofDreams::GameProcess()
{
	int i = 0;
	char chr;

	while (!GameOver)
	{
		numberOfCharacters = 0;
		std::cout << "Ход " << gamer[i].name << std::endl;
		GameDrumRotation(5);

		switch (GameDrum::Run())
		{
		case 0:
			std::cout << "Банкрот на барабане!!!" << std::endl;
			gamer[i].numberOfPoints = 0;
			i = NextPlayerNumber(i);
			break;
		case 100:
			std::cout << "100 очков на барабане!!!, буква: ";
			std::cin >> chr;

			if (Answer(chr))
			{
				gamer[i].numberOfPoints += numberOfCharacters * 100;
				DisplayWord();
			}
			else
			{
				i = NextPlayerNumber(i);
			}

			break;
		case 200:
			std::cout << "200 очков на барабане!!!, буква: ";
			std::cin >> chr;

			if (Answer(chr))
			{
				gamer[i].numberOfPoints += numberOfCharacters * 200;
				DisplayWord();
			}
			else
			{
				i = NextPlayerNumber(i);
			}

			break;
		case 300:
			std::cout << "300 очков на барабане!!!, буква: ";
			std::cin >> chr;

			if (Answer(chr))
			{
				gamer[i].numberOfPoints += numberOfCharacters * 300;
				DisplayWord();
			}
			else
			{
				i = NextPlayerNumber(i);
			}

			break;
		case 400:
			std::cout << "400 очков на барабане!!!, буква: ";
			std::cin >> chr;

			if (Answer(chr))
			{
				gamer[i].numberOfPoints += numberOfCharacters * 400;
				DisplayWord();
			}
			else
			{
				i = NextPlayerNumber(i);
			}

			break;
		case 500:
			std::cout << "500 очков на барабане!!!, буква: ";
			std::cin >> chr;

			if (Answer(chr))
			{
				gamer[i].numberOfPoints += numberOfCharacters * 500;
				DisplayWord();
			}
			else
			{
				i = NextPlayerNumber(i);
			}

			break;
		}

		if (WordMatch())
		{
			GameOver = true;
		}
	}
}

int FieldofDreams::NextPlayerNumber(int previousNumber)
{
	gamer[previousNumber].opportunityToMakeMove = false;

	if (previousNumber == gamer.size() - 1)
	{
		previousNumber = 0;
	}
	else
	{
		previousNumber++;
	}

	gamer[previousNumber].opportunityToMakeMove = true;

	return previousNumber;
}

void FieldofDreams::Delay(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void FieldofDreams::GameDrumRotation(int force)
{
	for (int i = 0; i <= force; i++)
	{
		std::cout << "*";
		Delay(1000);
	}

	std::cout << std::endl;
}

void FieldofDreams::DisplayWord()
{
	std::cout << "Слово: ";

	for (size_t i = 0; i < str.size(); i++)
	{
		std::cout << str[i];
	}

	std::cout << std::endl;
}

bool FieldofDreams::PresenceOfCharacterInString(char chr)
{
	for (size_t i = 0; i < word.length(); i++)
	{
		if (word[i] == chr)
		{
			return true;
		}
	}

	return false;
}

int FieldofDreams::NumberOfCharactersInString(char chr)
{
	int k = 0;

	for (size_t i = 0; i < word.size(); i++)
	{
		if (word[i] == chr)
		{
			k++;
		}
	}

	return k;
}

void FieldofDreams::OpenCharactersInWord(char chr)
{
	int k = numberOfCharacters;

	for (size_t i = 0; i < word.size() && k > 0; i++)
	{
		if (word[i] == chr)
		{
			str[i] = word[i];
			k--;
		}
	}
}

bool FieldofDreams::ValidCharacter(char chr)
{
	if ((65 <= chr && chr <= 90) || 
		(97 <= chr && chr <= 122) || 
		(192 <= chr && chr <= 255))
	{
		return true;
	}

	return false;
}

bool FieldofDreams::Answer(char chr)
{
	if (ValidCharacter(chr))
	{
		if (PresenceOfCharacterInString(chr))
		{
			numberOfCharacters = NumberOfCharactersInString(chr);
			OpenCharactersInWord(chr);

			return true;
		}
	}

	return false;
}

bool FieldofDreams::WordMatch()
{
	bool key = true;

	for (size_t i = 0; i < word.length() && key; i++)
	{
		key = key && (word[i] == str[i]);
	}

	return key;
}

void FieldofDreams::ResultGame()
{
	std::cout << "-------------------------------------------------------------------" << std::endl;

	for (size_t i = 0; i < gamer.size(); i++)
	{
		std::cout << gamer[i].name << " количество очков: " << gamer[i].numberOfPoints << std::endl;
	}
}
