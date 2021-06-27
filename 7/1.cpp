#include <iostream>

using namespace std;
class Time
{
    // Daten
private:
    int minuten;
    // Methoden
public:
    Time()
    {
        minuten = 0;
        cout << "Standard-Konstruktor" << endl;
    };
    Time(int min)
    {
        minuten = min;
        cout << "Minuten-Konstruktor" << endl;
    };
    Time(int min, int h)
    {
        minuten = 60 * h + min;
        cout << "Minuten- und Stunden-Konstruktor" << endl;
    };
    Time(const Time &t)
    {
        minuten = t.minuten;
        cout << "Kopier-Konstruktor" << endl;
    };
    virtual ~Time()
    {
        cout << "Destruktor" << endl;
    }
    virtual void
    set(int h, int m)
    {
        minuten = 60 * h + m;
    };
    virtual void get(int &h, int &m) const
    {
        h = minuten / 60;
        m = minuten % 60;
    };
    virtual void inc()
    {
        minuten++;
    };
};

void print(Time t)
{
    int h, m;
    t.get(h, m);
    cout << h << ":" << m << endl;
}
Time input()
{
    Time result;
    int h, m;
    cout << "Uhrzeit eingeben - Stunde: ";
    cin >> h;
    cout << "Minute: ";
    cin >> m;
    result.set(h, m);
    return result;
}
int main(int argc, char *argv[])
{
    Time t1(10, 10);
    Time t2;
    t2 = input();
    t2.inc();
    print(t2);
    print(1234);
    return 0;
}