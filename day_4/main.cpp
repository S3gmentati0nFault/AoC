#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char keyword[] = {'M', 'A', 'S'};

int checkStar(int i, int j, char **matrix, int size)
{
    int counter = 0;
    bool found = true;

    // Right
    for (int k = 1; k < 4 && found; ++k)
    {
        if (i + k >= size)
        {
            found = false;
            break;
        }

        char letter = matrix[i + k][j];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    // Lower right diagonal
    found = true;
    for (int k = 1; k < 4 && found; ++k)
    {
        if (i + k >= size || j + k >= size)
        {
            found = false;
            break;
        }

        char letter = matrix[i + k][j + k];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    // Down
    found = true;
    for (int k = 1; k < 4 && found; ++k)
    {
        if (j + k >= size)
        {
            found = false;
            break;
        }

        char letter = matrix[i][j + k];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    // Lower left diagonal
    found = true;
    for (int k = 1; k < 4 && found; ++k)
    {
        if (i - k < 0 || j + k >= size)
        {
            found = false;
            break;
        }

        char letter = matrix[i - k][j + k];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    // Left
    found = true;
    for (int k = 1; k < 4 && found; ++k)
    {
        if (i - k < 0)
        {
            found = false;
            break;
        }

        char letter = matrix[i - k][j];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    // Upper left diagonal
    found = true;
    for (int k = 1; k < 4 && found; ++k)
    {
        if (i - k < 0 || j - k < 0)
        {
            found = false;
            break;
        }

        char letter = matrix[i - k][j - k];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    // Up
    found = true;
    for (int k = 1; k < 4 && found; ++k)
    {
        if (j - k < 0)
        {
            found = false;
            break;
        }

        char letter = matrix[i][j - k];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    // Upper right diagonal
    found = true;
    for (int k = 1; k < 4 && found; ++k)
    {
        if (i + k >= size || j - k < 0)
        {
            found = false;
            break;
        }

        char letter = matrix[i + k][j - k];

        if (letter != keyword[k - 1])
        {
            found = false;
        }
    }
    if (found)
    {
        ++counter;
    }

    return counter;
}

int checkStarVariant(int i, int j, char **matrix, int size)
{
    int counter = 0;

    if (i + 1 < size && j + 1 < size && i - 1 >= 0 && j - 1 >= 0)
    {
        if (matrix[i + 1][j - 1] == 'M' && matrix[i - 1][j + 1] == 'S' && matrix[i - 1][j - 1] == 'M' && matrix[i + 1][j + 1] == 'S')
        {
            ++counter;
        }

        if (matrix[i + 1][j - 1] == 'S' && matrix[i - 1][j + 1] == 'M' && matrix[i - 1][j - 1] == 'S' && matrix[i + 1][j + 1] == 'M')
        {
            ++counter;
        }

        if (matrix[i + 1][j - 1] == 'M' && matrix[i - 1][j + 1] == 'S' && matrix[i - 1][j - 1] == 'S' && matrix[i + 1][j + 1] == 'M')
        {
            ++counter;
        }

        if (matrix[i + 1][j - 1] == 'S' && matrix[i - 1][j + 1] == 'M' && matrix[i - 1][j - 1] == 'M' && matrix[i + 1][j + 1] == 'S')
        {
            ++counter;
        }
    }

    return counter;
}

int main()
{
    ifstream f("input.txt");
    if (!f.is_open())
    {
        cout << "Could not open the file" << endl;
        return -1;
    }

    int size = 140;
    char letter;

    char **matrix = new char *[size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new char[size];
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (f >> letter)
            {
                matrix[i][j] = letter;
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            letter = matrix[i][j];

            if (letter == 'X')
            {
                counter += checkStar(i, j, matrix, size);
            }
        }
    }

    cout << counter << endl;

    counter = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            letter = matrix[i][j];

            if (letter == 'A')
            {
                counter += checkStarVariant(i, j, matrix, size);
            }
        }
    }

    cout << counter << endl;

    return 0;
}
