#include <Intervall_Arithmetik .h>

int main(){
    Intervall_Arithmetik<int> one(-1,1);
    Intervall_Arithmetik<int> two(2,2);
    Intervall_Arithmetik<int> three(5);
    Intervall_Arithmetik<int> four(2,5);
    Intervall_Arithmetik<int> five;

    //Test all
    cout<< "Test all" << endl;
    cout<< "operator+ : ";
    one.operator+(two).print();
    cout<< "operator- : ";
    one.operator-(two).print();
    cout<< "operator* : ";
    one.operator*(two).print();
    cout<< "operator/ : ";
    one.operator/(two).print();
    cout<< "operator- with four: ";
    four.operator-().print();
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
