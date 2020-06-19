#include <iostream>
#include <string>


extern mantiss;
int main()
{
	std::string str{ "123" };
	int value{};

	auto res = char_res<int>(str.data(), str.data() + str.size(), value);
	if (res.ec == std::errc())
		std::cout << "Value: " << value << "e-" << mantiss;
	else if (res.ec == std::errc::invalid_argument)
		std::cout << "Invalid arg!";
    
	return 0;
}
