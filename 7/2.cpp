#include <iostream>
#include <vector>

using namespace std;
class IntMenge
{
private:
    int maximum, minimum;
    vector<bool> menge;

public:
    IntMenge(int min, int max)
    {
        menge = vector<bool>(maximum, false);
        minimum = min;
        maximum = max;
    };
    bool isValid(int i) const
    {
        if (i <= maximum && i >= minimum)
        {
            return true;
        }
        return false;
    };
    void add(int i)
    {
        if(isValid(i)) {
            if (!menge[i]) {
                menge[i] = true;
            }
        }
    };
    void remove(int i)
    {
        if(isValid(i)) {
            if (menge[i]) {
                menge[i] = false;
            }
        }
    };
    bool contains(int i)
    {
        if(isValid(i)) {
            return menge[i];
        }
        return false;
    };
    bool isEmpty()
    {
        for (int i = minimum; i <= maximum; i++)
        {
            if (menge[i])
            {
                return false;
            }
        }
        return true;
    };
    int getSize()
    {
        int length = 0;
        for (int i = minimum; i <= maximum; i++)
        {
            if (menge[i])
            {
                length++;
            }
        }
        return length;
    };
    vector<int> getElements()
    {
        vector<int> elements;
        for (int i = minimum; i <= maximum; i++)
        {
            if (menge[i])
            {
                elements.push_back(i);
            }
        }
        return elements;
    };
    void print()
    {
        bool temp = false;
        cout << "Elements= "
             << "{";
        for (int i = minimum; i <= maximum; i++)
        {
            if (menge[i])
            {
                if (temp)
                {
                    cout << ", ";
                }
                cout << i;
                temp = true;
            }
        }
        cout << "}";
    };
};

int main()
{
    IntMenge m(10, 100);
    int input;
    cout << "input: ";
    cin >> input;
    while (input != 0)
    {
        if (m.isValid(input))
        {
            m.add(input);
        }
        cout << "Menge enthaelt " << m.getSize()
             << " Elemente:" << endl;
        m.print();
        cin >> input;
    }
    vector<int> intv = m.getElements();
    for (int i : intv)
        m.remove(i);
    cout << (m.isEmpty() ? "Menge ist leer" : "Menge ist nicht leer")
         << endl;
}
