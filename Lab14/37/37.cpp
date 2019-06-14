#include <iostream>
#include "fractionizer.h"
using namespace std;

typedef struct
{
    double num;
    double denom;
} Fraction;

int gcd(int x, int y)
{
    return (x == y) ? x : gcd((x < y) ? x : y, (x > y) ? x - y : y - x);
}

int lcd(int x, int y)
{
    return x * y / gcd(x, y); 
}

int main(int argc, char const *argv[])
{
    double x, y;
    Fraction x_frac, y_frac;

    cout << "Put first rational number: ";
    cin >> x;

    cout << "Put second rational number: ";
    cin >> y;

    Fractionizer::fractionize(x, *&x_frac.num, *&x_frac.denom);
    Fractionizer::fractionize(y, *&y_frac.num, *&y_frac.denom);

    cout << "First number as fraction: " << *&x_frac.num << "/" << *&x_frac.denom << endl;
    cout << "Second number as fraction: " << *&y_frac.num << "/" << *&y_frac.denom << endl;

    if (*&x_frac.denom == *&y_frac.denom) 
    {
        cout << "Their sum is " << *&x_frac.num + *&y_frac.num << "/" << *&y_frac.denom << endl;
    } else 
    {
        int lcd_denom = lcd(*&x_frac.denom, *&y_frac.denom);
        int additional_mul_x = lcd_denom / *&x_frac.denom;
        int additional_mul_y = lcd_denom / *&y_frac.denom;
        int new_x_num = *&x_frac.num * additional_mul_x;
        int new_x_denom = *&x_frac.denom * additional_mul_x;
        int new_y_num = *&y_frac.num * additional_mul_y;

        cout << "Their sum is " << new_x_num + new_y_num << "/" << new_x_denom << endl;
    }
    
    return 0;
}
