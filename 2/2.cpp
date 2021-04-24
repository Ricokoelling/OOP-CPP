#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    double a = 0, b = 0, c = 0;
    std::cout << "You got a quadratic formula from the form a * x^2 + b * x + c = 0. \n"
              << std::endl;
    std::cout << "Please enter a, b and c:"
              << std::endl;
    std::cin >> a >> b >> c;

    if (a != 1)
    {
        b /= a;
        c /= a;
    }
    double part1 = (b / 2) * -1;
    double part2 = pow((b / 2), 2) - c;

    if (part2 > 0)
    {
        std::cout << "The first solution is:" << part1 + sqrt(part2) << std::endl;
        std::cout << "the second solution is:" << part1 - sqrt(part2) << std::endl;
    }
    else if (part2 == 0)
    {
        std::cout << "The solution is:" << part1 << std::endl;
    }
    else
        std::cout << "The formula doesnt have a solution." << std::endl;

    return 0;
}