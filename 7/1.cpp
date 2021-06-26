#include <iostream>

using namespace std;
class Time
{
    // Daten
private:
    int minuten, stunden = 0;
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
        minuten = min;
        stunden = h;
        cout << "Minuten- und Stunden-Konstruktor" << endl;
    };
    Time(const Time &t)
    {
        minuten = t.minuten;
        stunden = t.stunden;
        cout << "Kopier-Konstruktor" << endl;
    };
    virtual ~Time() {}
    virtual void set(int h, int m)
    {
        minuten = m;
        stunden = h;
    };
    virtual void get(int &h, int &m) const
    {
        h = stunden;
        m = minuten;
        cout << h << " " << m << endl;
    };
    virtual void inc()
    {
        minuten++;
        stunden++;
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