#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//---------------------- 1st version --------------------------------
[[noreturn]]void JoinStrings(char delimiter, std::vector<std::string>&v)
{
	std::string str;
	for (auto i : v)
	{
		if (i != *(v.end()-1) )
			str += (i + delimiter);
		else
			str += i;
	}
	v.clear();
	v.push_back(str);
}
//----------------------------------------------------------------------

//------------------ 2nd version ---------------------------------------
template<typename T>
[[nodiscard]] std::string JoinStrings(T const& First, T const& last, const char* delimiter)
{
	std::ostringstream os;
	std::copy(First, last, std::ostream_iterator<std::string>(os,delimiter));
	os << *(last - 1);
	return os.str();
}

int main()
{
//------------------- 1st version --------------------------------
	std::vector<std::string> v{ "I am","a C++","Programmer","here" };
	std::cout << v.size() << '\n';
	JoinStrings(32, v);
	std::cout << v.size() << '\n';
	for (auto i : v)
		std::cout << i;


//------------------ 2nd version -----------------------------------
	/*std::vector<std::string> v{ "I am","a C++","Programmer","here" };
	std::string str = JoinStrings(32,v);
	std::cout << str;*/
	return 0;
}
