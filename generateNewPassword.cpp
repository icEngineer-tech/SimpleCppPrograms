#include <iostream>
#include <string>
#include <random>

void occ(std::string& s, char c)
{
	unsigned oc{};
	for (auto i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
			oc++;
		if (oc > 1)
		{
			s[i] = '1';
			oc = 0;
		}
	}
}

unsigned distinctL(std::string s)
{
	unsigned count{};
	for (auto i = 0; i < s.size(); i++)
	{
		occ(s, s[i]);
	}
	for (auto i = 0; i < s.size(); i++)
	{
		(s[i] > 96 && s[i] < 123) ? count++ : count;
	}
	return count;
}

int main()
{
	unsigned n{}, k{};
	do
	{
		std::cin >> n >> k;
	} while ((n < 2 || n>100) || (k<2 || k>std::min<unsigned>(n, 26)));

	char* str = new char[n + 1];
	for (auto i = 0; i < n; i++)
	{
		str[i] = rand() % 26 + 97;
	}
	str[n] = '\0';
	std::string s = str;
	while (distinctL(s) > k)
	{
		unsigned index = rand() % n;
		unsigned rep = rand() % n;
		s[rep] = s[index];
	}
	std::cout << s;
	delete[]str;
	return 0;
}
