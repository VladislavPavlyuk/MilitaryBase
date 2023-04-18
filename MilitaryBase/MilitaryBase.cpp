/*Спроектируйте приложение «Военная база».Приложение будет отображать план местности, на которой будут размещены военные объекты.
Все боевые единицы имеют нечто общее :
    • Картинку для отображения.
    • Скорость перемещения.
    • Коэффициент силы.
    • Метод Show, который принимает в качестве параметра позицию объекта.

Боевые единицы имеют строгую классификацию :
1. Легкая пехота
    a.Скорость 20
    b.Сила 10
2. Транспортные автомашины
    a.Скорость 70
    b.Сила 0
3. Тяжелая наземная боевая техника
    a.Скорость 15
    b.Сила 150
4. Легкая наземная боевая техника
    a.Скорость 50
    b.Сила 30
5. Авиатехника
    a.Скорость 300
    b.Сила 100
Для того чтобы приложение требовало меньше ресурсов, необходимо построить архитектуру данного приложения на основе паттерна «Flyweight».
Другими словами, объект каждого типа боевой единицы будет один, однако рисоваться будет сразу в нескольких частях экрана.
*/

#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

using namespace std;

// Flyweight (Unit) - объявляет интерфейс, с помощью которого приспособленцы могут получать внешнее состояние.
class Unit abstract
{
protected:
	// внутреннее состояние
	char picure;
	int speed;
	int power;

	// внешнее состояние
	int X;
	int Y;

public:
	virtual  void Show(int X, int Y) abstract;
};

/*
ConcreteFlyweight (LightInfantry) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым.
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
*/

class LightInfantry : public Unit
{
public:
	LightInfantry()
	{
		picure = 'I';
		power = 100;
		speed = 120;
	}
	void Show(int X, int Y) override
	{
		this->X = X;
		this->Y = Y;
		char buffer[100];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { X, Y };
		SetConsoleCursorPosition(hConsole, pos);
		sprintf_s(buffer, " (X: %d   Y: %d)\n", this->X, this->Y);
		cout << this->picure << buffer;
	}
};

/*
ConcreteFlyweight (Trucks) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым.
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
*/
class Trucks : public Unit
{
public:
	Trucks()
	{
		picure = 'T';
		power = 70;
		speed = 0;
	}
	void Show(int X, int Y) override
	{
		this->X = X;
		this->Y = Y;
		char buffer[100];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { X, Y };
		SetConsoleCursorPosition(hConsole, pos);
		sprintf_s(buffer, " (X: %d   Y: %d)\n", this->X, this->Y);
		cout << this->picure << buffer;
	}
};

//...
/*
ConcreteFlyweight (CharacterZ) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым.
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
*/

class HeavyMachines : public Unit
{
public:
	HeavyMachines()
	{
		picure = 'H';
		power = 15;
		speed = 150;
	}
	void Show(int X, int Y) override
	{
		this->X = X;
		this->Y = Y;
		char buffer[100];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { X, Y };
		SetConsoleCursorPosition(hConsole, pos);
		sprintf_s(buffer, " (X: %d   Y: %d)\n", this->X, this->Y);
		cout << this->picure << buffer;
	}
};

class LightMachines : public Unit
{
public:
	LightMachines()
	{
		picure = 'L';
		power = 50;
		speed = 30;
	}
	void Show(int X, int Y) override
	{
		this->X = X;
		this->Y = Y;
		char buffer[100];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { X, Y };
		SetConsoleCursorPosition(hConsole, pos);
		sprintf_s(buffer, " (X: %d   Y: %d)\n", this->X, this->Y);
		cout << this->picure << buffer;
	}
};

class Aviation : public Unit
{
public:
	Aviation()
	{
		picure = 'A';
		power = 300;
		speed = 100;
	}
	void Show(int X, int Y) override
	{
		this->X = X;
		this->Y = Y;
		char buffer[100];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { X, Y };
		SetConsoleCursorPosition(hConsole, pos);

		sprintf_s(buffer, " (X: %d   Y: %d)\n", this->X, this->Y);
		cout << this->picure << buffer;
	}
};

/*
FlyweightFactory - фабрика приспособленцев:
- создает объекты-приспособленцы и управляет ими;
- обеспечивает должное разделение приспособленцев. Когда клиент запрашивает приспособленца,
объект FlyweightFactory предоставляет существующий экземпляр или создает новый, если готового еще нет.
*/
class UnitFactory
{
private:
	map<char, Unit*> units;
public:
	Unit* GetUnit(char key)
	{
		Unit* unit = units[key];
		if (unit == nullptr)
		{
			switch (key)
			{
			case 'I':
				unit = new LightInfantry();
				break;

			case 'T':
				unit = new Trucks();
				break;

			case 'H':
				unit = new HeavyMachines();
				break;
			
			case 'L':
				unit = new LightMachines();
				break;

			case 'A':
				unit = new Aviation();
				break;
			}
			units[key] = unit;
		}
		return unit;
	}
};

int main()
{
	/*
	 Client - клиент:
		- хранит ссылки на одного или нескольких приспособленцев;
		- вычисляет или хранит внешнее состояние приспособленцев.
	 */
	srand(time(NULL));
	string s = "ITHLAITHLAITHLAITHLA";
	UnitFactory* pCF = new UnitFactory();

	// внешнее состояние
	int X, Y;

	for (int i = 0; i < s.length(); i++)
	{
		X = rand() % 120 + 1;
		Y = rand() % 48 + 1;
		Unit* character = pCF->GetUnit(s[i]);
		character->Show(X, Y);

	}

	system("pause");
}