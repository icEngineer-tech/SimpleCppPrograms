#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void get_integer(int& x)
{
	do
	{
		std::cout << "Enter a positive integer: ";
		std::cin >> x;
	} while (x < 0);
}
bool is_prime(int x)
{
	unsigned count{0};
	std::vector<unsigned> l;
	for (unsigned i = 1; i < x; i++)
		l.push_back(i);
	if (x == 1)
		return true;
	else
	{
		count = std::count_if(l.begin(), l.end(), [&](unsigned i) {return (x % i == 0); });
		return count == 1 ? true : false;
	}
}
double fp(int n)
{
	return std::pow(2, n) / (5 * static_cast<double>(n) + 1);
}
double fnp(int n)
{
	return (static_cast<double>(n) + 1) / std::sqrt(n);
}
double calc(int y)
{
	bool res = is_prime(y);
	return res == true ? fp(y) : fnp(y);
}
int main()
{
	int number{};
	double sum{};
	get_integer(number);
	std::cout << std::boolalpha;
	std::cout << is_prime(number) << '\n';
	for (int i = number; i <= number + 5; i++)
		sum += calc(number);
	std::cout << sum;
	return 0;
}
