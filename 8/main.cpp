#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class Position
{
private:
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
    Position(const Position &p) : laengengrad(p.laengengrad), breitengrad(p.breitengrad), hoehe(p.hoehe){};
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
    void setLaengengrad(double longitude)
    {
        laengengrad = longitude;
    };
    void setBreitengrad(double latitude)
    {
        breitengrad = latitude;
    };
    void setHoehe(double height)
    {
        hoehe = height;
    };

    virtual void print()
    {
        cout << "Laengengrad = " << laengengrad << "; Breitengrad = " << breitengrad << "; Hoehe = " << hoehe << "m" << endl;
    };
};

class Wegpunkt : public Position
{
private:
    string Ort;

public:
    Wegpunkt()
    {
        Ort = "";
    };
    Wegpunkt(double _laengengrad, double _breitengrad, double _hoehe, string _ort) : Ort(_ort), Position(_laengengrad, _breitengrad, _hoehe){};
    Wegpunkt(const Wegpunkt &w) : Ort(w.Ort), Position(w){};
    string getOrt()
    {
        return Ort;
    };
    void setOrt(const string place)
    {
        Ort = place;
    };
    void print()
    {

        cout << "Laengengrad = " << getLaengengrad() << "; Breitengrad = " << getBreitengrad() << "; Hoehe = " << getHoehe() << "m" << "; Ort = " << Ort << endl;
    };
};

class Trackpunkt : public Position
{
private:
    int Zeitpunkt;

public:
    Trackpunkt()
    {
        Zeitpunkt = 0;
    };
    Trackpunkt(double _laengengrad, double _breitengrad, double _hoehe, int _zeitpunkt) : Zeitpunkt(_zeitpunkt), Position(_laengengrad, _breitengrad, _hoehe){};
    Trackpunkt(const Trackpunkt &t) : Position(t), Zeitpunkt(t.Zeitpunkt)
    {
        Position();
    };
    int getZeitpunkt()
    {
        return Zeitpunkt;
    };
    void setZeitpunkt(int time)
    {
        Zeitpunkt = time;
    };
    void print()
    {
        cout << "Laengengrad = " << getLaengengrad() << "; Breitengrad = " << getBreitengrad() << "; Hoehe = " << getHoehe() << "m" << "; Zeitpunkt = " << Zeitpunkt << endl;
    };
};
class Track
{
private:
    vector<Trackpunkt> track;

public:
    Track(){};
    Track(const Track &other) : track(other.track){};
    void print()
    {
        for (auto & i : track)
        {
            i.print();
        }
    };
    void add(const Trackpunkt *point)
    {
        track.push_back(*point);
    };
    void write(const string& filepath)
    {
        ofstream file;
        file.open(filepath);

        if (!file.is_open())
            return;

        for (auto point : track)
        {
            string line;

            ostringstream ss1, ss2, ss3;
            ss1.precision(7);
            ss2.precision(7);
            ss3.precision(2);

            ss1 << fixed << point.getLaengengrad();
            ss2 << fixed << point.getBreitengrad();
            ss3 << fixed << point.getHoehe();
            line += ss1.str();
            line += " ";
            line += ss2.str();
            line += " ";
            line += ss3.str();
            line += " ";
            line += to_string(point.getZeitpunkt());

            file << line << endl;
        }

        file.close();
    };
    void read(const string& filepath)
    {
        ifstream file;
        file.open(filepath);

        if (!file.is_open())
            return;

        try
        {
            while (file.good())
            {
                string temp;
                Trackpunkt point = Trackpunkt();

                file >> temp;
                point.setLaengengrad(stod(temp));

                file >> temp;
                point.setBreitengrad(stod(temp));

                file >> temp;
                point.setHoehe(stod(temp));

                file >> temp;
                point.setZeitpunkt(stoi(temp));
                add(&point);
            }

            file.close();
        }
        catch (const exception &e)
        {
            //ignore
            file.close();
        }
    };
    double getAverageHeight()
    {
        double sum = 0;

        for (auto & i : track)
        {
            sum += i.getHoehe();
        }

        return sum / track.size();
    };
};

int main(int argc, char *argv[])
{
    Position p1;
    Position p2(50.8851, 12.0807, 205);
    p1.print();
    p2.print();

    Wegpunkt w1;
    Wegpunkt w2(11.6034, 50.943, 155, "Jena");
    Wegpunkt w3(50.8851, 12.0807, 205, "Gera");
    w1.print();
    w2.print();
    w3.print();

    Trackpunkt t1;
    Trackpunkt t2(139.6922, 35.6897, 40, 363720);
    t1.print();
    t2.print();

    Track track;
    track.read("track.txt");
    track.write("tracker.txt");
    //tracks.print();           //um platz in der Konsole zu sparen habe ich das print davon auskommentiert
    cout << "Durschnittliche Hoehe: " << track.getAverageHeight() << endl;

    return 0;
}
