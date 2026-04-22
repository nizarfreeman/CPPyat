#include "Base.hpp"
#include "iostream"
#include <ctime>

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

int main(void)
{
	std::srand(std::time(NULL));
	{
		Base *b = generate();
		std::cout<<std::endl;
		identify(b);
		std::cout<<std::endl;
		identify(*b);

		delete b;
	}
	std::cout<<"========================================================="<<std::endl;
	{
		Base *b = new Wrong();
		std::cout<<std::endl;
		identify(b);
		std::cout<<std::endl;
		identify(*b);

		delete b;
	}
}
