#include <iostream>
#include <stdio.h>
#include <math.h>

int testSolution(double partOne, double partTwo)
{
    if (partTwo > 0)
    {
        std::cout << "The first solution is:" << partOne + sqrt(partTwo) << std::endl;
        std::cout << "The second solution is:" << partOne - sqrt(partTwo) << std::endl;
    }
    else if (partTwo == 0)
    {
        std::cout << "The only solution is: " << partOne << std::endl;
    }
    else
        std::cout << "Your formula doesn't have a real solution." << std::endl;
    return 0;
}
int calculation(double p, double q)
{
    double partOne = (p / 2) * -1;
    double partTwo = pow((p / 2), 2) - q; //anstatt pow könnte man auch (p / 2)*(p / 2) schreiben.

    return testSolution(partOne, partTwo);
}

int test(double a, double b, double c)
{

    if (a != 1)
    {
        b /= a;
        c /= a;
    }
    return calculation(b, c);
}
int main()
{
    double a = 0, b = 0, c = 0;
    std::cout << "You got a quadratic formula from the form a * x^2 + b * x + c = 0. \n"
              << std::endl;
    std::cout << "Please enter a, b and c:"
              << std::endl;
    std::cin >> a >> b >> c;
    test(a, b, c);

    return 0;
}