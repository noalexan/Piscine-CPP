#include "Span.hpp"

int main()
{
	Span test(2);

	test.addNumber(42);
	test.addNumber(43);

	std::cout << std::endl << "Trying to add more number than there is stock" << std::endl;
	try { test.addNumber(44); }
	catch(const std::exception &e) { std::cerr << e.what() << '\n'; }

	std::cout << std::endl << "---ASSIGNMENT TESTS---" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Test with 10 000 numbers" << std::endl;

	int values[10000];

	for (int i = 0; i < 10000; i++) { values[i] = i; }

	std::vector<int> vect(values, values + sizeof(values) / sizeof(int));

	Span test2(10000);

	test2.Le_meilleur_pour_la_fin_Une_possibilité_qu_il_serait_utile_d_avoir_c_est_celle_de_pouvoir_remplir_votre_Span_en_utilisant_une_plage_d_itérateurs(vect.begin(), vect.end());

	std::cout << test2.shortestSpan() << std::endl;
	std::cout << test2.longestSpan() << std::endl;

	Span test3(1);

	test3.addNumber(42);

	std::cout << std::endl;
	std::cout << "Trying to find shortest span on small arrays" << std::endl;

	try { std::cout << test3.shortestSpan() << std::endl; }
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { std::cout << test3.longestSpan() << std::endl; }
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

	std::cout << std::endl;
	std::cout << "Trying to overflow the array using another big one" << std::endl;

	try { test3.Le_meilleur_pour_la_fin_Une_possibilité_qu_il_serait_utile_d_avoir_c_est_celle_de_pouvoir_remplir_votre_Span_en_utilisant_une_plage_d_itérateurs(vect.begin(), vect.end()); }
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

	std::cout << std::endl;

	return 0;
}