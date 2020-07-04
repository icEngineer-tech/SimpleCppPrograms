#include <iostream>

using namespace std;

void RestartPC(void)
{
	system("shutdown -r");
}
void ShutdownPC(void)
{
	system("shutdown -s");
}
int main()
{
	char c, res;
	cout << "What do you want to do? :";
	cin >> c;
	switch (c)
	{
	case 'r':
		cout << "Do you want really to Restart you Pc?: [y/n] ";
		cin >> res;
		if (res == 'y')
			RestartPC();
		break;
	case 's':
		cout << "Do you want really to Shutdown you Pc?: [y/n] ";
		cin >> res;
		if (res == 's')
			ShutdownPC();
		break;
	}
	return 0;
}
