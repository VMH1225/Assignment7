// Date: 10/17/2022
// Description: Chapter 7 - Assignment
// By: Victor Huerta, Alejandro Mamani, Arturo Sanchez, Bryan Soto, and Tien Nguyen

#include <iostream>
#include "input.h"
using namespace std;
int menuOption();

int main() {
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
        }
    } while (true);
    return EXIT_SUCCESS;
}


int menuOption()
{
    system("cls");
    cout << "\n\tCMPR131 Chapter 7 - Application Using Stacks (10/17/2022)";
    cout << "\n\tDeveloped by Group 3: Victor H, Alejandro M, Arturo S, Bryan S, and Tien N";
    cout << "\n\t" + string(100, char(205));
    cout << "\n\t\t1> Simple Calculator (problem 9, pg 391)";
    cout << "\n\t\t2> Translation of arithmetic expression (problem 10, pg 391)";
    cout << "\n\t\t3> n-Queens Problem (problem 11, pg 391-292)";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0> Exit";
    cout << "\n\t" + string(100, char(205));

    int option = inputInteger("\n\tOption: ", 0, 3);
    system("cls");

    return option;
}

