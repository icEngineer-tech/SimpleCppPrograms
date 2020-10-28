
//Example of implementation

#if defined (_MSVC_LANG) && (_MSVC_LANG)<201704L
#error enable C++20 because this project contains Concepts
#endif

#include "uDateTime.h"


template<typename T, size_t s>
_MAYBEUNUSED std::ostream& operator<<(std::ostream& os, std::array<T, s> _Arr)
{
	for (auto i : _Arr)
		os << i;
	os << " ";
	return os;
}
_MAYBEUNUSED std::ostream& operator<<(std::ostream& os, const uTime& t)
{
	os << t.hour << ":" << t.minute << ":" << t.second << " ";
	return os;
}

unsigned main()
{
	uTime t;
	uDate d;
	system("CLS");
	t.getCurrentSystemTime();
	d.getCurrentDate();
	t.set12hour();
	std::cout << t.ToString() << t.getTimeFormat() << '\n';
	std::cout << d.ToString() << '\n';
	std::cout << std::boolalpha;
	std::cout << t.is_12_hour() << '\n';
	std::cout << d.is_leap_year();
	std::cout << d.numberOfDays() << '\n';
	try
	{
		d.setYMD(2021, 5, 6, 2);
	}
	catch (std::string& e)
	{
		std::cout << e;
	}
	uDateTime td;
	std::cout << td.getCurrentDateTime();
	return 0;
}
