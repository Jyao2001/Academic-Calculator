#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cwchar>
#include <array>
#include <commdlg.h>
#include <sstream>
using namespace std;

#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define CHANGE_TITLE 4
#define GENERATE_BUTTON 5
#define OPEN_FILE_BUTTON 6
#define SAVE_FILE_BUTTON 7
#define ADD_ROW_BUTTON 8

#define ADD_CREDIT_BUTTON1 11
#define SUB_CREDIT_BUTTON1 12
#define ADD_CREDIT_BUTTON2 13
#define SUB_CREDIT_BUTTON2 14
#define ADD_CREDIT_BUTTON3 15
#define SUB_CREDIT_BUTTON3 16
#define ADD_CREDIT_BUTTON4 17
#define SUB_CREDIT_BUTTON4 18
#define ADD_CREDIT_BUTTON5 19
#define SUB_CREDIT_BUTTON5 20
#define ADD_CREDIT_BUTTON6 21
#define SUB_CREDIT_BUTTON6 22


#define ADD_LETTER_BUTTON1 23
#define SUB_LETTER_BUTTON1 24
#define ADD_LETTER_BUTTON2 25
#define SUB_LETTER_BUTTON2 26
#define ADD_LETTER_BUTTON3 27
#define SUB_LETTER_BUTTON3 28
#define ADD_LETTER_BUTTON4 29
#define SUB_LETTER_BUTTON4 30
#define ADD_LETTER_BUTTON5 31
#define SUB_LETTER_BUTTON5 32
#define ADD_LETTER_BUTTON6 33
#define SUB_LETTER_BUTTON6 34

extern LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
extern void AddMenus(HWND);
extern void AddControls(HWND);
extern void loadImages();
extern void registerDialogClass(HINSTANCE);
extern void displayDialog(HWND);
extern void save_file(HWND);
extern void addRow(int, HWND);
extern void subCreditButton(int, HWND);
extern void addCreditButton(int, HWND);
extern void subLetterButton(int, HWND);
extern void addLetterButton(int, HWND);

//h for handler
extern HMENU hMenu;
extern HWND hEdit, hName, hAge, hOutput, hLogo, hMainWindow, hFileEdit;
extern HBITMAP hLogoImage, hGenerateImage;
extern int timePressed, currentCredit;
extern string currentLetter;
extern int creditRow[7];
extern string letterRow[7];
extern double gradeRow[7];
extern string gradeScale[13];
extern double gradePoint[13];
extern char textSave[20];
void createLine(HWND);
string TextBoxData (HWND);
//wstring string_to_wstring(string&);
extern int credit[5];
extern void convertStrToLPCWSTR (string*, int);
double letterToPoints(string);
void calculateGradePoint(int , HWND );
extern void calculateCumulativeGPA();
//extern int gradePoint[6];
#endif
