#pragma once
#include <iostream>
#include <string>
#include <sstream>

class MyClass
{
	int* ar, d, m, y;
	std::string StrFormat;
public:
	MyClass();
	MyClass(int, int, int);
	MyClass(MyClass&&);
	MyClass& operator=(MyClass&&);
	~MyClass();
	operator const char* ();
	explicit operator int();

};
