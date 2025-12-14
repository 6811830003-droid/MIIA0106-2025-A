#include <iostream>
#include <random>
#include <limits>

int main()
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 100);

    std::cout << "เกมทายเลข (สุ่มเลข 1-100)\n";

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y')
    {
        int target = dist(rng);
        int guess = 0;
        int attempts = 0;

        std::cout << "\nระบบได้สุ่มเลขแล้ว ลองทายดูครับ/ค่ะ\n";

        while (true)
        {
            std::cout << "ป้อนหมายเลข (1-100): ";
            if (!(std::cin >> guess))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ค่าที่ป้อนไม่ถูกต้อง — กรุณาป้อนตัวเลขเท่านั้น\n";
                continue;
            }

            if (guess < 1 || guess > 100)
            {
                std::cout << "โปรดป้อนตัวเลขระหว่าง 1 ถึง 100\n";
                continue;
            }

            ++attempts;

            if (guess == target)
            {
                std::cout << "ยินดีด้วย! ถูกต้องแล้ว — คุณทายทั้งหมด " << attempts << " ครั้ง\n";
                break;
            }
            else if (guess < target)
            {
                std::cout << "น้อยเกินไป\n";
            }
            else
            {
                std::cout << "มากเกินไป\n";
            }
        }

        std::cout << "เล่นอีกครั้งหรือไม่? (y/n): ";
        std::cin >> playAgain;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "ขอบคุณที่เล่น\n";
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
