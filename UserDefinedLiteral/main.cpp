#include "Temperature.h"
#include <iostream>


Temperature operator"" _K(long double cel)
{
	return Temperature(cel + 273);
}
Temperature operator"" _F(unsigned long long fahr)
{
	return Temperature((fahr + 459.67) * 5 / 9);
}
int main()
{
	Temperature t = 12.3_K;		// change 12.3°C to Kelvin
	Temperature t1 = 15_F;		// change 15°C to Fahrenheit
	std::cout << "t is: " << t.temp << " Kelvin\n";
	std::cout << "t1 is: " << t1.temp << " Fahrenheit";
	return 0;
}
