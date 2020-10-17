#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <thread>
#include "GameDrum.h"

struct Gamer
{
	/// <summary>
	/// Имя
	/// </summary>
	std::string name = "Gamer";

	/// <summary>
	/// Возможность сделать ход
	/// </summary>
	bool opportunityToMakeMove = false;

	/// <summary>
	/// Количество очков
	/// </summary>
	int numberOfPoints = 0;
};

class FieldofDreams
{
public:

	/// <summary>
	/// Запуск игры
	/// </summary>
	/// <param name="word"> Разгадываемое слово </param>
	void Run(const std::string word);

private:

	/// <summary>
	/// Разгадываемое слово
	/// </summary>
	std::string word;

	/// <summary>
	/// Игроки
	/// </summary>
	std::array<Gamer, 3> gamer;

	/// <summary>
	/// Окончание игры
	/// </summary>
	bool GameOver = false;

	/// <summary>
	/// Строка для вывода
	/// </summary>
	std::vector<char> str;

	/// <summary>
	/// Количество символов
	/// </summary>
	int numberOfCharacters = 0;

	/// <summary>
	/// Инициализация игры
	/// </summary>
	void Init();

	/// <summary>
	/// Игровой процесс
	/// </summary>
	void GameProcess();

	/// <summary>
	/// Номер следующего игрока
	/// </summary>
	/// <param name="previousNumber"> Номер предыдущего игрока </param>	
	int NextPlayerNumber(int previousNumber);

	/// <summary>
	/// Задержка
	/// </summary>
	/// <param name="milliseconds"> Миллисекунды </param>
	void Delay(int milliseconds);

	/// <summary>
	/// Вращение игрового барабана
	/// </summary>
	/// <param name="force"> Сила </param>
	void GameDrumRotation(int force);

	/// <summary>
	/// Отображаемое слово
	/// </summary>
	void DisplayWord();

	/// <summary>
	/// Нахожнение символа в строке
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool PresenceOfCharacterInString(char chr);

	/// <summary>
	/// Количество символов в строке
	/// </summary>
	/// <param name="chr"> Символ </param>	
	int NumberOfCharactersInString(char chr);

	/// <summary>
	/// Открытые символы в слове
	/// </summary>
	/// <param name="chr"> Символ </param>
	void OpenCharactersInWord(char chr);

	/// <summary>
	/// Допустимый символ
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool ValidCharacter(char chr);
	
	/// <summary>
	/// Ответ
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool Answer(char chr);

	/// <summary>
	/// Совпадение слов
	/// </summary>	
	bool WordMatch();

	/// <summary>
	/// Результат игры
	/// </summary>
	void ResultGame();
};

