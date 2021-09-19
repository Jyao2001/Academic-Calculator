#include "main.h"

HMENU hMenu;
HWND hEdit, hName, hAge, hOutput, hLogo, hMainWindow, hFileEdit, creditBox, GPABox;
//HBITMAP hLogoImage, hGenerateImage;
int timePressed = 2, currentCredit = 0;
char textSave[20] = {0};


int WINAPI WinMain (HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    //creates message box
    //MessageBox(NULL, "Hello","My first GUI", MB_OK);
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    //L prefix
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;


    if(!RegisterClassW(&wc))
    {
        cout << "Application failed at register class" << endl;
        return -1;
    }

    //xxxW to specify type
    //1000x500 device unit size created for window
    //  x|y|width|height
    hMainWindow = CreateWindowW(L"myWindowClass", L"Academic Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_VSCROLL  | WS_HSCROLL, 0,0, 1000, 500,
                                NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while(GetMessage (&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

//first pop up menu
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    int val = 0, row = 2, currentCredit = 0, rowNumber = 1;
    int arrayLength = sizeof(creditRow)/sizeof(creditRow[0])+1;
    double numCredit = 0, numPoint = 0, semesterGPA = 0;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case ADD_ROW_BUTTON:
            addRow(timePressed, hWnd);
            //cout << "row is: " << row << endl;
            //cout << "time pressed is: " << timePressed << endl;
            timePressed++;
            break;
        }
        break;

    case WM_CREATE:
    {
        AddControls(hWnd);

        CreateWindowW(L"static", L"Cumulative GPA", WS_CHILD | WS_VISIBLE, 800,400,150,50, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"static", L"Total # of Credits", WS_CHILD | WS_VISIBLE, 652,460,150,200, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"static", L"Current GPA", WS_CHILD | WS_VISIBLE, 850,460,150,200, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"static", L"Cumulative GPA", WS_CHILD | WS_VISIBLE, 1100,460,150,200, hWnd, NULL, NULL, NULL);
        creditBox = CreateWindowW(L"edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 652,475,150,20, hWnd, NULL, NULL, NULL);
        GPABox = CreateWindowW(L"edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 850,475,150,20, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"Button", L"Enter", WS_BORDER | WS_CHILD | WS_VISIBLE, 1000,475,50,25, hWnd, (HMENU) 1, NULL, NULL);
    }

    break;
    case WM_DESTROY:
        //makes GetMessage return false to exit loop
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }

        //int arrayLength = sizeof(creditRow)/sizeof(creditRow[0]) + 1;
    CreateWindowW(L"static", L"Total Grade Points (Semester)", WS_CHILD | WS_VISIBLE, 700,150,150,200, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L" / ", WS_CHILD | WS_VISIBLE, 875,150,150,200, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Total Credits (Semester)", WS_CHILD | WS_VISIBLE, 950,150,150,200, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L" = ", WS_CHILD | WS_VISIBLE, 1050,150,150,200, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Semester GPA", WS_CHILD | WS_VISIBLE, 1100,150,150,200, hWnd, NULL, NULL, NULL);

    for(int i = 0; i < arrayLength; i ++)
    {
        numPoint += gradeRow[i];
        numCredit += creditRow[i];
    }

    semesterGPA = numPoint / numCredit;
    //cout << "# of credit is: " << numCredit << endl;
    //cout << "grade point is: " << numPoint << endl;
    //cout << "semester GPA is: " << semesterGPA << endl;

    if(numPoint == 0 || numCredit == 0 || semesterGPA == 0)
    {
        CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE, 700,200,150,200, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE, 950,200,150,200, hWnd, NULL, NULL, NULL);
        CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE, 1100,200,150,200, hWnd, NULL, NULL, NULL);
    }
    else
    {
        wstringstream wss;
        wss << numPoint;
        LPCWSTR  newString = wss.str().c_str();
        CreateWindowW(L"static", newString, WS_CHILD | WS_VISIBLE, 700,200,150,200, hWnd, NULL, NULL, NULL);

        wstringstream wsss;
        wsss << numCredit;
        //LPCWSTR
        newString = wsss.str().c_str();
        CreateWindowW(L"static", newString, WS_CHILD | WS_VISIBLE, 950,200,150,200, hWnd, NULL, NULL, NULL);

        wstringstream wssss;
        wssss << semesterGPA;
        //LPCWSTR
        newString = wssss.str().c_str();
        CreateWindowW(L"static", newString, WS_CHILD | WS_VISIBLE, 1100,200,150,200, hWnd, NULL, NULL, NULL);
    }



    if(msg == WM_COMMAND)
    {
        for(int i = 1; i < arrayLength; i++)
        {
            if(wp == (long long) (50 + rowNumber))
            {
                //cout << "first if statement has been called" << endl;
                subCreditButton(rowNumber, hWnd);
                calculateGradePoint(rowNumber, hWnd);
            }
            else if(wp == (long long) (100 + rowNumber))
            {
                addCreditButton(rowNumber, hWnd);
                calculateGradePoint(rowNumber, hWnd);
            }
            else if (wp == (long long) (150 + rowNumber))
            {
                subLetterButton(rowNumber, hWnd);
                calculateGradePoint(rowNumber, hWnd);
            }
            else if(wp == (long long) (200 + rowNumber))
            {
                addLetterButton(rowNumber, hWnd);
                calculateGradePoint(rowNumber, hWnd);
            }
            else if(wp == (long long) (250 + rowNumber))
            {
                //addLetterButton(rowNumber, hWnd);
                calculateGradePoint(rowNumber, hWnd);
            }
            rowNumber++;
        }

        if (wp == 1)
        {
            int totalCredit = stoi(TextBoxData(creditBox));
            int GPA = stoi(TextBoxData(GPABox));
            int gradePoint = (totalCredit * GPA + numPoint) / (numCredit + totalCredit);
            cout << "grade point is: " << gradePoint << endl;

            wstringstream wss;
            wss << gradePoint;
            LPCWSTR newString = wss.str().c_str();
            CreateWindowW(L"static", newString, WS_CHILD | WS_VISIBLE, 1100,480,150,200, hWnd, NULL, NULL, NULL);
        }
    }
}


void AddControls(HWND hWnd)
{
    CreateWindowW(L"static", L"GPA Calculator: ", WS_VISIBLE | WS_CHILD, 500, 0, 110, 20, hWnd,
                  NULL, NULL, NULL);
    CreateWindowW(L"button", L"Add Row", WS_VISIBLE | WS_CHILD, 25,50,98,38, hWnd,
                  (HMENU)ADD_ROW_BUTTON, NULL, NULL);

//************************************************
    //int a[16] = {16};
    //a[16] = 16;
    //wchar_t buffer[256];
    //wsprintfW(buffer, L"%d", a[16]);
    //MessageBoxW(nullptr, buffer, buffer, MB_OK);
    //CreateWindowW(L"static", buffer, WS_VISIBLE | WS_CHILD, 200,100,98,38, hWnd, NULL, NULL, NULL);
//************************************************

    CreateWindowW(L"static", L"Class", WS_VISIBLE | WS_CHILD, 25,100,98,38, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 25,125,150,20, hWnd, NULL, NULL, NULL);


    CreateWindowW(L"static", L"# of Credits", WS_VISIBLE | WS_CHILD, 200,100,98,38, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"button", L"-", WS_VISIBLE | WS_CHILD, 200,130,25,25, hWnd,
                  (HMENU)(long long) (50+1), NULL, NULL);
    CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 235,125,35,35, hWnd, NULL, NULL, NULL);
    ///////////////////////////////////////////////////////////////////////////
    CreateWindowW(L"static", L"0", WS_VISIBLE | WS_CHILD, 245, 135,20,20, hWnd, NULL, NULL, NULL);
    /////////////////////////////////////////////////////////////////////////////////////////////////
    CreateWindowW(L"button", L"+", WS_VISIBLE | WS_CHILD, 275,130,25,25, hWnd,
                  (HMENU)(long long) (100+1), NULL, NULL);

    CreateWindowW(L"static", L"Letter Grade", WS_VISIBLE | WS_CHILD, 350,100,98,38, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"button", L"-", WS_VISIBLE | WS_CHILD, 350,130,25,25, hWnd,
                  (HMENU)(long long) (150+1), NULL, NULL);
    CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 385,125,35,35, hWnd,
                  NULL, NULL, NULL);
    //////////////////////////////////////////////////////////////////////////////////////////////
    CreateWindowW(L"static", L"A+", WS_VISIBLE | WS_CHILD, 395, 135,20,20, hWnd, NULL, NULL, NULL);
    /////////////////////////////////////////////////////////////////////////////////////////////
    CreateWindowW(L"button", L"+", WS_VISIBLE | WS_CHILD, 425,130,25,25, hWnd,
                  (HMENU)(long long) (200+1), NULL, NULL);


    CreateWindowW(L"static", L"Grade Points", WS_VISIBLE | WS_CHILD, 485,100,98,38, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD, 485,125,35,35, hWnd,
                  (HMENU)(long long) (250+1), NULL, NULL);
}

int main ()
{
    HINSTANCE hInst, hPrevInst;
    LPSTR args;
    int ncmdshow;
    //cout << "Joe mama" << endl;
    WINAPI WinMain ( hInst,  hPrevInst,  args,  ncmdshow);

}
