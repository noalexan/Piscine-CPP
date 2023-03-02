#include <iostream>

typedef struct s_data {
	int	value;
}	Data;

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int	main() {

	Data	a;
	a.value = 101;

	std::cout << a.value << std::endl;

	uintptr_t	b = serialize(&a);

	std::cout << b << std::endl;
	std::cout << deserialize(b)->value << std::endl;

	return 0;

}
