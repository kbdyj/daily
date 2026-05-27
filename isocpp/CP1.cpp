namespace { //=================================================================

namespace bad {

double cachedComputation(int x)
{
#if (0)
    static int cachedX = 0.0;
    static double cachedResult = 0.0;
#else
    // Mark the state variables as thread_local instead of static
    thread_local int cachedX = 0.0;
    thread_local double cachedResult = 0.0;
#endif

    if (cachedX != x) {
        cachedX = x;
        cachedResult = computation(x);
    }

    return cachedResult;
}

} //bad

namespace good {

struct CachedComputation
{
    int cachedX = 0.0;
    double cachedResult = 0.0;

    double compute(int x) {
        if (cachedX != x) {
            cachedX = x;
            cachedResult = computation(x);
        }

        return cachedResult;
    }
};

} //good

} //===========================================================================