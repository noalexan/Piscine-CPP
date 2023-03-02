#pragma once

#include <iostream>

template <typename T>
class Array {

	private:
		T *				_array;
		unsigned int	_lenght;

	public:
		Array();
		Array(const unsigned int);
		Array(Array const &);
		~Array();

		Array<T>	&operator=(Array const &);
		T			&operator[](const unsigned int);
		T			operator[](const unsigned int) const;

		class OutOfRangeException: public std::exception {
			public:
				const char *	what() const throw() {
					return "Out of range access";
				}
		};

		unsigned int	size() const;

};

template <typename T>
Array<T>::Array() {
	_array = nullptr;
	_lenght = 0;
}

template <typename T>
Array<T>::Array(const unsigned int lenght) {
	_array = new T[lenght];
	_lenght = lenght;
}

template <typename T>
Array<T>::Array(Array const &other) {
	_lenght = other.size();
	_array = new T[_lenght];

	for (unsigned int i = 0; i < _lenght; i++)
		_array[i] = other[i];
}

template <typename T>
Array<T>::~Array() {}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	delete _array;

	_lenght = other.size();
	_array = new T[_lenght];

	for (unsigned int i = 0; i < _lenght; i++)
		_array[i] = other[i];

	return *this;
}

template <typename T>
T &Array<T>::operator[](const unsigned int i) {

	if (i >= _lenght)
		throw Array::OutOfRangeException();

	return _array[i];
}

template <typename T>
T Array<T>::operator[](const unsigned int i) const {

	if (i >= _lenght)
		throw Array::OutOfRangeException();

	return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _lenght;
}
