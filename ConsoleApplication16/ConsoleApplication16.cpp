#include <iostream>
#include <time.h>

using namespace std;

void Random(int** ptraray, int a, int b)
{
    srand(time(NULL));

    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            ptraray[i][j] = rand() % 9 + 1;
        }

}

void Show(int** ptraray, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "   " << ptraray[i][j] << "  ";
        }
        cout << endl;
    }
}void GetShow( int a, int b)
{
    FILE* pf;
    fopen_s(&pf, "s.txt", "r");
    if (pf != nullptr)
    {
        
        char ch;
        while ((ch=fgetc(pf))!=EOF)
        {
            cout << ch;
        }
        fclose(pf);
    }
}

void SetToFile(int** ptraray, int a, int b)
{
    FILE* pf;
    fopen_s(&pf, "s.txt", "w");
    if (pf != nullptr)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                
                fprintf(pf, "%i\t", &ptraray[i][j]);
            }
            fprintf(pf, "\n");
            cout << endl;
        }
        fclose(pf);
    }
    else
    {
        cout << "Error" << endl;
    }

}

void Delete(int** ptraray, int a)
{
    for (int i = 0; i < a; i++)
    {
        delete[] ptraray[i];
    }
    delete[] ptraray;
}

int main()
{
    int a, b;

    cout << "Size: ";
    cin >> a >> b;

    int** ptraray = new int* [a];

    for (int i = 0; i < a; i++)
    {
        ptraray[i] = new int[b];
    }

    Random(ptraray, a, b);
    Show(ptraray, a, b);
    Delete(ptraray, a);
    SetToFile(ptraray, a, b);
    GetShow(a, b);
    return 0;
}