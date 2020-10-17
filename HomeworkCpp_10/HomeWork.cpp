#include "HomeWork.h"

void HomeWork::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	bool exit = false;
	std::string text = "Выберите пункт меню";
	std::vector<std::string> item = { "Задача 1", 
		                              "Задача 2", 
		                              "Задача 3", 
		                              "Задача 4",
		                              "Задача 5",
		                              "Выход" };

	

	MenuController menu(item);

	while (!exit)
	{
		switch (menu.selectedMenuItem(text))
		{
		case 0:
			Task1();
			break;
		case 1:
			Task2();
			break;
		case 2:
			Task3();
			break;
		case 3:
			Task4();
			break;
		case 4:
			Task5();
			break;
		case 5:
			exit = true;
			break;
		}

		_getch();
	}	
}

void HomeWork::Task1()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	size_t n1 = 1;
	size_t n2 = 2;
	size_t n3 = 3;
	size_t n4 = 4;

	std::vector<bool> tiny(n1);
	std::vector<bool> small(n2);
	std::vector<bool> middle(n3);
	std::vector<bool> large(n4);

	std::cout << tiny.size() << " " << small.size() << " " << middle.size() << " " << large.size() << std::endl;
}

void HomeWork::Task2()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::vector<int> fitnessClub(2);
	std::vector<int> score(1);
	std::vector<int> cottage(3);
	std::vector<int> apartmentHouse(15);
	std::vector<int> skyscraper(50);

	std::cout << "Этажность квартала составляет: " << (fitnessClub.size() + score.size() + cottage.size() + apartmentHouse.size() + skyscraper.size()) / 5 << std::endl;
}

void HomeWork::Task3()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	int N = 0;
	std::array<int, 5> house;

	std::cout << "Введите количество зарегистрированных жильцов в пятиэтажке: ";
	std::cin >> N;	

	int sum = 0;

	for (size_t i = 0; i < house.size(); i++)
	{
		std::cout << "Введите количество людей находящихся на этаже: ";
		std::cin >> house[i];
		sum += house[i];
	}

	std::cout << "Уровень самоизиляции: " << sum * 100 / N << std::endl;
}

void HomeWork::Task4()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::array<float, 10> radioStations;

	radioStations[0] = 95.7;
	radioStations[1] = 103.5;
	radioStations[2] = 88.5;
	radioStations[3] = 87.2;
	radioStations[4] = 101.4;
	radioStations[5] = 105.0;
	radioStations[6] = 98.2;
	radioStations[7] = 94.5;
	radioStations[8] = 99.6;
	radioStations[9] = 107.0;

	bool exit = false;
	int i = 0;	

	while (!exit)
	{
		std::cout << "Введите номер радиостанции: ";
		std::cin >> i;

		if (i == 0)
		{
			exit = true;
		}
		else if (i > 0 && i <= radioStations.size())
		{
			std::cout << "Станция: " << radioStations[i - 1] << std::endl;
		}
		else
		{	
			std::cout << "Ошибка ввода!!!" << std::endl;			
		}
	}
}

void HomeWork::Task5()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	FieldofDreams fieldofDreams;

	fieldofDreams.Run("skillbox");
}
