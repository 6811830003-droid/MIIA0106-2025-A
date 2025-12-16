#include <iostream>
using namespace std;

void swapval(int a, int b) 
{
	int temp = a;
	a = b;
	b = temp;

}
void swapref(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main() 
{
	int a = 10, b = 20;
	cout << "Before swap:" << endl;
	cout << "a = " << a << ", b = " << b << endl;
	swapval(a, b); 
	cout << "After swapval (in main):" << endl;
	cout << "a = " << a << ", b = " << b << endl;
	swapref(a, b);
	cout << "After swapref (in main):" << endl;
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}
