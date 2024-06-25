#include <iostream>
#include <functional>

using namespace std;

template<typename T, typename... Args>
struct fixpoint
{
    typedef function<T(Args...)> effective_type;
    typedef function<T(const effective_type&, Args...)> function_type;

    function_type f_nonr;

    T operator()(Args... args) const
    {
        return f_nonr(*this, args...);
    }

    fixpoint(const function_type& p_f)
        : f_nonr(p_f)
    {
    }
};


int main()
{
    auto fib_nonr = [](const function<int(int)>& f, int n) -> int
    {
        return n < 2 ? n : f(n-1) + f(n-2);
    };

    auto fib = fixpoint<int,int>(fib_nonr);

    for (int i = 0; i < 20; ++i)
    {
        cout << fib(i) << '\n';
    }
}
