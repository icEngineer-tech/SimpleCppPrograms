#include "MyClass.h"


int main()
{
	MyClass c(12, 14, 2019);
	MyClass c1;
	c1 = std::move(c);
	std::string mystr(c);
	std::cout << c;
	return 0;
}

/* First notice, I'm using the move only when I have a dynamically memory(ar), otherwise it's wasteful.
   I'm also using the operator const char* to display some data in my class, if you don't create that function you'll get a compiler error.
   why I'm creating std::string mystr(c)? because if you try to do this: and if I didn't explicitly declate "operator int()"
                      MyClass c(12, 14, 2019);
                      MyClass c1;
                      c1 = std::move(c);
                      std::cout << c;
  the compiler will always use operator int() just because all my data are integer so it's easy to add all those data.
  But I'm for adding the line 9 and not for declaring operator int() explicitly */
