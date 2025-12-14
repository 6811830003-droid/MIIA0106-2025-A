// LAB4(7).cpp : Check if a number is prime (C++14)
#include <iostream>
#include <cmath>
#include <limits>

// Returns true if n is a prime number.
// Negative numbers, 0 and 1 are not prime.
bool isPrime(long long n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    long long limit = static_cast<long long>(std::sqrt(static_cast<long double>(n)));
    for (long long i = 3; i <= limit; i += 2)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int main()
{
    std::cout << "Prime Checker\n";
    std::cout << "Enter 0 to quit.\n\n";

    while (true)
    {
        std::cout << "Enter an integer: ";
        long long value;
        if (!(std::cin >> value))
        {
            // handle non-integer input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input — please enter an integer.\n";
            continue;
        }

        if (value == 0)
        {
            std::cout << "Exiting.\n";
            break;
        }

        if (isPrime(value))
            std::cout << value << " is a prime number.\n";
        else
            std::cout << value << " is NOT a prime number.\n";
    }

    return 0;
}
