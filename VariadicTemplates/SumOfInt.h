/* this program will return the sum of the INTEGER passed in params, if other param than int is provided then the compiler will throw an 
error, please don't use VS 2019 as some problems with fold expression are not corrected yet */

template<typename P, typename...T, std::enable_if_t<(std::is_integral_v<P>&&...&& std::is_integral_v<T>), bool> = true>
auto sum(P i, T...args)
{
	return (i+(args + ...));
}
