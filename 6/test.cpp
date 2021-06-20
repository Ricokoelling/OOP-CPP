/*
void buildfield(vector<vector<char>> *field)
{
    srand(time(nullptr));
    for (int i = 0; i < field->size(); i++)
    {
        vector<char> x = field->at(i);
        for (int j = 0; j < field->size(); j++)
        {
            int temp1 = rand() % 5 + 1;
            switch (temp1)
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
*/