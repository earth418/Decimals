#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define sign(x) (x != 0) ? x/abs(x) : 0
#define fract(x) (x - floor(x))

struct Decimal
{
private:

    char base_byte; // contains the sign of the number
    char exponent;
    unsigned char* numbers; // any additional precision necessary

public:
    Decimal() 
    {
        exponent = 0;
        base_byte = 0;
        numbers = nullptr;
    }

    Decimal(int size)
    {
        exponent = 0;
        base_byte = 0;
        numbers = new unsigned char[size];
    }

    Decimal::Decimal(double decimal);

    Decimal::Decimal(long long num, char exponent);

};
