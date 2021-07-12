#include <Intervall_Arithmetik .h>
#include "iostream"
template<class Number>
Intervall_Arithmetik<Number>::Intervall_Arithmetik(): isMarked(true){}
template<class Number>
Intervall_Arithmetik<Number>::Intervall_Arithmetik(Number range): left(0), right(range)
{
    isMarked = false;
    if(range < 0){
        right = 0;
    }
}
template<class Number>
Intervall_Arithmetik<Number>::Intervall_Arithmetik(Number _left, Number _right): left(_left), right(_right)
{
    isMarked = false;
    if(_left > _right){
        right = _left;
        left = _right;
    }
}
template<class Number>
Number Intervall_Arithmetik<Number>::getLeft() const {
    if(isValid()){
        return left;
    }
}
template<class Number>
Number Intervall_Arithmetik<Number>::getRight() const {
    if(isValid()){
        return right;
    }
}
template<class Number>
bool Intervall_Arithmetik<Number>::isMarked1() const {
    return isMarked;
}
template<class Number>
void Intervall_Arithmetik<Number>::Set(Number _left, Number _right) {
    if(_left < _right) {
        left = _left;
        right = _right;
        isMarked = false;
    }
    else{
        left = _right;
        right = _left;
        isMarked = false;
    }

}
template<class Number>
bool Intervall_Arithmetik<Number>::isValid() const{
    if(left < right && !isMarked)
        return true;
    return false;
}
template<class Number>
void Intervall_Arithmetik<Number>::print(){
    if(isValid()) {
        cout << "[" << left << ", " << right << "]" << endl;
    }
    else
        cout<< "Invalid interval" << endl;
}
template<class Number>
Intervall_Arithmetik<Number> Intervall_Arithmetik<Number>::operator+(const Intervall_Arithmetik &i) {
    if(isValid() && i.isValid()) {
        return Intervall_Arithmetik(left + i.left, right + i.right);
    }
    return Intervall_Arithmetik();
}
template<class Number>
Intervall_Arithmetik<Number> Intervall_Arithmetik<Number>::operator-(const Intervall_Arithmetik &i) {
    if(isValid() && i.isValid()) {
        return Intervall_Arithmetik(left - i.right, right - i.left);
    }
    return Intervall_Arithmetik();
}

template<class Number>
Intervall_Arithmetik<Number> Intervall_Arithmetik<Number>::operator*(const Intervall_Arithmetik &i){
    Intervall_Arithmetik<Number> newInt;
    newInt.setMarked(false);
    if(isValid() && i.isValid()){
        Number temp1 = left * i.left;
        Number temp2 = left * i.right;
        Number temp3 = right * i.right;
        Number temp4 = right * i.left;
        Number lft,rgt;

        if(temp1 < temp2)
        {
            lft = temp1;
        } else
        {
            lft = temp2;
        }
        if(temp3 > temp4){
            rgt = temp3;
        }
        else
        {
            rgt = temp4;
        }
        newInt.Set(lft,rgt);
        return newInt;
    }
    return Intervall_Arithmetik();
}

template<class Number>
Intervall_Arithmetik<Number> Intervall_Arithmetik<Number>::operator/(const Intervall_Arithmetik &i) {
    Intervall_Arithmetik<Number> temp;
    temp.setMarked(false);
    if(isValid() && i.isValid()) {
        if(i.right != 0 && i.left != 0){
            temp.Set(1/ i.left, 1 / i.right);
            return this->operator*(temp);
        }
    }
    return Intervall_Arithmetik();
}
template<class Number>
Intervall_Arithmetik<Number> Intervall_Arithmetik<Number>::operator-(){
    if(isValid()) {
        if (left * -1 > right * -1) {
            return Intervall_Arithmetik(-right, -left);
        }
        return Intervall_Arithmetik(-left,-right);
    }
    return Intervall_Arithmetik<Number>();
}
template<class Number>
void Intervall_Arithmetik<Number>::setMarked(bool marker) {
    isMarked = marker;
}


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
