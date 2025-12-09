#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i = 0;

    cout << "for loop from 1 to 10" << endl;
    for (i = 1; i <= 10; i++)
    {
        cout << i << endl;
    }

    i = 0;
    cout << "while loop from 1 to 10" << endl;
    while (i < 10)
    {
        i++;
        cout << i << endl;
    }

    i = 0;

    cout << "do while loop from 1 to 10" << endl;
    do
    {
        i++;
        cout << i << endl;
    } while (i < 10);


    return 1;
}