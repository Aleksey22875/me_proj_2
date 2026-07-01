#include "libmath.h"

namespace libmath
{
    int addition(int x, int y)
    {

        return x + y;
    }
    int subtraction(int x, int y)
    {
        return x - y;
    }
    int multiplication(int x, int y)
    {
        return x * y;
    }
    int power(int x, int y)
    {
        int c = 1;
        for (int i = 0; i < y; i++)
        {
            c = c * x;
        }
        return c;
    }
    int division(int x, int y, int &c)
    {
        if (y == 0)
        {
            return -1;
        }
        else
        {
            c = x / y;
            return 0;
        }
    }
}