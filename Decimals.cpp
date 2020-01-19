#include "Decimals.h"
#include <iostream>

using namespace std;

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

void Decimal::numberToArray(auto numb, unsigned char (&outArray)[7])
{
    double temp[7];
    temp[0] = numb / double(pow(256, 6));
    outArray[0] = floor(temp[0]);
    for (int i = 1; i < 7; i++)
    {
        temp[i] = fract(temp[i - 1]) * 256;
        outArray[i] = floor(temp[i]);
    }
}
unsigned long Decimal::arrayToNumber(unsigned char inArray[7])//std::vector<unsigned char> inArray)
{
    unsigned long numb = 0;
    for (int i = 0; i < 7; i++)
        numb += inArray[i] * pow(256, 6 - i);
    return numb;
}

string Decimal::toString()
{
    unsigned long number = arrayToNumber(numbr);
    char digits = log10(number);
    string rString;
    if (exponent == 0 || exponent - digits == 0)
        return to_string(number);
    else if (exponent < 0 && abs(exponent) > digits) {// && exponent > log10(number)) {
        rString.append("0.");
        for (int i = 0; i < abs(exponent) - (1 + digits); i++) {
            rString.append(to_string(0));
        }
        return rString + to_string(number);
    }
    else if (exponent < 0 && abs(exponent) <= digits) {
        string m = to_string(number);
        m.insert(m.length() + exponent, ".");
        return m;
    }
    else return 0;
    //return to_string(number) + "e" + to_string(exponent);
}
inline Decimal Decimal::operator+(Decimal right)
{
    return 0;
}
inline Decimal Decimal::operator+(auto right)
{
    return Decimal(arrayToNumber(numbr) + right * pow(10, -exponent), exponent);
}
float Decimal::toFloat() {
    return arrayToNumber(numbr) * pow(10, exponent);
}
inline Decimal Decimal::operator*(Decimal right)
{
    return Decimal(arrayToNumber(numbr) * arrayToNumber(right.numbr), exponent + right.exponent);
}
inline Decimal Decimal::operator*(auto right)
{
    return Decimal(arrayToNumber(numbr) * right, exponent);
}

int main()
{
    //Decimal y = 563.25;
    Decimal x = {2, -2};
    Decimal y = {52, -25};
    cout<<(x * 25).toString();
    cout<<(x * y).toString();
    //Decimal x = {6626, -37};
    //cout<<x.toFloat();
    //cout << sizeof(x) << "\n";
    //cout<< x.toString() << "\n";
    //cout<< to_string(x.exponent) << "\n";
    //cout << x.arrayToNumber(x.numbr);

    cout<<"\n";
    return 0;
}