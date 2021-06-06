#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
void toString(vector<string *> &Pointer, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *Pointer[i] << endl;
    }
}
void sort(vector<string *> &String, int size)
{
    bool sortiert = false;
    while (!sortiert)
    {
        sortiert = true;
        for (int i = 0; i < size; i++)
        {
            if (String[i] > String[i + 1])
            {
                string *temp = String[i];
                String[i] = String[i + 1];
                String[i + 1] = temp;

                sortiert = false;
            }
        }
    }
}
int main()
{

    vector<string *> Pointer;
    vector<string> String;
    string input, *temp;
    int size = 0;
    cout << "Please insert your word: ";
    getline(cin, input);
    while (input != ".")
    {
        String.push_back(input);
        temp = &String[size];
        Pointer.push_back(new string(*temp));
        cout << "Please insert your word: ";
        size++;
        getline(cin, input);
    }
    sort(Pointer, size);
    toString(Pointer, size);
    return 0;
}