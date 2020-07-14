#include <iostream>
#include <vector>

std::vector<signed short> is_even(unsigned);
std::vector<signed short> is_odd(unsigned);

int main()
{
	std::cout << "Enter a number: ";
	unsigned n{};
	std::cin >> n;
	std::vector<signed short>s;
	n % 2 == 0 ? (s = is_even(n)) : (s = is_odd(n));
	for (auto i : s)
		std::cout << i << " ";
	return 0;
}

std::vector<signed short> is_even(unsigned n)
{
	std::vector<signed short> v;
	int i = 0;
	signed short sum = -pow(n, 2);
	signed prod = 1;
	v.push_back(sum);
	for (; i <= (n / 2); i++)
	{
		prod *= (2 * i + 1);
		sum += prod;
		v.push_back(sum);
		//sum -= prod;
	}
return v;
}
std::vector<signed short> is_odd(unsigned n)
{
	std::vector<signed short> v;
	int i = 0;
	signed short sum = -pow(n, 2);
	signed prod = 1;
	v.push_back(sum);
	for (; i <= ((n+1) / 2); i++)
	{
		prod *= (2 * i + 1);
		sum += prod;
		v.push_back(sum);
		//sum -= prod;
	}
	return v;
}
