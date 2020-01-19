#include "Decimals.h"
#include <iostream>

using namespace std;

inline long Decimal::num() {
    return arrayToNumber(numbr);
}

Decimal::Decimal(auto num, auto exp)
{
    numberToArray(num, numbr);
    exponent = exp;
}
Decimal::Decimal(long inp)
{
    numberToArray(inp, numbr);
    exponent = 0;
}
Decimal::Decimal(int inp)
{
    numberToArray(inp, numbr);
    exponent = 0;
}
Decimal::Decimal(double inp)
{
    string in = to_string(inp);
    cout<<in;
    in.resize(17, '0');
    char pt = 0;
    for (char i = 16; i > 0; i--) {
       if (in.at(i) != '0') pt = i;
    }
    in.resize(pt, '0');
    cout<<in;
    char i = in.length() - in.find('.') - 1; // - (pt);
    numberToArray(inp * pow(10, i), numbr);
    exponent = -i;
    in.erase();
}

void Decimal::numberToArray(auto numb, unsigned char (&outArray)[6])
{
    double temp[6];
    double scalr = numb / double(pow(256, 5));
    outArray[0] = floor(fract(scalr) * 256);
    for (int i = 1; i < 6; i++)
    {
        temp[i] = fract(temp[i - 1]) * 256;
        outArray[i] = floor(temp[i]);
    }
    scalar = floor(scalr);
}

unsigned long Decimal::arrayToNumber(unsigned char inArray[6])//std::vector<unsigned char> inArray)
{
    unsigned long numb = 0;
    for (int i = 0; i < 6; i++)
        numb += inArray[i] * pow(256, 5 - i);
    numb += (scalar * pow(256, 6));
    return numb;
}

string Decimal::toString()
{
    char digits = log10(num());

    string rString;
    if (exponent > 0)
        return to_string(num() * pow10(exponent));
    else if (exponent == 0 || exponent - digits == 0)
        return to_string(num());
    else if (exponent < 0 && abs(exponent) > digits) {// && exponent > log10(number)) {
        rString.append("0.");
        for (int i = 0; i < abs(exponent) - (1 + digits); i++) {
            rString.append(to_string(0));
        }
        return rString + to_string(num());
    }
    else if (exponent < 0 && abs(exponent) <= digits) {
        string m = to_string(num());
        m.insert(m.length() + exponent, ".");
        return m;
    }
    else return 0;
    //return to_string(number) + "e" + to_string(exponent);
}

inline Decimal Decimal::operator+(Decimal right)
{
    if (right.exponent > exponent)
        return Decimal(num() * pow10(right.exponent - exponent) + right.num(), right.exponent);
    //if (right.exponent < 0)
    //    return Decimal(right.number() * pow10(-right.exponent) + number() * pow10(exponent - right.exponent), right.exponent);
    //if (right.exponent > exponent)
    //    return Decimal(arrayToNumber(right.numbr) * pow(10, exponent) + arrayToNumber(right.numbr) * pow(10, right.exponent), exponent);
    //else
    //    return Decimal(number() + arrayToNumber(right.numbr) * pow(10, exponent - right.exponent), exponent);
}
inline Decimal Decimal::operator+(auto right)
{
    if (exponent <= 0)
        return Decimal(num() * pow10(-exponent) + right, exponent);
    else
        return Decimal(num() * pow10(exponent) + right, 0);
}
double Decimal::toFloat() {
    return num() * pow10(exponent);
}
inline Decimal Decimal::operator*(Decimal right)
{
    return Decimal(num() * right.num(), exponent + right.exponent);
}
inline Decimal Decimal::operator*(auto right)
{
    return Decimal(num() * right, exponent);
}
inline long Decimal::pow10(char exp)
{
    long ret = 1;
    for (char i = 0; i < exp; i++)
        ret *= 10;
    return ret;
}


int main()
{
    //Decimal y = 563.25;
    Decimal x = {20, 2};
    Decimal y = {2, 3};
    //cout<<sizeof(Decimal) << "\n" << "\n";
    //cout<<sizeof(long) << "\n" << "\n";

    cout<<(  x  ).toString() << "\n";
    // cout<<(x * 5).toString() << "\n";
    // cout<<(x * y).toString() << "\n";
    // cout<<(x + y).toString() << "\n";
    //double b = (x + 6).toFloat();
    //cout<<to_string(b) << "\n";
    //cout<<(x + 6).toString() << "\n";
    //Decimal x = {6626, -37};
    //cout<<x.toFloat();
    //cout << sizeof(x) << "\n";
    //cout<< x.toString() << "\n";
    //cout<< to_string(x.exponent) << "\n";
    //cout << x.arrayToNumber(x.numbr);

    cout<<"\n";
    return 0;
}