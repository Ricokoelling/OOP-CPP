#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int fehler()
{
    cout << "Something went wrong, try again or check your input, please!" << endl;
}
int guess(int maximum, int minimum)
{
    srand(time(NULL));
    int counter = 0, next = rand() % 3 + 4; //für die erste Frage wird random eine Nummer ausgesucht, damit die fragen sich nicht all zu oft wiederholen
    while (1)
    {
        int difference = maximum - minimum;
        next -= 3;
        if (maximum < minimum)
        {
            return fehler();
        }
        if (maximum - minimum <= 1)
        {
            cout << "Is your number " << +maximum << " ?" << endl;
            string input;
            getline(cin, input);
            bool correct = input == "yes";
            if (correct == true)
            {
                cout << "Your number is: " << +maximum << " ! \n"
                     << "I only needed: " << +counter << " trys! \n"
                     << "That was fun lets do it again!" << endl;
                return 0;
            }
            else
            {
                counter++;
                cout << "Is your number " << +minimum << " ?" << endl;
                string input;
                getline(cin, input);
                bool correct = input == "yes";
                if (correct == true)
                {
                    cout << "Your number is: " << +minimum << " ! \n"
                         << "I only needed: " << +counter << " trys! \n"
                         << "That was fun lets do it again!" << endl;
                    return 0;
                }
                else
                    return fehler();
            }
        }
        if (next == 1)
        {
            cout << "Is your number bigger then: " << +maximum - (difference / 2) << " ?" << endl;
            string input;
            getline(cin, input);
            bool correct = input == "yes";
            if (correct == true)
            {
                minimum = maximum - (difference / 2) + 1;
                next = 6;
            }
            else
            {
                maximum = maximum - (difference / 2);
                next = 5;
            }
        }
        if (next == 2)
        {
            cout << "Is your number smaller then: " << +maximum - (difference / 2) << " ?" << endl;
            string input;
            getline(cin, input);
            bool correct = input == "yes";
            if (correct == true)
            {
                maximum = maximum - (difference / 2) - 1;
                next = 4;
            }
            else
            {
                minimum = maximum - (difference / 2);
                next = 6;
            }
        }
        if (next == 3)
        {
            cout << "Is your number between: " << +minimum << " and " << +maximum - (difference / 2) << " ?" << endl;
            string input;
            getline(cin, input);
            bool correct = input == "yes";
            if (correct == true)
            {
                maximum = maximum - (difference / 2);
                next = 5;
            }
            else
            {
                minimum = maximum - (difference / 2) + 1;
                next = 3;
            }
        }
        counter++;
    }
}
bool test(int maximum, int minimum)
{
    if (maximum > minimum)
        return true;
    return false;
}
int main()
{
    int minimum = 0, maximum = 0;
    cout << "This Programm trys to guess your Number. If the statement is correct type 'yes', otherwise type 'no' \n"
         << "Please, insert a valid minimum and maximum: " << endl;
    cin >> minimum >> maximum;
    cin.clear();
    cin.ignore(123, '\n');
    if (test(maximum, minimum) == true)
    {
        guess(maximum, minimum);
    }
    else
        fehler();
    return 0;
}