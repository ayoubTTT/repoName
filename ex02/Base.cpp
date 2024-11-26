#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base * generate(void)
{
    srand(time(0));
    int i = rand() % 3;

    if (i == 0)
    {
        A *a = new A;
        return dynamic_cast<Base *>(a);
    }
    else if (i == 1)
    {
        B *b = new B;
        return dynamic_cast<Base *>(b);
    }
    C *c = new C;
    return dynamic_cast<Base *>(c);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "the actual type: A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "the actual type: B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "the actual type: C" << std::endl;
}

void identify(Base& p)
{
    try{
        dynamic_cast<A&>(p);
        std::cout << "the actual type: A" << std::endl;
    }
    catch (const std::exception &e)
    {}

    try{
        dynamic_cast<B&>(p);
        std::cout << "the actual type: B" << std::endl;

    }
    catch (const std::exception &e)
    {}

    try{
        dynamic_cast<C&>(p);
        std::cout << "the actual type: C" << std::endl;
    }
    catch (const std::exception &e)
    {}
    
}