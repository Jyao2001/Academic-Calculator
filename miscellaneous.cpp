#include "main.h"

double gradePoint[13] = {0, 0.67, 1.00, 1.33, 1.67, 2.00, 2.33, 2.67, 3.00, 3.33, 3.67, 4.00, 4.00};
double gradeRow[7] = {0};

double letterToPoints(string grade)
{
    int arrayLength = sizeof(gradePoint)/sizeof(gradePoint[0]) + 1;
    for(int i = 0; i < arrayLength; i++)
    {
        if(strcmp(currentLetter.c_str(), gradeScale[i].c_str()) == 0)
        {
            return gradePoint[i];
        }
    }
}

void calculateGradePoint(int currentRow, HWND hWnd)
{
    //int arrayLength = sizeof(creditRow)/sizeof(creditRow[0]) + 1, index = 0;
    gradeRow[currentRow] = creditRow[currentRow] * letterToPoints(letterRow[currentRow]);

    wstringstream wss;
    wss << double(gradeRow[currentRow]);
    LPCWSTR newString = wss.str().c_str();

    CreateWindowW(L"static", newString, WS_VISIBLE | WS_CHILD, 485,currentRow * 100 + 30,35,35, hWnd,
                  NULL, NULL, NULL);

}

void createLine(HWND hWnd)
{
    int height = 0;
    while (height < 501)
    {
        CreateWindowW(L"static", L"|", WS_VISIBLE | WS_CHILD, 600, 100 + height,35,35, hWnd,
                      NULL, NULL, NULL);
        height++;
    }
}

string TextBoxData (HWND hWnd)
{
    int len = GetWindowTextLength(hWnd) + 1;
    char* text = new char[len];
    GetWindowText(hWnd, &text[0], len);
    return text;
}

void calculateCumulativeGPA (){
    int arrayLength = sizeof(gradeRow)/sizeof(gradeRow[0]), totalGradePoint = 0;
    for(int i = 0; i < arrayLength; i++)
    {
        totalGradePoint += gradeRow[i];
    }

}
