#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const WrongAnimal* wrong = new WrongAnimal("salut");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* l = new WrongCat();

	std::cout << meta->getType() << std::endl;
	std::cout << wrong->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << l->getType() << std::endl;

	meta->makeSound();
	wrong->makeSound();
	i->makeSound();
	j->makeSound();
	l->makeSound();

	delete meta;
	delete wrong;
	delete j;
	delete i;
	delete l;

	return 0;
}
