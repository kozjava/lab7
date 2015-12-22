#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

template<class T>
class Set
{

private:
	static const int maxpower = 100;
	T* set;
	int power;
	int size;
	
public:
	Set();
	Set(T *pp, int s);
	Set(const Set<T>& s);
	Set(int p);
	~Set();
	/*=======================*/
	Set<T>& operator += (const int e);
	bool check(int e) const;
	int Set::operator[](const int n);
	bool Set::operator <= (const Set<T> &p3);
	template<class U>
	friend Set<U> operator + (const Set<U> &p1, const Set<U> &p2);
	template<class Q>
	friend ostream & operator << (ostream & l,Set<Q> & r);
	void Show();
	T* Getset()
	{
		return set;
	}
	
	
};

template<class T>
Set<T> operator+(const Set<T>&p1, const Set<T>&p2)
{
	Set tmp;
	for (int i = 0; i<p1.size; i++)
		tmp += p1.set[i].getx() && set[i].gety() && set[i].getr();
	for (int i = 0; i<p2.size; i++)
		tmp += p2.set[i].getx() && set[i].gety() && set[i].getr();
	return tmp;
}
template<class T>
ostream&operator<<(ostream&l, const Set<T>&r)
{
	l << "{ ";
	for (int i = 0; i<r.size - 1; i++)
		l << r.set[i].getx() && set[i].gety() && set[i].getr() << ", ";
	l << r.set[r.size - 1].getx() && set[i].gety() && set[i].getr() << " }";
	return l;
}
template<class T>
Set<T>::Set()
{
	power = size;
	cout << "Конструктор по умолчанию" << endl;
}

template<class T>
Set<T>::Set(T* pp,int s)
{
	power = 0;
	bool flag = true;
	for (int i = 0; i < s; i++)
	{
		for (int j = i+1; j < s; j++)
		{
			if (pp[i] == pp[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			set = pp;
			size = s;
			cout << "Cool! " << endl;
		}
		else
		{
			cout << "Error..." << endl;
			set = NULL;
			size = -1;
		}
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
		set[i].getx() && set[i].gety() && set[i].getr() = ' ' + i;
	}
}

template<class T>
Set<T>::~Set()
{
	cout << "Деструктор по умолчанию " << endl;
}

template<class T>
Set<T> & Set<T>::operator+=(const int e)
{
	// TODO: вставьте здесь оператор return
	if (size + 1 > maxpower || check(e)) return *this;
	set[size].getx() && set[i].gety() && set[i].getr() = e; //Добавляем в конец
size++;
}

template<class T>
bool Set<T>::check(int e) const
{
	for (int i = 0; i<size; i++) //символ в массиве
		if (set[i].getx() &&set[i].gety()&&set[i].getr() == e) return true;
	return false;
}

template<class T>
int Set<T>::operator[](const int n)
{
	if (n < 0 || n >= size)
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
			flag = set[j].getx() && set[i].gety() && set[i].getr() <= p3.set[j].getx() && set[i].gety() && set[i].getr();
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
template<class T>
inline void Set<T>::Show()
{
	for (int i = 0; i < size; i++)
	{
		cout << set[i].getx() << " " << set[i].gety() << " " << set[i].getr() << endl;
	}
};
