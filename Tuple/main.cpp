#include <tuple>
#include <iostream>

template<typename tupleType>
void displayInfoTup(tupleType& tup)
{
	enum { numVal = std::tuple_size<tupleType>::value };                    // enum because the value numVal has to be const
	std::cout << "the size is: " << numVal << '\n';
	std::cout << "Last element is: " << std::get<numVal - 1>(tup) << '\n'; // std::get return the element at that position zero-based indices
}

int main()
{
  std::tuple<int, char, std::string> tup1(std::make_tuple(12, 'r', "Hello!"));
	displayInfoTup(tup1);
	std::tuple<int,bool> tup2(12, false);
	auto tup3(std::tuple_cat(tup2, tup1));
	displayInfoTup(tup3);
	int p; std::string str;
	std::tie(p, std::ignore, std::ignore, std::ignore, str) = tup3; /*std::tie to unpack the content of a tuple into indivual onjects
	std::cout << p << " " << str;                                     and std::ignore to ignore the member tuple at that position */
	return 0;
}
