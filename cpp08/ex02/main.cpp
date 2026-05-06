#include "MutantStack.hpp"
#include <list>

int main(void)
{
	// ===== BASIC STACK BEHAVIOR =====
	MutantStack<int> ms;
	ms.push(5);
	ms.push(17);

	std::cout << "Top: " << ms.top() << std::endl;
	ms.pop();
	std::cout << "Size: " << ms.size() << std::endl;

	// ===== ITERATION TEST =====
	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);

	std::cout << "Iterate: ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// ===== MODIFY THROUGH ITERATOR =====
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		*it += 1;

	std::cout << "Modified: ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// ===== COPY INTO std::stack =====
	std::stack<int> s(ms);
	std::cout << "Copied stack size: " << s.size() << std::endl;

	// ===== COMPARISON WITH LIST =====
	std::list<int> lst;
    lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "List: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// ===== EDGE CASE: EMPTY ITERATION =====
	MutantStack<int> empty;
	std::cout << "Empty begin == end : " << (empty.begin() == empty.end()) << std::endl;

	return 0;
}