#include "include.cpp"
#include <iostream>
int main(){

    Intervall_Arithmetik<int> one(-2,1);
    Intervall_Arithmetik<int> two(4,3);
    Intervall_Arithmetik<double> three(6,10);           //ich hab de beiden als double genommen damit die Funktion funktioniert. Um die division durchzuführen muss 1 / y1 und 1 / y2 gerechnet werden, bei Integer-Values kommt dort immer 0 raus.
    Intervall_Arithmetik<double> four(5,2);
    Intervall_Arithmetik<int> five;

    //Test all
    cout<< "Test all" << endl;
    cout<< "operator+ : ";
    (one + two).print();
    cout<< "operator- : ";
    (one - two).print();
    cout<< "operator* : ";
    (one * two).print();
    cout<< "operator/ : ";
    (three / four).print();
    cout<< "operator- with four: ";
    (-four).print();
    cout << "all print : { " << endl;
    one.print();
    two.print();
    three.print();
    four.print();
    five.print();
    cout << "}";
    cout << endl;
    cout << endl;
    cout << endl;


    //Test specific
    cout << "Test specific" << endl;
    cout << "{" << endl;
    Intervall_Arithmetik<int> oneTest(0,0);
    Intervall_Arithmetik<int> twoTest;
    oneTest.operator+(twoTest).print();
    oneTest.operator-(twoTest).print();
    oneTest.operator*(twoTest).print();
    oneTest.operator/(twoTest).print();
    cout << "}" << endl;

    return 0;
}
