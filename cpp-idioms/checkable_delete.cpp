#include "deleter.hpp"
#include "object.hpp"
#include <functional>

class Empty;

template<class T>
inline void checked_delete(T* p)
{
    typedef char type_must_be_completed[sizeof(T) ? 1 : -1];
    (void)sizeof(type_must_be_completed);
    delete p;
}

template<class T>
struct checked_deleter : std::unary_function<T*, void>
{
    void operator()(T* p) const
    {
        //boost::checked_delete(x);
    }
};

int test_checkable_delete()
{
    Object* p = new Object;
    delete_object(p);

    Empty* e = new Empty;
    delete_object(e);

    return 0;
}