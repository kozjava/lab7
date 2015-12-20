#pragma once
#include<iostream>
#include <conio.h>
#include <stdlib.h>
#include<cmath>

#define PI 3.14159 
using namespace std;
class Circle
{
private:
	int x;
	int y;
	int radius;
	Circle* Array;
	int size = 0;
public:
	Circle(int s)
	{
		size = s;
	}
	Circle::Circle()
	{
		cout << "Constructor" << endl;
	}
	Circle(int X, int Y, int R)
	{
		x = X;
		y = Y;
		radius = R;
	}
	bool setx(int X)
	{
		x = X;
		return true;
	}
	bool sety(int Y)
	{
		y = Y;
		return true;
	}
	bool setr(int R)
	{
		if (R < 0)
		{
			return false;
		}
		radius = R;
		return true;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int getr()
	{
		return radius;
	}
	static bool check(int x, int y, int radius)
	{/*Проверка на вводимые данные с помощью
	 уравнения окружности, где x0, y0 - начало координат.
	 По крайней мере, я так понял проверку
	 */
		int x0 = 0;
		int y0 = 0;
		if (pow((x - x0), 2) + pow((y - y0), 2) == radius)
		{
			cout << "Correct...." << endl;
			cout << endl;
			return true;
		}
		else
		{
			cout << "Error.... Please try again: " << endl;
			cout << endl;
			return false;
		}
	}
	float square()
	{
		cout << "The area of a circle: " << PI *pow(radius, 2) << " square units." << endl;
		cout << endl;
		return PI *pow(radius, 2);
	}
	float length()
	{
		cout << "Circumference: " << 2 * PI * radius << " units" << endl;
		cout << endl;
		return 2 * PI * radius;
	}
	void show()
	{
		cout << this->x << "  " << this->y << "  " << this->radius << endl;
	}
	bool operator==(Circle &b)
	{
		return this->getx() && gety() && getr() == b.getx() && b.gety() && b.getr();
	}
	bool operator!=(Circle &b)
	{
		return this->getx() && gety() && getr() != b.getx() && b.gety() && b.getr();
	}
};
