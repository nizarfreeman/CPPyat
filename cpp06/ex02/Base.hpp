#ifndef BASE
# define BASE
# include <iostream>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif