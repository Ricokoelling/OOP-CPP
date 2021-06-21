#include <iostream>
#include <string.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
bool isEmpty(vector<vector<char>> field)
{
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field.size(); j++)
        {
            if (field[j][i] != 0)
                return false;
        }
    }

    return true;
}
bool valid(const string input)
{
    if (input.length() != 2)
        return false;

    if (input[0] < 97 || input[0] > 97 + 9 - 1)
        return false;

    if (input[1] < 49 || input[1] > 49 + 9 - 1)
        return false;

    return true;
}
bool validmove(const vector<vector<char>> field, const int x, const int y)
{

    char stone = field[x][y];
    if (stone == 0)
    {
        return false;
    }
    if (x != field.size() - 1)
        if (field[x + 1][y] == stone)
        {
            return true;
        }
    if (x != 0)
        if (field[x - 1][y] == stone)
        {
            return true;
        }
    if (y != field.size() - 1)
        if (field[x][y + 1] == stone)
        {
            return true;
        }
    if (y != 0)
        if (field[x][y - 1] == stone)
        {
            return true;
        }
    return false;
}
void Input(int *x, int *y)
{
    string insert;
    do
    {
        cout << "Please insert your move: ";
        getline(cin, insert);
    } while (!valid);
    *x = insert.at(0) - 97;
    *y = insert.at(1) - 49;
}
bool moremoves(vector<vector<char>> field)
{
    for (int i = 0; i < field.size() - 1; i++)
    {
        vector<char> x = field[i];
        for (int j = 0; j < x.size() - 1; j++)
        {
            char color = x[j];
            if (color == 0)
                continue;

            if (x[j + 1] == color || field[i + 1][j] == color)
                return false;
        }
    }

    return true;
}
void removeStones(vector<vector<char>> *field, vector<int> check)
{
    for (int i = 0; i < check.size(); i++)
    {
        field->at(check.at(i) / 10)[check.at(i) % 10] = 0;
    }
}
void newColumm(vector<vector<char>> *field)
{
    bool anyGaps;
    int size = field->at(0).size();
    do
    {
        size--;
        anyGaps = false;
        for (int i = 0; i < field->at(0).size() - 1; i++)
        {
            bool gap = true;
            for (int j = 0; j < field->size(); j++)
            {
                if (field->at(j)[i] != 0)
                    gap = false;
            }

            if (gap)
            {
                anyGaps = true;
                for (int j = 0; j < field->size(); j++)
                {
                    field->at(j)[i] = field->at(j)[i + 1];
                    field->at(j)[i + 1] = 0;
                }
            }
        }
    } while (anyGaps && size > 0);
}
void newstones(vector<vector<char>> *field)
{
    for (int i = 0; i < field->at(0).size(); i++)
    {
        bool done;
        do
        {
            done = true;
            for (int j = 1; j < field->size(); j++)
            {
                if (field->at(j)[i] == 0 && field->at(j - 1)[i] != 0)
                {
                    done = false;
                    field->at(j)[i] = field->at(j - 1)[i];
                    field->at(j - 1)[i] = 0;
                }
            }
        } while (!done);
    }
}
void getStones(vector<vector<char>> *field, int x, int y, vector<int> *check)
{
    bool exists = false;
    for (int i = 0; i < check->size(); i++)
    {
        if (check->at(i) / 10 == x && check->at(i) % 10 == y)
            exists = true;
    }
    if (exists)
        return;

    check->push_back(x * 10 + y); //bereits bereiste Steine werden in das array aufgenommen
    char stone = field->at(x)[y];
    if (x != field->size() - 1)
        if (field->at(x + 1)[y] == stone)
        {
            getStones(field, x + 1, y, check);
        }
    if (x != 0)
        if (field->at(x - 1)[y] == stone)
        {
            getStones(field, x - 1, y, check);
        }
    if (y != field->size() - 1)
        if (field->at(x)[y + 1] == stone)
        {
            getStones(field, x, y + 1, check);
        }
    if (y != 0)
        if (field->at(x)[y - 1] == stone)
        {
            getStones(field, x, y - 1, check);
        }
}
int makemove(vector<vector<char>> *field, int x, int y)
{
    vector<int> check; //Vector der die bereits Richtigen steine hat, *
    getStones(field, x, y, &check);
    removeStones(field, check);
    newstones(field);
    newColumm(field);

    return check.size() * (check.size() - 1); //so kann auch die Punktzahl berechnet werden
}
void print(const vector<vector<char>> field)
{
    char outchar = 219; //Weil der char ähnlichkeiten mit einer Box hat habe ich diesen für die Ausgabe genommen
    string outgoes;
    string reset = "\033[0m";
    for (int i = 0; i < field.size(); i++)
    {
        char line = 'a' + i;
        cout << line << "   ";
        for (int j = 0; j < field.size(); j++)
        {
            switch (field[i][j])
            {
            case 'R':
                outgoes = "\033[0;31m";
                break;
            case 'G':
                outgoes = "\033[0;32m";
                break;
            case 'Y':
                outgoes = "\033[0;33m";
                break;
            case 'B':
                outgoes = "\033[0;34m";
                break;
            case 'P':
                outgoes = "\033[0;35m";
                break;
            case 0:
                outgoes = "\033[0;30m";
                break;
            default:
                exit;
                break;
            }
            cout << outgoes << outchar << outchar << outchar << reset;
        }
        cout << " \n";
    }
    cout << "   ";
    for (int i = 0; i < 9; i++)
    {
        cout << "  " << i + 1;
    }
    cout << "\n";
}
void buildfield(vector<vector<char>> *field)
{
    srand(time(nullptr)); //Damit das Feld wirklich random ist, wird die es an der Zeit festgemacht welche Zahlen genommen werden (time(nullptr))
    for (int i = 0; i < field->size(); i++)
    {
        vector<char> x = field->at(i);
        for (int j = 0; j < field->size(); j++)
        {
            int temp1 = rand() % 5 + 1;
            switch (temp1) //R -> red ; G -> greeen ; Y -> yellow ; B -> blue; P -> purple
            {
            case 1:
                x[j] = 'R';
                break;
            case 2:
                x[j] = 'G';
                break;
            case 3:
                x[j] = 'Y';
                break;
            case 4:
                x[j] = 'B';
                break;
            case 5:
                x[j] = 'P';
                break;
            default:
                exit;
                break;
            }
        }
        field->at(i) = x;
    }
}
void loop(vector<vector<char>> *field)
{
    string input;
    int points = 0;
    int x = 0;
    int y = 0;
    cout << "Score: " << points << endl;
    while (true)
    {
        Input(&x, &y);
        if (!validmove(*field, x, y)) //Validmove ist nur true wenn in einer Richtung ein andere Stein mit der selben Farbe liegt
        {
            cout << "No valid move" << endl;
            continue;
        }
        points += makemove(field, x, y);
        print(*field);
        cout << "Score: " << points << endl;
        if (isEmpty(*field)) //Es würde eigentlich reichen zu testen ob moremoves = false aber so gibt es eine Mögichkeit den totalen Sieg zu bekommen
        {
            cout << "Yuhuuu you won nothing!"
                 << "\n"
                 << "Your total points: "
                 << "\033[0;31m" << points << "! "
                 << "\033[0m" << endl;
            break;
        }
        if (moremoves(*field))
        {
            cout << "No more moves possible."
                 << "You won!"
                 << "Your total points: "
                 << "\033[0;31m" << points << "! "
                 << "\033[0m" << endl;
            break;
        }
    }
}
int main()
{
    vector<vector<char>> field(9, vector<char>(9));
    buildfield(&field);
    print(field);
    loop(&field);
    return 0;
}