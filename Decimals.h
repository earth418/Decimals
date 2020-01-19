#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define sign(x) (x != 0) ? x/abs(x) : 0
#define fract(x) (x - floor(x))

struct Decimal
{
    inline long pow10(char exp);
    inline long num();
    /*std::vector<unsigned char>*/ void numberToArray(auto numb, unsigned char (&outArray)[6]);
    
    unsigned long arrayToNumber(unsigned char inArray[6]);//std::vector<unsigned char> inArray);
    
    char exponent;
    char scalar;
    unsigned char numbr[6] = {0, 0, 0, 0, 0, 0};

    Decimal(auto num, auto exp);
    Decimal(long inp);
    Decimal(int inp);
    Decimal(double inp);

    std::string toString();



    inline Decimal operator+(Decimal right);
    inline Decimal operator+(auto right);

    inline Decimal operator*(Decimal right);
    inline Decimal operator*(auto right);

    double toFloat();
};
