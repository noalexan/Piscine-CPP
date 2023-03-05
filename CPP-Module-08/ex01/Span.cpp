#include <algorithm>
#include "Span.hpp"

Span::Span() {}

Span::Span(const unsigned int lenght_max): _lenght_max(lenght_max), _lenght(0) {}

Span::Span(Span const &other) { *this = other; }

Span::~Span() {}

Span &Span::operator=(Span const &other) {
	_lenght_max = other._lenght_max;
	_lenght = other._lenght;
	_array = other._array;
	return *this;
}

void Span::addNumber(const int number) {

	if (_lenght == _lenght_max)
		throw Span::MaxLenghtException();

	_array.push_back(number);
	_lenght++;
}

void Span::Le_meilleur_pour_la_fin_Une_possibilité_qu_il_serait_utile_d_avoir_c_est_celle_de_pouvoir_remplir_votre_Span_en_utilisant_une_plage_d_itérateurs(std::vector<int> a) {
	std::vector<int>::iterator	it = a.begin();
	while (it != a.end()) {
		addNumber(*it);
		it++;
	}
}

void Span::Le_meilleur_pour_la_fin_Une_possibilité_qu_il_serait_utile_d_avoir_c_est_celle_de_pouvoir_remplir_votre_Span_en_utilisant_une_plage_d_itérateurs(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::vector<int>::iterator	it = begin;
	while (it != end) {
		addNumber(*it);
		it++;
	}
}

int Span::shortestSpan() {
	int							shortest = INT_MAX, a;
	std::vector<int>::iterator	it2;

	if (_lenght == 0 || _lenght == 1)
		throw Span::CannotFindDistanceException();

	for (std::vector<int>::iterator it = _array.begin(); it != _array.end(); it++) {
		it2 = it;
		while (++it2 != _array.end()) {
			a = *it - *it2;
			if (a < 0) a *= -1;
			if (a < shortest) shortest = a;
		}
	}

	return shortest;
}

int Span::longestSpan() {
	int							shortest = INT_MIN, a;
	std::vector<int>::iterator	it2;

	if (_lenght == 0 || _lenght == 1)
		throw Span::CannotFindDistanceException();

	for (std::vector<int>::iterator it = _array.begin(); it != _array.end(); it++) {
		it2 = it;
		while (++it2 != _array.end()) {
			a = *it - *it2;
			if (a < 0) a *= -1;
			if (a > shortest) shortest = a;
		}
	}

	return shortest;
}

// void	Span::print() {
// 	for (std::vector<int>::iterator it = _array.begin(); it != _array.end(); it++)
// 		std::cout << *it << std::endl;
// }
