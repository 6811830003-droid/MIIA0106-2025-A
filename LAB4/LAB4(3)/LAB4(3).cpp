#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Sum from 1 to 100" << endl;
	int sum = 0;
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		sum += i; // sum = sum + i
	}
	cout << "Sum from 1 to 100 = " << sum << endl;

	return 1;
}