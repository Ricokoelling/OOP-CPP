#include <iostream>
#include <cstring>

using namespace std;
template <class Number>

class Intervall_Arithmetik {
private:
    Number left;
    Number right;
    bool isMarked;
    void setMarked(bool);

public:
    Intervall_Arithmetik();
    explicit Intervall_Arithmetik(Number range);
    Intervall_Arithmetik(Number _left, Number _right);
    virtual ~Intervall_Arithmetik() = default;;

    Number getLeft() const;
    Number getRight() const;
    bool isMarked1() const;
    void Set(Number _left, Number _right);
    virtual bool isValid() const;
    virtual void print();
    virtual Intervall_Arithmetik operator+(const Intervall_Arithmetik &i);
    virtual Intervall_Arithmetik operator-(const Intervall_Arithmetik &i);
    virtual Intervall_Arithmetik operator*(const Intervall_Arithmetik &i);
    virtual Intervall_Arithmetik operator/(const Intervall_Arithmetik &i);
    virtual Intervall_Arithmetik operator-();
};


