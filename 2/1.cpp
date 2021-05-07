#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

int main()
{
    int max = 0, correctNumber = 0, userNumber = -1, counter = 1;
    std::cout << "Please enter a valid maximum: "
              << std::endl;
    std::cin >> max;
    srand((unsigned int)time(NULL)); //Wird benutzt um die Zahl wirklich zufällig zu würfeln
    correctNumber = rand() % (max + 1);
    std::cout << "Now enter the number that you think is the wanted one:" << std::endl;
    std::cin >> userNumber;
    while (correctNumber != userNumber)
    {
        if (userNumber < correctNumber)
        {
            std::cout << "Your number " << userNumber << " is smaller than the wanted one. \n\r" << std::endl;
            std::cout << "Please enter a bigger number:" << std::endl;
            std::cin >> userNumber;
        }
        else if (userNumber > correctNumber)
        {
            std::cout << "Your number " << userNumber << " is bigger than the wanted one. \n\r" << std::endl;
            std::cout << "Please enter a smaller number:" << std::endl;
            std::cin >> userNumber;
        }
        counter++;
    }
    std::cout << "Great, you found the number: " << correctNumber << "!\n \r"
              << "You needed " << counter << " tries. Good Job!" << std::endl;

    return 0;
}