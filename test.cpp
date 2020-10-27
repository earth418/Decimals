#include "Decimals.h"
#include <iostream>
#include <string>
#include "LinkedList.h"

int main()
{
    // ListIndex head = {0, nullptr};

    ListIndex last = {0, nullptr};
    ListIndex* t = nullptr;

    for (char i = 0; i < 10; i++)
    {
        last.next = t;
        t = new ListIndex{i, &last};

        std::cout<<i;
        // head.next = new ListIndex{i};
    }

    int m = 0;
    ListIndex* iterator = &last;
    while (iterator->next)
    {
        // std::cout<< iterator->value;

        iterator = iterator->next;
        m++;
    }

    std::cout<< m << "\n";

    return 0;
}