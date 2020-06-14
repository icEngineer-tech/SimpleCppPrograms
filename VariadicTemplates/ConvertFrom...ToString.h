

/*1st version     here it will print only on the console the args that you will enter to function to_str. YOU CANNOT ENTER DYNAMIC
  VALUE BECAUSE TEMPLATES ARE EXECUTED AT COMPILE TIME. */   
template<typename O>          
void to_str(const O& args)
{
	std::cout << args;
}
template<typename P,typename...args>
void to_str(const P& t,args...ar)
{
	std::cout << t << '\n';
	to_str(ar...);
}
//example of execution in main: 
to_str("Hello", 14, 8.2);
/*
NOTE: in the example above, you have to add the to_str() with one param so we can expand ar because we cannot do this: std::cout<<ar...;.
This is an error.
*/

// 2nd version
template<typename P>
std::string to_str(const P& t)
{
	std::ostringstream out;
	out << t;
	return out.str();
}
std::vector<std::string> dis()    //the compiler will complain if it doesn't exist, it's like a specialization
{
	return {};
}
template<typename...var,typename P1>
std::vector<std::string> dis(P1 arg,const var&...s)
{
	std::vector<std::string> v;
	v.push_back(to_str(arg));
	auto rest = dis(s...);
	v.insert(v.end(), rest.begin(), rest.end());
	return v;
}
//example of execution in main:
std::vector<std::string> v = dis(1.5,"Hello", 14);
	for (auto o : v)
		std::cout << o << '\n';
