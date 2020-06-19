#include <iostream>

int main()
{
int a = 1178796145;
	int* pA = &a;
	char* pC = reinterpret_cast<char*>(pA);
	for (int i = 0; i < 4; i++)
		std::cout << *pC++ << std::endl;        /*if the architecture is little endian the output will be: q \0 C F else the reverse order
  return 0;                                   will be outputed */
}
