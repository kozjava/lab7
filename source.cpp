#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

template<class T>
class Set
{
private:
	static const int maxpower = 100;
	T set[maxpower];
	int power;
public:
	Set();
	Set(const char* str);
	Set(const Set<T>& s);
	Set(int p);
	~Set();
		/*=======================*/
	Set<T>& operator += (const char e);
	bool check(char e) const;
	int Set::operator[](const int n);
	bool Set::operator <= (const Set<T> &p3);
	template<class U>
	friend Set<U> operator + (const Set<U> &p1, const Set<U> &p2);
	template<class Q>
	friend ostream & operator << (ostream & l, const Set<Q> & r);

};
template<class T>
Set<T> operator+(const Set<T>&p1, const Set<T>&p2)
{
	Set<int> tmp;
	for (int i = 0; i<p1.power; i++)
		tmp += p1.set[i];
	for (int i = 0; i<p2.power; i++)
		tmp += p2.set[i];
	return tmp;
}
template<class T>
ostream&operator<<(ostream&l, const Set<T>&r)
{
	l << "{ ";
	for (int i = 0; i<r.power - 1; i++)
		l << r.set[i] << ", ";
	l << r.set[r.power - 1] << " }";
	return l;
}
template<class T>
Set<T>::Set()
{
	power = 0;
	cout << "Конструктор по умолчанию" << endl;
}

template<class T>
Set<T>::Set(const char * str)
{
	power = 0;
	int len = strlen(str); //длина строки
	if (len > maxpower) return;
	for (int i = 0; i < len; i++) //Заполнение
	{
		*this += str[i];
	}
}

template<class T>
Set<T>::Set(const Set<T>& s)
{
	power = s.power;
	memcpy(set, s.set, sizeof(char)*power);
}

template<class T>
Set<T>::Set(int p)
{
	if (p>maxpower)
	{
		return;
	}
	power = p;
	for (int i = 0; i < p; i++)
	{
		set[i] = ' ' + i;
	}
}

template<class T>
Set<T>::~Set()
{
	cout << "Деструктор по умолчанию " << endl;
}

template<class T>
Set<T> & Set<T>::operator+=(const char e)
{
	// TODO: вставьте здесь оператор return
	if (power + 1 > maxpower || check(e)) return *this;
	set[power] = e; //Добавляем в конец
	power++;
}

template<class T>
bool Set<T>::check(char e) const
{
	for (int i = 0; i<power; i++) //символ в массиве
		if (set[i] == e) return true;
	return false;
}

template<class T>
int Set<T>::operator[](const int n)
{
	if (n < 0 || n >= power)
	{
		cout << "Нет подходящего индеска " << endl;
		exit(1);
	}
	else
	{
		cout << "n = " << n << endl;
		return n;
	}
}

template<class T>
bool Set<T>::operator<=(const Set<T>& p3)
{
	for (int i = 0; i <= power; i++)
	{
		bool flag = false;
		for (int j = 0; j <= p3.power && !flag; j++)
		{
			flag = set[j] <= p3.set[j];
			//flag = p3.set[j] <= set[j];
		}
		if (!flag)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}









Set<int> s1;
Set<int> s2;
char menu()
{
	system("cls");
	cout << "1-Ввод строки('01234')" << endl;
	cout << "2-Добавление новых элементов во множество " << endl;
	cout << "3-Сложение строк " << endl;
	cout << "4-Поиск элемента " << endl;
	cout << "5 - [] " << endl;
	cout << "6 - <= " << endl;
	cout << "7-Выход  " << endl;
	cout << "->: ";
	char c;
	cin >> c;
	return c;
}
void f1()
{
	cout << "s1:" << s1 << endl;
	cout << "Дальше ->";
	_getch();
}
void f2()
{
	int k;
	cout << "Введите Строку(0-9)" << endl;
	for (char i = '0'; i <= '9'; i++)
	{
		cin >> k;
		s2 += k;
	}
	cout << "s2:" << s2 << endl;
	cout << "Далше ->";
	_getch();
}
void f3()
{
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s1+s2: " << s1 + s2 << endl;
	_getch();
}
void f4()
{
	char d;
	cout << "Введите элемент" << endl;
	cin >> d;
	if (s1.check(d))
	{
		cout << "Элемент найден в множестве s1 " << endl;
	}
	else
	{
		cout << "Такого элемента нет в множестве s1" << endl;
	}
	if (s2.check(d))
	{
		cout << "Элемент найден в множестве s2 " << endl;
	}
	else
	{
		cout << "Такого элемента нет в множестве s2" << endl;
	}
	if (s1.check(d) == s2.check(d))
	{
		cout << "100%" << endl;
	}
	else
	{
		cout << "Ошибка... что-то пошло не так" << endl;
	}
	_getch();
}
void f5()
{
	cout << "Введите элемент(0-9)" << endl;
	int current; cin >> current;
	//cout << "Мощность : ";
	if (s2[current])
	{
		cout << "Correct... [] is working " << endl;
	}
	else
	{
		cout << "[] isn't working " << endl;
	}
	cout << "Дальше ->";
	_getch();
}
void f6()
{
	if (s1 <= s2)
	{
		cout << "Множество 1 <= чем множество 2 " << endl;
	}
	else
	{
		cout << "Множество 1 =>  чем множество 2 " << endl;
	}
	cout << "Дальше ->";
	_getch();
}
int main()
{
	setlocale(LC_CTYPE, "russian");
	bool b = true;
	while (b) {
		try
		{
			char c = menu();
			switch (c)
			{
			case '1': f1();
				break;
			case '2': f2();
				break;
			case '3': f3();
				break;
			case '4': f4();
				break;
			case '5':f5();
				break;
			case '6':f6();
				break;
			case '7': b = false;
				break;
			}
		}
		catch (char* ex)
		{
			cout << ex;
		}
	}

	return 0;
}
