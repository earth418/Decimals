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
    void numberToArray(long numb, unsigned char (&outArray)[7]);
    
    unsigned long arrayToNumber(unsigned char inArray[7]);
    
    char exponent;

    unsigned char numbr[7] = {0, 0, 0, 0, 0, 0, 0};

    Decimal(long num, char exp);
    Decimal(long inp);
    Decimal(int inp);
    Decimal(double inp);

    std::string toString();

    inline Decimal operator+(Decimal right);
    inline Decimal operator+(double right);

    inline Decimal operator*(Decimal right);
    inline Decimal operator*(double right);

    double toFloat();
};
