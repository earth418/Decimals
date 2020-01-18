#include "Decimals.h"
#include <iostream>

using namespace std;

Decimal::Decimal(auto exp, auto num)
{
    numbr = numberToArray(num);
    exponent = exp;
}
Decimal::Decimal(double inp)
{
    string in = to_string(inp);
    in.resize(17, '0');
    char pt = 0;
    //cout<<in << "\n";
    for (char i = 16; i > 0; i--) {
        if (in.at(i) != '0')
            pt = i;
    }
    char i = to_string(inp).length() - to_string(inp).find('.') - (pt);
    numbr = numberToArray(inp * pow(10, i));
    exponent = -i;
}

std::vector<unsigned char> Decimal::numberToArray(auto numb)
{
    std::vector<unsigned char> rArray;
    std::vector<double> temp;
    rArray.resize(7);
    temp.resize(7);
    temp[0] = numb / double(pow(256, 6));
    rArray[0] = floor(temp[0]);
    for (int i = 1; i < 7; i++)
    {
        temp[i] = fract(temp[i - 1]) * 256;
        rArray[i] = floor(temp[i]);
    }
    return rArray;
}
unsigned long Decimal::arrayToNumber(std::vector<unsigned char> inArray)
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
    return 0;
}
float Decimal::toFloat() {
    return arrayToNumber(numbr) * pow(10, exponent);
}

int main()
{
    double m = 1523232.24435255;
    Decimal x = m;
    //Decimal x{m};
    cout << sizeof(Decimal) << "\n";
    cout<< x.toString() << "\n";
    cout<< x.exponent << "\n";
    cout << x.arrayToNumber(x.numbr);


    cout<<"\n";
    return 0;
}