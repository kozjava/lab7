#include<iostream>
#include"lab1.h"
#include"lab7.h"

using namespace std;

void main()
{
	//Компилится с интами
	setlocale(LC_CTYPE, "Rus");
	Circle *name = new Circle[1];
	name[0].setx(1);
	name[0].sety(2);
	name[0].setr(3);
	Set<Circle>obj(name, 1);
	obj.Show();
	Circle *name2 = new Circle[1];
	name2[0].setx(1);
	name2[0].sety(5);
	name2[0].setr(6);
	Set<Circle>obj1(name2, 1);
	obj1.Show();
	int k;
	cout << "Enter: " << endl;
	cin >> k;
	if (obj.check(k) != obj1.check(k))
	{
		cout << "Correct entered number..." << endl;
	}
	else
	{
		cout << "Nope..." << endl;
	}
	system("pause");
}
