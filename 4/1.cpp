#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double max(const vector<double> &v)
{
    double maximum = INT32_MIN; //Das maximum wird auf den kleinsten integer Wert gesetzt
    for (double d : v)
    {
        if (maximum < d)
        {
            maximum = d;
        }
    }
    return maximum;
}
bool allPositive(const vector<double> &v)
{
    bool temp;
    for (double d : v)
    {
        if (d > 0)
        {
            temp = true;
        }
        else
        {
            return false;
        }
    }
    return temp;
}
double product(const vector<double> &v1, const vector<double> &v2)
{
    double solution = 0;
    for (int i = 0; i < v1.size() && v2.size(); i++)
    {
        solution += v1[i] * v1[i];
    }
    return solution;
}
vector<double> product(const vector<double> &v, double f)
{
    vector<double> solution;
    for (int i = 0; i < v.size(); i++)
    {
        solution.push_back(v[i] * f);
    }
    return solution;
}
double norm(const vector<double> &v)
{
    int part = 0;
    for (int i = 0; i < v.size(); i++)
    {
        part += (v[i] * v[i]);
    }
    return sqrt(part);
}
void normalize(vector<double> &v)
{
    double temp = norm(v);
    for (double &d : v)
    {
        d = d / temp;
    }
}

int main()
{
    int choice;
    vector<double> array1, array2, result;
    int input, counter = 0;
    double temp;
    cout << "Please insert what function you need: " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Please insert how many numbers your vector has: ";
        cin >> input;
        cin.ignore();
        cout << "Please insert your numbers for the vector: ";
        for (int i = 0; i < input; i++)
        {
            cin >> temp;
            array1.push_back(temp);
        }
        cout << "The biggest number in the vector is: " << max(array1) << endl;
        break;

    case 2:
        cout << "Please insert how many numbers your vector has: ";
        cin >> input;
        cout << "Please insert your numbers for the vector: ";
        for (int i = 0; i < input; i++)
        {
            cin >> temp;
            array1.push_back(temp);
        }
        if (allPositive(array1) == true)
        {
            cout << "The vector is positiv in all its numbers" << endl;
        }
        else
            cout << "The vector is not positiv in all its numbers" << endl;
        break;
    case 3:
        cout << "Please insert how many numbers your vector's got: ";
        cin >> input;
        cout << "Please insert your numbers for the vector1: ";
        for (int i = 0; i < input; i++)
        {
            cin >> temp;
            array1.push_back(temp);
        }
        cout << "Please insert your numbers for the vector2: ";
        for (int i = 0; i < input; i++)
        {
            cin >> temp;
            array2.push_back(temp);
        }
        cout << "The scalar product is: " << product(array1, array2) << endl;
        break;
    case 4:
        cout << "Please insert how many numbers your vector has: ";
        cin >> input;
        cout << "Please insert your numbers for the vector: ";
        for (int i = 0; i < input; i++)
        {
            cin >> temp;
            array1.push_back(temp);
        }
        cout << "Please insert the number you want your vector to be multiplied with: ";
        cin >> temp;
        result = product(array1, temp);
        cout << "The product is: " << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << endl;
        }
        break;
    case 5:
        cout << "Please insert how many numbers your vector has: ";
        cin >> input;
        cout << "Please insert your numbers for the vector: ";
        for (int i = 0; i < input; i++)
        {
            cin >> temp;
            array1.push_back(temp);
        }
        cout << "The norm is: " << norm(array1) << endl;
        break;
    case 6:
        cout << "Please insert how many numbers your vector has: ";
        cin >> input;
        cout << "Please insert your numbers for the vector: ";
        for (int i = 0; i < input; i++)
        {
            cin >> temp;
            array1.push_back(temp);
        }
        normalize(array1);
        cout << "The normalised vector is: " << endl;
        for (int i = 0; i < array1.size(); i++)
        {
            cout << array1[i] << endl;
        }
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
    return 0;
}