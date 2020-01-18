#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define sign(x) (x != 0) ? x/abs(x) : 0
#define fract(x) (x - floor(x))

struct Decimal
{
    std::vector<unsigned char> numberToArray(auto numb);
    
    unsigned long arrayToNumber(std::vector<unsigned char> inArray);
    
    char exponent;
    std::vector<unsigned char> numbr;

    Decimal(auto exp, auto num);
    Decimal(double inp);

    std::string toString();

    inline Decimal operator+(Decimal right);
    inline Decimal operator+(auto right);

    float toFloat();
};
