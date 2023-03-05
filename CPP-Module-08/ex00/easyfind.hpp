#pragma once

class CannotFindException: public std::exception {
	public:
		const char * what() const throw() {
			return "Cannot find value";
		}
};

template <class T>
int easyfind(T a, int b) {
	bool found = false;

	for (typename T::iterator it = a.begin(); it != a.end(); it++) {
		if (*it == b) {
			found = true;
		}
	}

	if (!found)
		throw CannotFindException();

	return b;
}
