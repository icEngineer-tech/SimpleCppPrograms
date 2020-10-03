template <typename... Ts>
void f(Ts... args)
{
	int* p = std::get<0>(std::make_tuple(&args...));
	std::cout << p;
}



int main()
{
	f(5, "hello");
	return 0;
}
