
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook();
		Contact *getContact(int id);
		void add(Contact newContact);

	private:
		Contact contacts[8];
		int	i;
		int	added;

};

#endif
