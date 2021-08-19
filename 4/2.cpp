#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool test(const char &c)
{
    if (c >= '0' && c <= '9' || c == ' ')
    {
        return true;
    }
    return false;
}
int convert(const string &s)
{
    int result = 0, temp;
    bool check;
    for (int i = 0; i < s.size(); i++)
    {
        try
        {
            if (!test(s[0]) || (!test(s[i + 1]) && test(s[i + 2])) || (!test(s[i + 1]) && i + 1 < s.size()))
            {
                throw -1;
            }
            if (s[i] >= '0' && s[i] <= '9' || s[i] == ' ' && !(s[i] >= '0' && s[i] <= '9'))
            {
                if (s[i] != ' ')
                {
                    temp = s[i];
                    result += (temp - 48);
                    if (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9')
                        result *= 10;
                    else
                        return result;
                }
            }
            else
                return result;
        }
        catch (int error)
        {
            cerr << "Error!" << endl;
            return error;
        }
    }
    return result;
}
int main()
{
    string input;
    cout << "Please insert your text: " << endl;
    getline(cin, input);
    convert(input);

    return 0;
}