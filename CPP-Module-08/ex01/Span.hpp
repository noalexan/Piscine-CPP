#pragma once

#include <iostream>
#include <vector>

class Span {

	private:
		Span();

		unsigned int		_lenght_max;
		unsigned int		_lenght;
		std::vector<int>	_array;

	public:
		Span(const unsigned int);
		Span(Span const &);
		~Span();

		Span	&operator=(Span const &);

		class MaxLenghtException: public std::exception {
			public:
				const char *	what() const throw() {
					return "You've hit the max lenght";
				}
		};

		class CannotFindDistanceException: public std::exception {
			public:
				const char *	what() const throw() {
					return "You must to have at least 2 int to get distance";
				}
		};

		void	addNumber(const int);
		void	Le_meilleur_pour_la_fin_Une_possibilité_qu_il_serait_utile_d_avoir_c_est_celle_de_pouvoir_remplir_votre_Span_en_utilisant_une_plage_d_itérateurs(std::vector<int>);
		void	Le_meilleur_pour_la_fin_Une_possibilité_qu_il_serait_utile_d_avoir_c_est_celle_de_pouvoir_remplir_votre_Span_en_utilisant_une_plage_d_itérateurs(std::vector<int>::iterator, std::vector<int>::iterator);
		int		shortestSpan();
		int		longestSpan();

		// void	print();

};
