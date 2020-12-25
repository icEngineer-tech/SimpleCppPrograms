#include <iostream>
#include <random>
#include <string>
#include <vector>

class Student
{
	static unsigned short hash;
	std::vector<char> ALP;
	static std::vector<unsigned short> NONCE;
public:
	Student() 
	{ 
		for (auto i = 65; i < 91; i++)
			ALP.push_back(char(i));
	}
	_NODISCARD void addStudent(std::string subject, std::string pid, char grade)
	{
		std::cout << "\t\t\t\t\tPrevious hash is: " << hash << '\n';
		auto res_sub = std::find(ALP.begin(), ALP.end(), std::toupper(subject.at(0)));
		auto res_pid = std::find(ALP.begin(), ALP.end(), std::toupper(pid.at(0)));
		if (res_sub == ALP.end() && res_pid == ALP.end())
			throw std::string("Error while getting entries for "+subject+"! Please try again");
		unsigned a = (int)(std::toupper(subject.at(0)));
		unsigned b = (int)(std::toupper(pid.at(0)));
		unsigned c = (int)grade;
		unsigned n_Helper = 0;
		std::string val = std::to_string(hash);
		std::string temp;
		temp = val[val.size() - 2];
		temp+=val[val.size() - 1];
		unsigned v = std::stoi(temp);
		unsigned sum = a + b + c - v;
		for (auto i : NONCE)
		{
			if ((i + sum) % 3 == 0)
			{
				hash = i + sum;
				n_Helper = i;
				break;
			}
		}
		std::cout << "The subject is: " << subject << ", the ID is: " << pid << " and the grade is: " << grade;
		std::cout << "\nThe Nonce is: " << n_Helper << " and the hash is: " << hash << '\n';
	}
};
unsigned short Student::hash= rand() % 51 + 200;
std::vector<unsigned short> Student::NONCE{ 1,2,3 };
int main()
{
	Student s;
	try
	{
		s.addStudent("Parks200", "p74", 'F');
		s.addStudent("Rom450", "tf17", 'D');
	}
	catch (std::string s)
	{
		std::cout << s;
	}

	Student s1;
	try
	{
		s1.addStudent("eom450", "7i91", 'A');
	}
	catch (std::string s)
	{
		std::cout << s;
	}

	Student s2;
	try
	{
		s2.addStudent("Eng490", "Az91", 'B');
	}
	catch (std::string s)
	{
		std::cout << s;
	}
	return 0;
}
