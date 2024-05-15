#include <iostream>
#include "CRational.h"

int main()
{
    CRational a = 5, b = 6, c = 7;
    ((a+=b)+=c);
    std::cout << a;
}
