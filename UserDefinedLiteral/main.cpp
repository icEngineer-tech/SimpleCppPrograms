#include "Temperature.h"
#include <iostream>


Temperature operator"" _C(unsigned long long cel)
{
	return Temperature(cel + 273);
}

int main()
{
	Temperature t = 12_C;
	std::cout << "t is: " << t.temp << " Kelvin";
	return 0;
}
