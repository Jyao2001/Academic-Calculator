#include "main.h"

string currentLetter = "A+";
int creditRow[7] = {0};
string letterRow[7] = {"A+"};
string gradeScale[13] = {"F", "D-", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A","A+"};
int credit[5] = {0, 1, 2, 3, 4};

void addRow(int rowNumber, HWND hWnd)
{
    //array length is 6, then + 1
    int arrayLength = sizeof(creditRow)/sizeof(creditRow[0]) + 1;
    //rowNumber = 2;
    //row number would start from 2 and end at 6
    if(rowNumber < arrayLength)
    {
        CreateWindowW(L"static", L"Class", WS_VISIBLE | WS_CHILD, 25, rowNumber * 100,98,38, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 25,rowNumber * 100 + 25,150,20, hWnd, NULL, NULL, NULL);

        CreateWindowW(L"static", L"# of Credits", WS_VISIBLE | WS_CHILD, 200,rowNumber * 100,98,38, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"button", L"-", WS_VISIBLE | WS_CHILD, 200,rowNumber * 100 +35,25,25, hWnd,
                      (HMENU)(long long) (50 + rowNumber), NULL, NULL);

        CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 235,rowNumber * 100 +25,35,35, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"static", L"0", WS_VISIBLE | WS_CHILD, 245, rowNumber * 100 + 35,20,20, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"button", L"+", WS_VISIBLE | WS_CHILD, 275,rowNumber * 100 + 30,25,25, hWnd,
                      (HMENU)(long long) (100 + rowNumber), NULL, NULL);


        CreateWindowW(L"static", L"Letter Grade", WS_VISIBLE | WS_CHILD, 350,rowNumber * 100,98,38, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"button", L"-", WS_VISIBLE | WS_CHILD, 350,rowNumber * 100 +30,25,25, hWnd,
                      (HMENU)(long long )(150 + rowNumber), NULL, NULL);
        CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 385,rowNumber * 100 + 25,35,35, hWnd,
                      NULL, NULL, NULL);
        CreateWindowW(L"static", L"A+", WS_VISIBLE | WS_CHILD, 395, rowNumber * 100 + 35,20,20, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"button", L"+", WS_VISIBLE | WS_CHILD, 425,rowNumber * 100 + 30,25,25, hWnd,
                      (HMENU)(long long) (200+ rowNumber), NULL, NULL);

        CreateWindowW(L"static", L"Grade Points", WS_VISIBLE | WS_CHILD, 485,rowNumber * 100,98,38, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD, 485,rowNumber * 100 + 25,35,35, hWnd,
                      (HMENU)(long long) (250+rowNumber), NULL, NULL);
    //break;
    }
}

void subCreditButton(int currentRow, HWND hWnd)
{
    //credit condition for subtracting: 0<x<=4
    int index = 0, arrayLength = 0;
    //length of array is 5
    arrayLength = sizeof(credit)/sizeof(credit[0]) ;

    //letter condition for decrementing: F < x <= A+, so all letters except F
    if (currentCredit != 0)
    {
        for (int i = 0; i < arrayLength; i++)
        {
            if(credit[i] == currentCredit)
            {
                index = i;
            }
        }
        creditRow[currentRow] = credit[--index];
        //cout << "credit for row " << currentRow << " is now " << creditRow[currentRow] << endl;
        currentCredit = creditRow[currentRow];

        wchar_t buffer[256];
        wsprintfW(buffer, L"%d", creditRow[currentRow]);
        CreateWindowW(L"static", buffer, WS_VISIBLE | WS_CHILD, 245, (currentRow) * 100 + 35,20,20, hWnd, NULL, NULL, NULL);
    }
}

void addCreditButton(int currentRow, HWND hWnd)
{
    int index = 0, arrayLength = 0;
    //length of array
    arrayLength = sizeof(credit)/sizeof(credit[0]);

    //letter condition for decrementing: F < x <= A+, so all letters except F
    if (currentCredit != 4)
    {
        for (int i = 0; i < arrayLength; i++)
        {
            if(credit[i] == currentCredit)
            {
                index = i;
            }
        }
        creditRow[currentRow] = credit[++index];
        //cout << "credit for row " << currentRow << " is now " << creditRow[currentRow] << endl;
        currentCredit = creditRow[currentRow];

        wchar_t buffer[256];
        wsprintfW(buffer, L"%d", creditRow[currentRow]);
        CreateWindowW(L"static", buffer, WS_VISIBLE | WS_CHILD, 245, (currentRow) * 100 + 35,20,20, hWnd, NULL, NULL, NULL);

    }
}

void subLetterButton(int currentRow, HWND hWnd)
{
    int index = 0, arrayLength = 0;
    //length of array is 13
    arrayLength = sizeof(gradeScale)/sizeof(gradeScale[0]);

    //letter condition for decrementing: F < x <= A+, so all letters except F
    if(currentLetter != "F")
    {
        for (int i = 0; i < arrayLength; i++)
        {
            if(strcmp(gradeScale[i].c_str(), currentLetter.c_str()) == 0)
            {
                index = i;
            }
        }
        //ifstrcmp(currentLetter.c_str(), ) == 0
        letterRow[currentRow] = gradeScale[--index];
        //cout << "letter for row " << currentRow << " is now " << letterRow[currentRow] << endl;
        currentLetter = letterRow[currentRow];

        wstring oldString = wstring(letterRow[currentRow].begin(), letterRow[currentRow].end());
        LPCWSTR newString = oldString.c_str();
        //convertStrToLPCWSTR(letterRow[], currentRow);

        CreateWindowW(L"static", newString, WS_VISIBLE | WS_CHILD, 395, (currentRow) * 100 + 35,20,20, hWnd, NULL, NULL, NULL);

    }
}

void addLetterButton(int currentRow, HWND hWnd)
{

    int index = 0, arrayLength = 0;
    //length of array is 13
    arrayLength = sizeof(gradeScale)/sizeof(gradeScale[0]);

    //letter condition for decrementing: F <= x < A+, so all letters except A+
    if(currentLetter != "A+")
    {
        for (int i = 0; i < arrayLength; i++)
        {
            if(strcmp(gradeScale[i].c_str(), currentLetter.c_str()) == 0)
            {
                index = i;
            }
        }

        letterRow[currentRow] = gradeScale[++index];
        //cout << "letter for row " << currentRow << " is now " << letterRow[currentRow] << endl;
        currentLetter = letterRow[currentRow];

        wstring oldString = wstring(letterRow[currentRow].begin(), letterRow[currentRow].end());
        LPCWSTR newString = oldString.c_str();
        //convertStrToLPCWSTR(letterRow[], currentRow);

        CreateWindowW(L"static", newString, WS_VISIBLE | WS_CHILD, 395, (currentRow) * 100 + 35,20,20, hWnd, NULL, NULL, NULL);
    }
}


