#include <fstream>
#include <iostream>
#include <string>


[[nodiscard]]std::string Capitalize(std::string str)
{
	std::ifstream title;
	std::string text;
	title.open(str);
	if (!title.is_open())
		exit(EXIT_FAILURE);
	while (!title.eof())
	{
		std::string word;
		while (title >> word)
		{
			int i = 0;
			while (word[i] < 65 || (word[i]<97 && word[i]>90) || word[i]>122)
			{
				i++;
			}
			word[i] = (word[i] > 96 && word[i] < 123) ? toupper(word[i]) : word[i];
			text += (word+char(32));
		}
	}
	title.close();
	return text;
}
int main()
{
	std::string str = Capitalize("file.txt");
	std::cout << str;
	return 0;
}
