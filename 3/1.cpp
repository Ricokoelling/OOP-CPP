#include <iostream>
int ggt(int numerator, int denomirator)
{
    if (denomirator == 0)
    {
        return numerator;
    }
    else
        ggt(denomirator, numerator % denomirator);
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
    char input = 'Y';
    while (input == 'Y')
    {
        std::cout << "Please insert numerator and denomirtor:" << std::endl;
        std::cin >> numerator >> denomirator;
        shorten(numerator, denomirator);
        //std::cout << ggt(numerator, denomirator) << std::endl;
        std::cout << "If you want to insert an other pair of numbers type 'Y'. If you want to end the Programm type 'N': "
                  << std::endl;
        std::cin >> input;
        input = toupper(input);
    }
    return 0;
}