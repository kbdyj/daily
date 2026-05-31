#include <iostream>

using namespace std;

int powm(int base, int exp, int mod)
{
    int r = 1;
    for (int i=0; i<exp; i++) {
        r *= base;
        r %= mod;
    }
    return r;
}

// mode should be prime number
bool isPrimitive(int base, int mod)
{
    int exp = 2;
    int r = base * base;
    for ( ; r != base; exp++) {
        r *= base;
        r %= mod;
    }
    return exp == mod;
}

void test_isPrimitive()
{
    int base = 3;
    int mod = 5;
    cout << "isPrimivie(" << base << ", " << mod << "): " << isPrimitive(base, mod) << endl;
}

inline void POWM(int base, int mod, int exp)
{
    cout << "powm(" << base << ", " << exp << ", " << mod << "): " << powm(base, exp, mod) << endl;
}

void test_powm()
{
    int base = 3;
    int mod = 5;
    int exp = 100;

    POWM(base, mod, exp);
    exp++;
    POWM(base, mod, exp);
    exp++;
    POWM(base, mod, exp);
    exp++;
    POWM(base, mod, exp);
}

int main()
{
    //test_isPrimitive();
    test_powm();

    return 0;
}
