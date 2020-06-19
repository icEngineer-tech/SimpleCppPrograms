#include <charconv>


unsigned mantiss;
template<typename T, std::enable_if_t<std::is_arithmetic_v<T>, bool> =true>
[[maybe_unused]] std::from_chars_result char_res(const char* f, const char* l,T& val)	//because I may use std::from_chars directly
{
	std::from_chars_result res;
	unsigned point{};
	if(std::is_integral_v<T>)
	{
		while (*f != *l)
		{
			if (*f < 58 && *f > 47)
			{
				res.ec = std::errc();
				val = val * 10 + (static_cast<int>(*f) - 48);
			}
			else
			{
				res.ec = std::errc::invalid_argument;
				break;
			}
			f++;
		}
		return res;
	}
	else if (std::is_arithmetic_v<T>)
	{
		while (*f != *l)
		{
			if (*f < 58 && *f > 47)
			{
				res.ec = std::errc();
				val = val * 10 + (static_cast<int>(*f) - 48);
				if (point == 1)
					mantiss++;
			}
			else if (*f == '.')
			{
				point = 1;
			}
			else
			{
				res.ec = std::errc::invalid_argument;
				break;
			}
			f++;
		}
		return res;
	}
}
