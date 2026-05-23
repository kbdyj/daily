#include <iostream>
#include <vector>
#include <assert.h>

// NR.5 Don't use two-phase initialization

namespace bad {

class Picture {
    int mX;
    int mY;
    int*pData;

public:
    Picture(int x, int y)
    {
        mX = x;
        mY = y;
        pData = nullptr;
    }
    ~Picture()
    {
        cleanup();
    }

    bool initialize()
    {
        if (mX <= 0 || mY <= 0)
            return false;
        if (pData) {
            return false;
        }
        pData = new int[mX * mY];

        return nullptr != pData;
    }

    void cleanup()
    {
        delete [] pData;

        pData = nullptr;
    }
};

} //bad

namespace good {


class Picture {
    int mX;
    int mY;
    std::vector<int> data;

    static int checkSize(int size) {
        assert(0 < size);

        return size;
    }

public:
    Picture(int x, int y)
        : checkSize(x)
        , checkSize(y)
        , data(mX * mY)
    {

    }
};

} //good

void test_NR5()
{
    bad::Picture p0(100, 0);
    if (!p0.initialize()) {
        std::cerr << "Error, invalid picture.";
    }

    good::Picture p1(100, 100);
    good::Picture p2(100, 0);
}