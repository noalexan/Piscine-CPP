
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { i = 0; added = 0; }

Contact *PhoneBook::getContact(int id) { if (id < 8 && id < added) return &contacts[id]; return NULL; }

void PhoneBook::add(Contact newContact) {
	contacts[i] = newContact;
	i++;
	added++;
	if (i == 8)
	i = 0;
}
