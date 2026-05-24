#include <string>

namespace { //=================================================================

namespace good {

template <class T>
std::string sign(T x)
{
    if (x < 0)
        return "negative";
    else if (0 < x)
        return "positive";
    else
        return "zero";
}

} //good

namespace bad {

template <class T>
std::string sign(T x)
{
    std::string ret;

    if (x < 0)
        ret = "negative";
    else if (0 < x)
        ret = "positive";
    else
        ret = "zero";

    return ret;
}

} //bad

} //===========================================================================

