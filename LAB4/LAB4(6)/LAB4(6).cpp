// LAB4(6).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>

enum class LinePosition
{
    Left,
    Center,
    Right,
    Unknown
};

class MotorController
{
public:
    // speeds range -100 (full reverse) .. 100 (full forward)
    void goStraight()
    {
        leftSpeed_  = 80;
        rightSpeed_ = 80;
        printAction("Go straight");
    }

    void turnLeft()
    {
        // example differential speeds to turn left
        leftSpeed_  = 20;
        rightSpeed_ = 80;
        printAction("Turn left");
    }

    void turnRight()
    {
        // example differential speeds to turn right
        leftSpeed_  = 80;
        rightSpeed_ = 20;
        printAction("Turn right");
    }

    void stop()
    {
        leftSpeed_  = 0;
        rightSpeed_ = 0;
        printAction("Stop");
    }

private:
    void printAction(const std::string& action)
    {
        std::cout << action
                  << " | left motor: " << leftSpeed_
                  << " right motor: " << rightSpeed_ << '\n';
    }

    int leftSpeed_  = 0;
    int rightSpeed_ = 0;
};

LinePosition readSensorFromChar(char c)
{
    switch (c)
    {
    case 'l':
    case 'L':
        return LinePosition::Left;
    case 'c':
    case 'C':
        return LinePosition::Center;
    case 'r':
    case 'R':
        return LinePosition::Right;
    default:
        return LinePosition::Unknown;
    }
}

int main()
{
    MotorController controller;

    std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(0, 2); // 0=Left,1=Center,2=Right

    std::cout << "Line Following Robot (simulation)\n";
    std::cout << "Sensor inputs: l = left, c = center, r = right, s = random, q = quit\n\n";

    while (true)
    {
        std::cout << "Enter sensor input (l/c/r/s/q): ";
        char cmd = '\0';
        if (!(std::cin >> cmd))
        {
            // handle EOF or input error
            break;
        }

        if (cmd == 'q' || cmd == 'Q')
        {
            controller.stop();
            break;
        }

        LinePosition pos = LinePosition::Unknown;
        if (cmd == 's' || cmd == 'S')
        {
            int sampled = dist(rng);
            pos = (sampled == 0 ? LinePosition::Left
                 : sampled == 1 ? LinePosition::Center
                                : LinePosition::Right);
            std::cout << "Sensor (random) => "
                      << (pos == LinePosition::Left ? "Left" :
                          pos == LinePosition::Center ? "Center" : "Right")
                      << '\n';
        }
        else
        {
            pos = readSensorFromChar(cmd);
            if (pos == LinePosition::Unknown)
            {
                std::cout << "Invalid input. Use l/c/r/s/q\n";
                continue;
            }
        }

        // Control logic:
        // 1. If line is left  => turn left
        // 2. If line is right => turn right
        // 3. If line is center => go straight
        switch (pos)
        {
        case LinePosition::Left:
            controller.turnLeft();
            break;
        case LinePosition::Right:
            controller.turnRight();
            break;
        case LinePosition::Center:
            controller.goStraight();
            break;
        default:
            controller.stop();
            break;
        }

        // small delay to simulate time between sensor reads / motor actions
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout << "Exiting simulation. Thank you.\n";
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
