#include "Decimals.h"
#include <iostream>


template <class T>
char NumToArray(const T& number, unsigned char* array, const unsigned char& size = -1) {
    
    if (size == -1)
        unsigned char size = sizeof(T);

    char base =  & number;

    array = new unsigned char[size];

    for (int i = size - 1; i >= 0; --i)
    {
        *(array + i) = number % 256;
        number /= 256;
    }

    return size;
}


Decimal::Decimal(double decimal) {
    return;
}

Decimal::Decimal(long num, char inExp) {
    NumToArray(num, numbers);
    exponent = inExp;
}

int main()
{
    std::cout << sizeof(long) << std::endl;

    return 0;
}