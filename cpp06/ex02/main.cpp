#include "Base.hpp"
#include "iostream"

Base *generate(void)
{
	int	r;
 
	r = std::rand() % 3;
	if (r == 0)
	{
		std::cout<<"Generated: A"<<std::endl;
		return (new A());
	}
	else if (r == 1)
	{
		std::cout<<"Generated: B"<< std::endl;
		return (new B());
	}
	else
	{
		std::cout<<"Generated: C"<<std::endl;
		return (new C());
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout<<"A"<<std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout<<"B"<<std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout<<"C"<<std::endl;
	else
		std::cout<<"Unknown type"<< std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout<<"A"<<std::endl;
		return ;
	}
	catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout<<"B"<<std::endl;
		return ;
	}
	catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout<<"C"<<std::endl;
		return ;
	}
	catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
	std::cout<<"Unknown type"<<std::endl;
}


class Wrong : public Base {};

int main(void)
{
    std::cout << "--- Test with random instance ---" << std::endl;

	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	std::cout << std::endl << "--- Test with Wrong ---" << std::endl;
	Wrong wrong;
	identify(&wrong);
	identify(wrong);

	std::cout << std::endl << "--- Test with NULL ---" << std::endl;
	Base *null = NULL;
	identify(null);
    return 0;
}
