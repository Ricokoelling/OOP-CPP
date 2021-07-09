#include "iostream"
#include <cstring>

using namespace std;
template <class T>

class Intervall_Arithmetik{
private:
    int left{};
    int right{};
    bool isMarked;


public:
    Intervall_Arithmetik() {
        isMarked = true;
    };

    explicit Intervall_Arithmetik(int range): left(0), right(range)
    {
        isMarked = false;
        if(range < 0){
            right = 0;
        }
    }

    Intervall_Arithmetik(int _left, int _right): left(_left), right(_right)
    {
        isMarked = false;
        if(_left > _right){
            right = _left;
            left = _right;
        }
    };

    virtual ~Intervall_Arithmetik() = default;;

    int getLeft() const {
        if(!isMarked){
            return left;
        }
    };
    int getRight() const {
        if(!isMarked){
            return right;
        }
    };

    bool isMarked1() const {
        return isMarked;
    }

    void setLeft(int _left) {
        if(!isMarked) {
            if (_left > right) {
                Intervall_Arithmetik::right = _left;
            } else
                Intervall_Arithmetik::left = _left;
        }
    };
    void setRight(int _right) {
        if(!isMarked) {
            if (_right < left) {
                Intervall_Arithmetik::left = _right;
            } else
                Intervall_Arithmetik::right = _right;
        }
    };
    virtual void print(){
        if(!isMarked) {
            cout << "[" << left << ", " << right << "]" << endl;
        }
        else
            cout<< "Invalid interval" << endl;
    };
    virtual Intervall_Arithmetik operator+(const Intervall_Arithmetik &i){
        if(!isMarked && !i.isMarked) {
            return Intervall_Arithmetik(left + i.left, right + i.right);
        }
        return Intervall_Arithmetik();
    };

    virtual Intervall_Arithmetik operator-(const Intervall_Arithmetik &i){
        if(!isMarked && !i.isMarked) {
            return Intervall_Arithmetik(left - i.left, right - i.right);
        }
        return Intervall_Arithmetik();
    };

    virtual Intervall_Arithmetik operator*(const Intervall_Arithmetik &i){
        if(!isMarked && !i.isMarked){
            return Intervall_Arithmetik(left * i.left, right * i.right);
        }
        return Intervall_Arithmetik();
    };

    virtual Intervall_Arithmetik operator/(const Intervall_Arithmetik &i) {
        if(!isMarked && !i.isMarked) {
            if(i.right != 0 && i.left != 0)
                return Intervall_Arithmetik(left / i.left, right / i.right);
            }
        return Intervall_Arithmetik();
    };

    virtual Intervall_Arithmetik operator-(){
        if(!isMarked) {
            if (left * -1 > right * -1) {
                swap(left, right);
            }
            return Intervall_Arithmetik(left * -1, right * -1);
        }
    };
};

