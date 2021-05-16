#include <iostream>
#include <cmath>
using namespace std; //ich benutze namespacing um den code überscihtlicher zu gestalten
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
        cout << "Please check your input. \n"
             << "Every input has to be unequal to zero. " << endl;
        return 0;
    }
    cout << "The short version of " << +numerator << "/" << +denomirator << " is";
    if (abs(numerator) < abs(denomirator) && (denomirator < 0 || numerator < 0))
    {
        divider = ggt(numerator * -1, denomirator * -1);
    }
    else
        divider = ggt(numerator, denomirator);
    if (divider == 1)
    {
        cout << "the same, cant be shorten: " << +numerator << " / " << +denomirator << endl;
        return 1;
    }
    numerator /= divider;
    denomirator /= divider;

    cout << ": \n"
         << +numerator << " / " << +denomirator << endl;
    cout << "The biggest common divider is: " << +divider << endl;
    return 1;
}
int shorten(int numerator, int denomirator) //Das ist für Aufgabe 1.1 gedacht
{
    int smaller;
    if (denomirator < 0)
    {
        denomirator *= -1;
        numerator *= -1;
    }
    if (denomirator == 0 || numerator == 0)
    {
        cout << "Please check your input. \n"
             << "Every input has to be unequal to zero. " << endl;
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
            cout << "The short version of " << +numerator << "/" << +denomirator << " is: " << +numerator / i << " / " << +denomirator / i << endl;
            return 0;
        }
    }
    cout << "It's not possible to shorten " << +numerator << "/" << +denomirator << "." << endl;
}
int main()
{
    int numerator = 0, denomirator = 0;
    char input;
    do
    {
        cout << "Please insert numerator and denomirator:" << endl;
        cin >> numerator >> denomirator;
        //shorten(numerator, denomirator);
        int output = ggtshorten(numerator, denomirator);
        if (output != 0)
        {
            cout << "If you want to insert an other pair of numbers type 'Y'. If you want to end the Programm type 'N': "
                 << endl;
            cin >> input;
            input = toupper(input);
        }
        if (input == 'N')
        {
            break;
        }
    } while (input == 'Y');
    return 0;
}