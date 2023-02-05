#include <cmath>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NB_OF_ANIMALS 5

void test1() {
	Animal *array[NB_OF_ANIMALS];

	// Fill the array with cats and dogs
	for (int i = 0; i < roundf((float) NB_OF_ANIMALS / 2); i++)
	{
		array[i] = new Dog();
		if (i < NB_OF_ANIMALS - i - 1)
			array[NB_OF_ANIMALS - i - 1] = new Cat();
	}

	std::cout << std::endl;

	// delete all the animals in the array
	for (int i = 0; i < NB_OF_ANIMALS; i++)
		delete(array[i]);
}

void test2() {
	Dog a;
	a.getBrain()->ideas[97] = "== ✅ ==";
	Dog b = a;
	std::cout << a.getBrain()->ideas[97] << std::endl;
	std::cout << b.getBrain()->ideas[97] << std::endl;
}

int main() {

	test1();
	std::cout << "-----------------------------------------\n";
	test2();

	return 0;
}
