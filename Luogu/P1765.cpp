#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int a = 0;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a' || s[i] == 'd' || s[i] == 'g' || s[i] == 'j' || s[i] == 'm' || s[i] == 'p' || s[i] == 't' || s[i] == 'w')
			a++;
		else if (s[i] == ' ')
			a++;
		else if (s[i] == 'b' || s[i] == 'e' || s[i] == 'h' || s[i] == 'k' || s[i] == 'n' || s[i] == 'q' || s[i] == 'u' || s[i] == 'x')
			a +=2;
		else if (s[i] == 'b' + 1 || s[i] == 1 + 'e' || s[i] == 1 + 'h' || s[i] == 1 + 'k' || s[i] == 1 + 'n' || s[i] == 1 + 'q' || s[i] == 1 + 'u' || s[i] == 1 + 'x')
			a +=3;
		else if (s[i] == 's' || s[i] == 'z')
			a +=4;
	}
	cout << a << endl;
	return 0;
}
