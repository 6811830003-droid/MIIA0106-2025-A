// LAB4(6).cpp : Line Following Robot - simulation / simple controller
// Uses C++14
#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <stdexcept>

enum class LinePosition
{
    Left,
    Center,
    Right,
    Unknown
};

class ColorSensor
{
public:
    // If randomMode==true, sensor returns random positions (Left/Center/Right).
    // Otherwise it runs in interactive mode and reads single-character commands from stdin.
    ColorSensor(bool randomMode = false)
        : m_randomMode(randomMode),
          m_rd(),
          m_gen(m_rd()),
          m_dist(0, 2)
    {
    }

    LinePosition read()
    {
        if (m_randomMode)
        {
            return static_cast<LinePosition>(m_dist(m_gen));
        }

        std::string line;
        std::cout << "Sensor input (l=left, c=center, r=right, u=unknown, q=quit): ";
        if (!std::getline(std::cin, line))
            return LinePosition::Unknown;

        if (line.empty())
            return LinePosition::Unknown;

        switch (line[0])
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
        case 'u':
        case 'U':
            return LinePosition::Unknown;
        case 'q':
        case 'Q':
            throw std::runtime_error("quit");
        default:
            return LinePosition::Unknown;
        }
    }

private:
    bool m_randomMode;
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<int> m_dist;
};

class MotorController
{
public:
    // In a real robot these methods would drive the motor driver / PWM outputs.
    void goStraight()
    {
        std::cout << "[Motor] Forward\n";
    }

    void turnLeft()
    {
        std::cout << "[Motor] Turn Left\n";
    }

    void turnRight()
    {
        std::cout << "[Motor] Turn Right\n";
    }

    void stop()
    {
        std::cout << "[Motor] Stop\n";
    }
};

int main()
{
    // Change to 'true' to use random sensor readings (automatic test).
    const bool randomSimulation = false;
    // Control loop period (ms).
    const std::chrono::milliseconds loopDelay(200);

    ColorSensor sensor(randomSimulation);
    MotorController motors;

    std::cout << "Line Following Robot - Simple Controller\n";
    std::cout << "Rules:\n";
    std::cout << "  1) If black line detected on LEFT  -> turn left\n";
    std::cout << "  2) If black line detected on RIGHT -> turn right\n";
    std::cout << "  3) If black line detected CENTER   -> go straight\n";
    std::cout << "Enter 'q' to quit.\n\n";

    try
    {
        while (true)
        {
            LinePosition pos = sensor.read();

            switch (pos)
            {
            case LinePosition::Left:
                motors.turnLeft();
                break;
            case LinePosition::Right:
                motors.turnRight();
                break;
            case LinePosition::Center:
                motors.goStraight();
                break;
            case LinePosition::Unknown:
            default:
                motors.stop();
                break;
            }

            std::this_thread::sleep_for(loopDelay);
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Exiting: " << e.what() << '\n';
    }

    return 0;
}
