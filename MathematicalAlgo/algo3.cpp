#include <iostream>
#include <vector>
#include <numbers>

std::vector<float> fill_algo(float);
int main()
{
	float n{};
	do
	{
		std::cout << "Enter a number: ";

		std::cin >> n;
	} while (n < 0.0 && n>1.0);
	n *= std::numbers::pi;
	std::vector<float>s;
	s = fill_algo(n);
	for (auto i : s)
		std::cout << i << " ";

	return 0;
}

std::vector<float> fill_algo(float n)
{
	std::vector<float> v;
	int i = 0;
	float sum{};
	float prod = n;
	float temp{};
	for (; i <= std::nearbyint(pow(n,2)); i++)
	{
		temp += i / std::numbers::pi;
		sum = (temp) * prod;
		v.push_back(sum);
		prod = n;
	}
return v;
}
