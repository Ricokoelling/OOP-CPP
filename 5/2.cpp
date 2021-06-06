#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm> //Um transform zu importen
using namespace std;
void toString(vector<string *> const &Pointer, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *Pointer.at(i) << endl;
    }
}
void sort(vector<string *> &Pointer, int size) //Weil nicht genau gesagt wurde wie welche art von sortieralgorythmus verwendet werden soll habe ich eine abgewandelte Art des bubblesort verwendet die die Zeichenketten nach dem Alphabet ordnen (nach ASCII)
{
    bool sortiert = false;
    while (sortiert == false)
    {
        sortiert = true;
        for (int i = 0; i < size - 1; i++)
        {
            string *temp1 = Pointer[i];
            string *temp2 = Pointer[i + 1];
            if (temp1[0] > temp2[0])
            {
                string *temp3 = Pointer[i];
                Pointer[i] = Pointer[i + 1];
                Pointer[i + 1] = temp3;
            }
            else if (temp1[0] == temp2[0])
            {
                int k = 0;
                while (temp1[k] == temp2[k])
                {
                    k++;
                    if (temp1[k] > temp2[k])
                    {
                        string *temp3 = Pointer[i];
                        Pointer[i] = Pointer[i + 1];
                        Pointer[i + 1] = temp3;
                        break;
                    }
                }
            }
            sortiert = false;
        }
        size--;
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
        transform(input.begin(), input.end(), input.begin(), ::tolower); //wird benutzt um die Groß- und Kleinschreibung außer acht zu lassen. (Dies verändert zwar den String aber die Semantsiche Bedeutung wird nicht verändert)
        String.push_back(input);
        temp = &String[size];
        Pointer.push_back(new string(*temp));
        cout << "Please insert your word: ";
        getline(cin, input);
        size++;
    }
    sort(Pointer, size);
    toString(Pointer, size);
    return 0;
}