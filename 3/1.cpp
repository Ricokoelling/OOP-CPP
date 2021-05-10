#include <iostream>
#include <cmath>
int ggt(int numerator, int denomirator)
{
    if (denomirator == 0)
    {
        return numerator;
    }
    else
        ggt(denomirator, numerator % denomirator);
}
int ggtshorten(int numerator, int denomirator)
{
    int divider;
    if (denomirator == 0 || numerator == 0)
    {
        std::cout << "Please check your input. \n"
                  << "Every input has to be unequal to zero. " << std::endl;
        return 0;
    }
    std::cout << "The short version of " << +numerator << "/" << +denomirator << " is";
    if (abs(numerator) < abs(denomirator) && (denomirator < 0 || numerator < 0))
    {
        divider = ggt(numerator * -1, denomirator * -1);
    }
    else
        divider = ggt(numerator, denomirator);
    if (divider == 1)
    {
        std::cout << "the same: " << +numerator << " / " << +denomirator << std::endl;
        return 1;
    }
    numerator /= divider;
    denomirator /= divider;

    std::cout << ": \n"
              << +numerator << " / " << +denomirator << std::endl;
    std::cout << "The biggest common divider is: " << +divider << std::endl;
    return 1;
}
int shorten(int numerator, int denomirator)
{
    int smaller;
    if (denomirator < 0)
    {
        denomirator *= -1;
        numerator *= -1;
    }
    if (denomirator == 0 || numerator == 0)
    {
        std::cout << "Please check your input. \n"
                  << "Every input has to be unequal to zero. " << std::endl;
        return 0;
    }
    if (numerator < denomirator)
    {
        smaller = numerator;
    }
    else
    {
        smaller = denomirator;
    }
    for (int i = smaller; i >= 2; i--)
    {
        if (numerator % i == 0 && denomirator % i == 0)
        {
            std::cout << "The short version of " << +numerator << "/" << +denomirator << " is: " << +numerator / i << " / " << +denomirator / i << std::endl;
            return 0;
        }
    }
    std::cout << "It's not possible to shorten " << +numerator << "/" << +denomirator << "." << std::endl;
}
int main()
{
    int numerator = 0, denomirator = 0;
    char input;
    do
    {
        std::cout << "Please insert numerator and denomirator:" << std::endl;
        std::cin >> numerator >> denomirator;
        //shorten(numerator, denomirator);
        int output = ggtshorten(numerator, denomirator);
        if (output != 0)
        {
            std::cout << "If you want to insert an other pair of numbers type 'Y'. If you want to end the Programm type 'N': "
                      << std::endl;
            std::cin >> input;
            input = toupper(input);
        }
        if (input == 'N')
        {
            break;
        }
    } while (input == 'Y');
    return 0;
}