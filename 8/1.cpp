#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Position
{
protected:
    double laengengrad;
    double breitengrad;
    double hoehe;

public:
    Position()
    {
        laengengrad = 0;
        breitengrad = 0;
        hoehe = 0;
    };
    Position(double _laengengrad, double _breitengrad, double _hoehe) : laengengrad(_laengengrad), breitengrad(_breitengrad), hoehe(_hoehe){};
    Position(const Position &p)
    {
        laengengrad = p.laengengrad;
        breitengrad = p.breitengrad;
        hoehe = p.hoehe;
    };
    double getLaengengrad()
    {
        return laengengrad;
    };
    double getBreitengrad()
    {
        return breitengrad;
    };
    double getHoehe()
    {
        return hoehe;
    };
    string print()
    {
        cout << "Laengengrad = " << laengengrad << "; Breitengrad = " << breitengrad << "; Hoehe = " << hoehe;
    }
};

class Wegpunkt : public Position
{
private:
    string Ort;

public:
    Wegpunkt()
    {
        Position();
        Ort = " ";
    };
    Wegpunkt(double _laengengrad, double _breitengrad, double _hoehe)
    {
        Position(_laengengrad, _breitengrad, _hoehe);
        Ort = " ";
    };
    Wegpunkt(double _laengengrad, double _breitengrad, double _hoehe, string _Ort) : Ort(_Ort)
    {
        Position(_laengengrad, _breitengrad, _hoehe);
    };
    Wegpunkt(string _Ort) : Ort(_Ort)
    {
        Position();
    };
    Wegpunkt(const Wegpunkt &w)
    {
        Ort = w.Ort;
    };
    string print()
    {

        cout << "Laengengrad = " << laengengrad << "; Breitengrad = " << breitengrad << "; Hoehe = " << hoehe << "Ort = " << Ort;
    }
};

class Trackpunkt : public Position
{
private:
    int Zeitpunkt;

public:
    Trackpunkt()
    {
        Position();
        Zeitpunkt = 0;
    };
    Trackpunkt(double _laengengrad, double _breitengrad, double _hoehe)
    {
        Position(_laengengrad, _breitengrad, _hoehe);
        Zeitpunkt = 0;
    };
    Trackpunkt(double _laengengrad, double _breitengrad, double _hoehe, int _Zeitpunkt) : Zeitpunkt(_Zeitpunkt)
    {
        Position(_laengengrad, _breitengrad, _hoehe);
    };
    Trackpunkt(int _Zeitpunkt) : Zeitpunkt(_Zeitpunkt)
    {
        Position();
    };
    Trackpunkt(const Trackpunkt &t)
    {
        Zeitpunkt = t.Zeitpunkt;
    };
    int getZeitpunkt()
    {
        return Zeitpunkt;
    };
    string print()
    {

        cout << "Laengengrad = " << laengengrad << "; Breitengrad = " << breitengrad << "; Hoehe = " << hoehe << "Zeitpunkt = " << Zeitpunkt;
    }
};
class Tracks : public Trackpunkt
{
private:
    Trackpunkt t;
    vector<Trackpunkt> anhang;

public:
    Tracks()
    {
        Trackpunkt(t);
        anhang.push_back(t);
    };
    Tracks(const Tracks &tr)
    {
        Trackpunkt(tr);
    };
    string print()
    {
        t.print();
    };
    double mittlereHoehe()
    {
        double mithigth = 0;
        for (int i = 0; i < anhang.size(); i++)
        {
            mithigth += anhang[i].getHoehe();
        }
        return mithigth;
    };
    void Write(string writeable)
    {
        string tracker = writeable, str;
        ofstream os;
        for (int i = 0; i < anhang.size(); i++)
        {
            if (os.good())
                os << anhang[i].getLaengengrad() << anhang[i].getBreitengrad() << anhang[i].getHoehe() << anhang[i].getZeitpunkt() << std::endl;
        }
    }
    void read(string readable)
    {
        string input, temp;
        ifstream is;
        is.open(readable);
        is >> input;
        for (int i = 0; i < input.length(); i++)
        {
            int temp2 = 0;
            while (input[i] != ' ')
            {
                temp.push_back(input[i]);
            }
            if (temp2 == 0)
            {
                temp2++;
                laengengrad = stod(temp);
                temp = "";
            }
            if (temp2 == 1)
            {
                temp2++;
                breitengrad = stod(temp);
                temp = "";
            }
            if (temp2 == 2)
            {
                temp2++;
                hoehe = stod(temp);
                temp = "";
            }
        }
    }
};

int main()
{
    Position p1();
    Position p2(1, 2, 3);
    Wegpunkt w1();
    Wegpunkt w2(1, 2, 3);
    Wegpunkt w3(1, 2, 3, "Klaus");
    Wegpunkt w4("peter");
    Trackpunkt t1();
    Trackpunkt t2(1, 2, 3);
    Trackpunkt t3(1, 2, 3, 5);
    Trackpunkt t4(0);
    Tracks(t1);
    Tracks(t2);
    Tracks(t3);
    Tracks(t4);

    return 0;
}