// LAB4(5).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <limits>

int main()
{
    // Prepare random number generator (1-100)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    const int secret = dist(gen);

    int guess = 0;
    int attempts = 0;

    std::cout << "Number Guessing Game (1-100)\n";
    std::cout << "Enter 0 to quit at any time.\n\n";

    while (true)
    {
        std::cout << "Your guess: ";
        if (!(std::cin >> guess))
        {
            // Handle non-integer input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input — please enter an integer.\n";
            continue;
        }

        if (guess == 0)
        {
            std::cout << "You quit. The secret number was " << secret << ".\n";
            break;
        }

        ++attempts;

        if (guess < secret)
        {
            std::cout << "Too low.\n";
        }
        else if (guess > secret)
        {
            std::cout << "Too high.\n";
        }
        else
        {
            std::cout << "Correct! You found the number in " << attempts << " attempt";
            if (attempts != 1) std::cout << "s";
            std::cout << ".\n";
            break;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
