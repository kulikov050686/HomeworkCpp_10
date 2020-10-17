#include "GameDrum.h"

int GameDrum::Run()
{
	return 100 * Random(0, 6);
}

int GameDrum::Random(int min, int max)
{
	// Генерируем случайное число
	std::random_device rd;

	// Инициализируем Вихрь Мерсенна случайным стартовым числом 
	std::mt19937 mersenne(rd());

	return min + mersenne() % (max - min);
}
