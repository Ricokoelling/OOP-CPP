#include <iostream>
#include <vector>

using namespace std;
class IntMenge
{
private:
    int maximum, minimum;
    vector<bool> menge = vector<bool>(maximum, false);

public:
    IntMenge(int min, int max)
    {
        minimum = min;
        maximum = max;
    };
    bool isValid(int i)
    {
        if (i <= maximum && i >= minimum)
        {
            return true;
        }
        return false;
    };
    void add(int i)
    {
        if (menge[i] == false)
        {
            menge[i] = true;
        }
    };
    void remove(int i)
    {
        if (menge[i] == true)
        {
            menge[i] = false;
        }
    };
    bool contains(int i)
    {
        return menge[i];
    };
    bool isEmpty()
    {
        for (int i = minimum; i < maximum; i++)
        {
            if (menge[i] != false)
            {
                return false;
            }
        }
        return true;
    };
    int getSize()
    {
        int length = 0;
        for (int i = minimum; i < maximum; i++)
        {
            if (menge[i] == true)
            {
                length++;
            }
        }
        return length;
    };
    vector<int> getElements()
    {
        vector<int> elements;
        for (int i = minimum; i < maximum; i++)
        {
            if (menge[i] == true)
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
        for (int i = minimum; i < maximum; i++)
        {
            if (menge[i] == true)
            {
                if (temp == true)
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
    for (int i = 0; i < intv.size(); i++)
        m.remove(intv[i]);
    cout << (m.isEmpty() ? "Menge ist leer" : "Menge ist nicht leer")
         << endl;
}
