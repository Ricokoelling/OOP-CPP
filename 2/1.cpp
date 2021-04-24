#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

int main()
{
    int max = 0, zahl = 0, userzahl = -1;
    std::cout << "Please enter a valid maximum: "
              << std::endl;
    std::cin >> max;
    srand((unsigned int)time(NULL)); //Wird benutzt um die Zahl wirklich zufällig zu würfeln
    zahl = rand() % (max + 1);
    std::cout << "Now enter the number that you think is the wanted one:" << std::endl;
    std::cin >> userzahl;
    while (zahl != userzahl)
    {
        if (userzahl < zahl)
        {
            std::cout << "Your number " << userzahl << " is smaller than the wanted one. \n\r" << std::endl;
            std::cout << "Please enter a bigger number:" << std::endl;
            std::cin >> userzahl;
        }
        else if (userzahl > zahl)
        {
            std::cout << "Your number " << userzahl << " is bigger than the wanted one. \n\r" << std::endl;
            std::cout << "Please enter a smaller number:" << std::endl;
            std::cin >> userzahl;
        }
    }
    std::cout << "Great, you found the number:" << zahl << "!" << std::endl;

    return 0;
}