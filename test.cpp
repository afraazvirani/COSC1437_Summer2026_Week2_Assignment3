// ============================================================
// Name    : Afraaz Virani
// Course  : COSC 1437 — Programming Fundamentals II
// Date    : 6/10/26
// Program : Chapter 6 Major Project
// Purpose : This assignment covers the major concepts from Chapter 6: predefined functions, 
// value-returning functions, void functions, value vs. reference parameters, scope, 
// static variables, function overloading, and default parameters.
// ============================================================

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void mathSummary(double x);
double calcTax(double income, double rate);
void printHeader(string courseTitle);
void displayResult(string label, double value);
void convertTime(int totalSeconds, int& minutes, int& seconds);
void countCalls();
void displayBox(int width);
void displayBox(int width, int height);
double calcShipping(double weight, double ratePerPound = 1.50, double baseFee = 5.00);


int main()
{
    mathSummary(5.5);
    mathSummary(10.0);
    
    double grossIncome;
    double taxRate;
    double taxOwed;

    int totalSeconds;
    int minutes;
    int seconds;

    double shippingCost1;
    double shippingCost2;
    double shippingCost3;

    cout << fixed << setprecision(2);

    cout << "Enter your gross income: $" << endl;
    cin >> grossIncome;

    cout << "Enter the tax rate as percentage %: " << endl;
    cin >> taxRate;

    taxOwed = calcTax(grossIncome, taxRate);

    printHeader("Tax Summary");
    displayResult("Tax Owed ($)", taxOwed);


    cout << endl;
    cout << "Enter number of seconds: ";
    cin >> totalSeconds;

    // minutes and seconds are passed as reference parameters as this function needs
    // to change both variables and send the updated values back to main.
    convertTime(totalSeconds, minutes, seconds);

    printHeader("Time Conversion Result");
    displayResult("Minutes", minutes);
    displayResult("Seconds", seconds);

    // a static local variable is created only once and keeps its value between function calls.
    // , while a regular local variable is recreated every time the function runs and loses its value when the function ends.
    printHeader("Static Variable");

    countCalls();
    countCalls();
    countCalls();
    countCalls();


    printHeader("Function Overloading");
    cout << "Square Box:" << endl;
    displayBox(5);

    cout << endl;
    cout << "Rectangle Box:" << endl;
    displayBox(8,4);


    shippingCost1 = calcShipping(10.0, 2.00, 7.50);
    shippingCost2 = calcShipping(10.0, 2.00);
    shippingCost3 = calcShipping(10.0);

    printHeader("Shipping Costs");
    displayResult("Shipping cost with all arguments", shippingCost1);
    displayResult("Shipping cost with weight and rate", shippingCost2);
    displayResult("Shipping cost with weight only", shippingCost3);


    return 0;
}

// ===== Part 1 – Predefined Functions Warm-Up =====
void mathSummary(double x)
{
    cout << fixed << setprecision(2);

    cout << "Math Summary for: " << x << endl;
    cout << "Square root of " << x << ": " << sqrt(x) << endl;
    cout << x << " raised to the power of 3: " << pow(x, 3) << endl;
    cout << "Ceiling of " << x << ": " << ceil(x) << endl;
    cout << "Floor of " << x << ": " << floor(x) << endl;
    cout << "Absolute value of " << x << " * -1: " << fabs(x * -1) << endl;
    cout << endl;
}

// ===== Part 2 – Value-Returning Function =====
double calcTax(double income, double rate)
{
    rate = rate / 100;
    return income * rate;
}

// ===== Part 3 – Void Functions =====
void printHeader(string courseTitle)
{
    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "        " << courseTitle << endl;
    cout << "--------------------------------------" << endl;
}

void displayResult(string label, double value)
{
    cout << fixed << setprecision(2);
    cout << label << ": " << value << endl;
}

// ===== Part 4 – Value vs. Reference Parameters =====
void convertTime(int totalSeconds, int& minutes, int& seconds)
{
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
}

// ===== Part 5 – Scope and Static Variables =====
void countCalls()
{
    static int callCount = 0;
    
    callCount = callCount + 1;
    
    cout << "countCalls has been called " << callCount << " times." << endl;
}

// ===== Part 6 – Function Overloading =====
void displayBox(int width)
{
    for (int row = 1; row <= width; row = row + 1)
    {
        for (int col = 1; col <= width; col = col + 1)
        {
            if (row == 1 || row == width || col == 1 || col == width)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

void displayBox(int width, int height)
{
    for (int row = 1; row <= height; row = row + 1)
    {
        for (int col = 1; col <= width; col = col + 1)
        {
            if (row == 1 || row == height || col == 1 || col == width)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

// ===== Part 7 – Default Parameters =====
double calcShipping(double weight, double ratePerPound, double baseFee)
{
    return baseFee + (weight * ratePerPound);
}