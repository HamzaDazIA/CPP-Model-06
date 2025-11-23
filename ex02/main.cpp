#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


Base * generate(void)
{
    unsigned int rs  = std::rand() % 3;

    if (rs == 1)
        return (new A());
    else if (rs == 0)
        return (new B());
    else 
        return (new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "undefine type of cast" << std::endl;
}
void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...) {}
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...) {}
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...) {}
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    Base* ptr = generate();
    
    identify(ptr);
    identify(*ptr);
    
    delete ptr;
    return 0;
}