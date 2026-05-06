#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main(void)
{
	// ===== BASIC FUNCTIONALITY =====
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Basic: ";
	std::cout << sp.shortestSpan() << " | " << sp.longestSpan() << std::endl;

	// ===== EDGE CASE: ONLY 2 ELEMENTS =====
	Span two(2);
	two.addNumber(10);
	two.addNumber(20);

	std::cout << "Two elements: ";
	std::cout << two.shortestSpan() << " | " << two.longestSpan() << std::endl;

	// ===== RANGE INSERT TEST =====
	std::vector<int> v;
	v.push_back(100);
	v.push_back(105);
	v.push_back(110);

	Span range(5);
	range.addNumber(1);
	range.addNumber(2);
	range.addNumber(v.begin(), v.end());

	std::cout << "Range insert: ";
	std::cout << range.shortestSpan() << " | " << range.longestSpan() << std::endl;

	// ===== LARGE DATA (STRESS LIGHT) =====
	Span big(10000);
	for (int i = 0; i < 10000; i++)
		big.addNumber(i);

	std::cout << "Big: ";
	std::cout << big.shortestSpan() << " | " << big.longestSpan() << std::endl;

	// ===== EXCEPTIONS =====
	try
	{
		Span empty(5);
		empty.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "Empty: " << e.what() << std::endl;
	}

	try
	{
		Span one(5);
		one.addNumber(42);
		one.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "One element: " << e.what() << std::endl;
	}

	try
	{
		Span full(2);
		full.addNumber(1);
		full.addNumber(2);
		full.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << "Overflow: " << e.what() << std::endl;
	}

	try
	{
		Span range_fail(3);
		std::vector<int> tmp;
		tmp.push_back(1);
		tmp.push_back(2);
		tmp.push_back(3);
		tmp.push_back(4);

		range_fail.addNumber(tmp.begin(), tmp.end());
	}
	catch (std::exception &e)
	{
		std::cout << "Range overflow: " << e.what() << std::endl;
	}

	return 0;
}