#include <iostream>

int main()
{
	int N{};
	int sum{};
	do
	{
		std::cout << "enter an integer: ";
		std::cin >> N;
	} while (N < 0 || N > 10);
	if (N == 0)
		std::cout << " ";
	else
	{
		sum = -pow(N, 2);
		std::cout << sum << " ";
		for (int i = 0; i <= (3 * N - 2); i++)
		{
			sum += (2 * i + 1);
			std::cout << sum << " ";
		}

	}
	return 0;
}
