#include <string>
#include <iostream>



void info(std::string hn)
{
	std::cout << "======================================================================================================================\n";
	std::cout << "\t\t\tBlueMont hotel located in " << hn <<"\n\n";
	std::cout << "\t\t\tTODAY'S ROOM RATES<US$/night>\n\n";
	std::cout << "\tSingle room\tDouble room\tKing room\tSuite room\n\n";
	std::cout << "\t\t60\t\t75\t\t100\t\t150\n";
	std::cout << "======================================================================================================================\n";
}
void End(void)
{
	std::cout << "Thank you!!\n";
	std::cout << "PROGRAMMER: Idriss\n";
	std::cout << "Hotel management Common Project 3\n";
	std::cout << "Due date: August 16 2020\n";
}
