#pragma once
#include <random>

class GameDrum
{
public:

	/// <summary>
	/// Запуск барабана и возвращение результата 
	/// </summary>	
	static int Run();

private:

	/// <summary>
	/// Генератор случайных чисел [min, max)
	/// </summary>
	/// <param name="min"> Минимальное число </param>
	/// <param name="max"> Максимальное число </param>	
	static int Random(int min, int max);
};

