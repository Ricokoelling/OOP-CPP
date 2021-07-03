double datenzugriff()
{
    string input, temp;
    ifstream is;
    int temp2 = 0;
    is.open("track.txt");
    is >> input;
    for (int i = 0; i < input.length(); i++)
    {
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
            temp2 = 0;
        }
    }
};