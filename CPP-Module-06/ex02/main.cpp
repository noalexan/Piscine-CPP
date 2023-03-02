#include <iostream>

class Base {
	public:
		virtual ~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base::~Base() {}

Base *generate(void) {

	switch (std::rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}

	return nullptr;
}

void identify(Base *b) {

	if (dynamic_cast<A*>(b))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(b))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(b))
		std::cout << "type: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;

}

void identify(Base &b) {

	try {
		(void) dynamic_cast<A&>(b);
		std::cout << "type: A" << std::endl;
	} catch (std::exception &) {
		try {
			(void) dynamic_cast<B&>(b);
			std::cout << "type: B" << std::endl;
		} catch (std::exception &) {
			try {
				(void) dynamic_cast<C&>(b);
				std::cout << "type: C" << std::endl;
			} catch (std::exception &) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}

}

int main() {

	std::srand(std::time(nullptr));

	Base	*b = generate();
	identify(b);
	identify(*b);
	delete b;

	return 0;

}
