#include "MyClass.h"

MyClass::MyClass(int day, int month, int year)
	:d(day), m(month), y(year)
{
	ar = new int[3];
	for (int i = 0; i < 3; i++)
		ar[i] = i;
}

MyClass::operator const char* ()
{
	std::ostringstream format;
	if (ar != NULL)
	{
		format << "the day is: " << d << " " << ar[0] << " " << ar[1] << " " << ar[2];
		StrFormat = format.str();
	}
	else
	{
		format << "NULL PTR to array!";
		StrFormat = format.str();
	}
	return StrFormat.c_str();
}
MyClass::operator int()
{
	return d + m + y;
}
MyClass::MyClass(MyClass&& c)
	:d(std::move(5))
{
	if (c.ar != NULL)
	{
		ar = c.ar;
		c.ar = NULL;
	}
}
MyClass& MyClass::operator=(MyClass&& c)
{
	if (c.ar != NULL)
	{
		ar = c.ar;
		c.ar = NULL;
	}
	return *this;
}
MyClass::MyClass()
{
	ar = new int[3];
	for (int i = 0; i < 3; i++)
		ar[i] = i + 5;
}
MyClass::~MyClass() { delete[]ar; }
