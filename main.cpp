// Date: 10/17/2022
// Description: Chapter 7 - Assignment
// By: Victor Huerta, Alejandro Mamani, Arturo Sanchez, Bryan Soto, and Tien Nguyen

#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include <stack>
#include "input.h"

using namespace std;
int menuOption();
void challenge1();
void printStack(stack<double> s);
double operate(stack<double>& nums, string op);

int main() {
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: challenge1(); break;
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

// use alejnadros class that converts infix notation to postfix notation.
// assume that his program return a valid postfix expression
// Now you have the postfix notation expression
// create stack template
// 2 stacks are created using stack template
// pseudocode for this problem found on page 377-378 & 380

void challenge1() {
    string expression = "";
    bool flag = true;
    string option = "";
    stack<double> numbers;
    double tempNum;

    do {

        cout << "\n\t\tSimple Calculator";
        cout << "\n\t\t" + string(80, char(205));
        cout << "\n\t\tEnter an arithmetic expression: ";

        getline(cin, expression);

        // printing out words function 
        string word = "";
        for (auto x : expression)
        {
            if (x == ' ')
            {
                if (word == "*" || word == "/" || word == "+" || word == "-" || word == "^") {
                    cout << "Calling operator sending " << word << " operator.\n";
                    operate(numbers, word);               
                }
                else {
                    cout << "It is a number " << word << endl;
                    numbers.push(stod(word));
                }
                word = "";
            }
            else {
                word = word + x;
            }
        }
        if (word == "*" || word == "/" || word == "+" || word == "-" || word == "^") {
            cout << "Calling operator sending " << word << " operator.\n";
            operate(numbers, word);
        }
        else {
            cout << "It is a number " << word << endl;
            numbers.push(stod(word));
        }
        // printing out word
        cout << "\nprinting stack\n\n";
        printStack(numbers);

        system("pause");
    } while (false);
}

double operate(stack<double>& nums, string op) {
    double leftOperand = 0;
    double rightOperand = 0;
    if (nums.empty()) {
        cout << "\nError empty stack\n";
        return 1.1;
    }
    cout << "\nThe size of the stack is " << nums.size() << endl;
    cout << "\nThe operator passed in is " << op << endl;
    if (nums.size() >= 2) {
        rightOperand = nums.top();
        nums.pop();
        leftOperand = nums.top();
        nums.pop();
    }
    if (op == "+") {
        cout << leftOperand << " + " << rightOperand << " = " << leftOperand + rightOperand << endl;
        nums.push(leftOperand + rightOperand);   
    }
    else if(op == "-") {
        cout << "\nSubtraction time hijo de puta chingada madre\n";
        cout << leftOperand << " - " << rightOperand << " = " << leftOperand - rightOperand << endl;
        nums.push(leftOperand - rightOperand);
    }
    else if (op == "*") {
        cout << "Multiplication time hijo de puta chingada madre\n";
        cout << leftOperand << " * " << rightOperand << " = " << leftOperand * rightOperand << endl;
        nums.push(leftOperand * rightOperand);
    }
    else if (op == "/") {
        cout << "Division time hijo de puta chingada madre\n";
        cout << leftOperand << " / " << rightOperand << " = " << leftOperand / rightOperand << endl;
        nums.push(leftOperand / rightOperand);
    }
    else if (op == "^") {
        cout << "Division time hijo de puta chingada madre\n";
        cout << leftOperand << " ^ " << rightOperand << " = " << pow(leftOperand, rightOperand) << endl;
        nums.push(pow(leftOperand, rightOperand));
    }
    else {
        cout << "\nInvalid operator\n";
    }
    return 1.1;
}

void printStack(stack<double> s)
{
    // If stack is empty
    if (s.empty())
        return;

    // Extract top of the stack
    double x = s.top();

    // Pop the top element
    s.pop();

    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';

    // Proceed to print
// remaining stack
    printStack(s);

    // Push the element back
    s.push(x);
}


            // how this shoul work
            // go through the expression        
            // take each space separated number and add it to the stack
            // when an operand is ecountered pop 2 elements off the stack evaluate them using the operand and push value on to the stack
            // the number remaining after we have gone through the entire expression is the answer

    

       /* do {
            option = inputString("\n\tEnter another arithmetic expression? (Yes or No): ", 0);
            option = tolower(option[0]);
            cout << "\nThe option you entered was " << option << endl;
        } while (option != "y" && option != "n");
        if (option == "n" || option == "N") {
            flag = false;
        }
    }while (flag == true);*/


