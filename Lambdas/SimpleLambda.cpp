#include <iostream>

class is_greater
{
	const int& x;
public:
	is_greater(const int& v) :x(v) {}
	auto operator ()(int v)
	{
		return v > x;
	}
};

int main()
{
	
	std::vector<int> vec{ 4,8,3,1 };
  auto l = std::count_if(vec.begin(), vec.end(), is_greater(2));
	std::cout << l;
  // it's equivalent to do this:
  auto f = std::count_if(vec.begin(),vec.end(), [](int t){return t>2;});
  std::cout << f;
  return 0;
  }
