#pragma once

#include <iostream>
#include <stack>

template <typename _T, class _Allocator = std::deque<_T> >
class MutantStack: public std::stack<_T, _Allocator> {

	public:
		MutantStack() {}
		MutantStack(const MutantStack &copy) { for (iterator it = copy.begin(); it != copy.end(); it++) push(*it); }
		~MutantStack() {}

		MutantStack &	operator=(const MutantStack &copy) {
			std::stack<_T, _Allocator>().swap(this);
			for (iterator it = copy.begin(); it != copy.end(); it++) push(*it);
		}

		typedef typename std::stack<_T, _Allocator>::container_type::iterator iterator;

		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }

};
