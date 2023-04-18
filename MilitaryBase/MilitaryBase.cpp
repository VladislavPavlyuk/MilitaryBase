/*������������� ���������� �������� ����.���������� ����� ���������� ���� ���������, �� ������� ����� ��������� ������� �������.
��� ������ ������� ����� ����� ����� :
    � �������� ��� �����������.
    � �������� �����������.
    � ����������� ����.
    � ����� Show, ������� ��������� � �������� ��������� ������� �������.

������ ������� ����� ������� ������������� :
1. ������ ������
    a.�������� 20
    b.���� 10
2. ������������ ����������
    a.�������� 70
    b.���� 0
3. ������� �������� ������ �������
    a.�������� 15
    b.���� 150
4. ������ �������� ������ �������
    a.�������� 50
    b.���� 30
5. �����������
    a.�������� 300
    b.���� 100
��� ���� ����� ���������� ��������� ������ ��������, ���������� ��������� ����������� ������� ���������� �� ������ �������� �Flyweight�.
������� �������, ������ ������� ���� ������ ������� ����� ����, ������ ���������� ����� ����� � ���������� ������ ������.
*/

#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

using namespace std;

// Flyweight (Unit) - ��������� ���������, � ������� �������� �������������� ����� �������� ������� ���������.
class Unit abstract
{
protected:
	// ���������� ���������
	char picure;
	int speed;
	int power;

	// ������� ���������
	int X;
	int Y;

public:
	virtual  void Show(int X, int Y) abstract;
};

/*
ConcreteFlyweight (LightInfantry) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
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
ConcreteFlyweight (Trucks) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
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
ConcreteFlyweight (CharacterZ) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
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
FlyweightFactory - ������� ���������������:
- ������� �������-�������������� � ��������� ���;
- ������������ ������� ���������� ���������������. ����� ������ ����������� ��������������,
������ FlyweightFactory ������������� ������������ ��������� ��� ������� �����, ���� �������� ��� ���.
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
	 Client - ������:
		- ������ ������ �� ������ ��� ���������� ���������������;
		- ��������� ��� ������ ������� ��������� ���������������.
	 */
	srand(time(NULL));
	string s = "ITHLAITHLAITHLAITHLA";
	UnitFactory* pCF = new UnitFactory();

	// ������� ���������
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