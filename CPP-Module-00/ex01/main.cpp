
#include <iomanip>
#include "PhoneBook.hpp"

bool ft_isdigit(std::string s) {
	int i = -1;

	if (!s[0])
		return false;
	if (s[++i])
		if (!isdigit(s[i]))
			return false;
	return true;
}

int main() {
	PhoneBook phoneBook;
	std::string	command;

	while (std::getline(std::cin, command)) {

		if (command == "EXIT")
			break;

		if (command == "ADD") {
			
			// Add a contact to the list

			Contact newContact;

			std::string firstName;
			std::cout << "First Name:	";
			std::getline(std::cin, firstName);
			newContact.setFirstName(firstName);

			std::string lastName;
			std::cout << "Last Name:	";
			std::getline(std::cin, lastName);
			newContact.setLastName(lastName);

			std::string nickname;
			std::cout << "NickName:	";
			std::getline(std::cin, nickname);
			newContact.setNickName(nickname);

			std::string phoneNumber;
			std::cout << "Phone Number:	";
			std::getline(std::cin, phoneNumber);
			newContact.setPhoneNumber(phoneNumber);

			std::string darkestSecret;
			std::cout << "Darkest Secret:	";
			std::getline(std::cin, darkestSecret);
			newContact.setDarkestSecret(darkestSecret);

			phoneBook.add(newContact);

		}

		if (command == "SEARCH") {

			// Search a contact in the list

			std::cout << "|==========|==========|==========|==========|" << std::endl;
			std::cout << "|        id|First Name| Last Name|  NickName|" << std::endl;
			std::cout << "|==========|==========|==========|==========|" << std::endl;
			
			for (int j = 0; j < 8; j++) {
				Contact *contact = phoneBook.getContact(j);

				if (contact) {
					std::string firstName(contact->getFirstName());
					std::string lastName(contact->getLastName());
					std::string nickname(contact->getNickName());

					if (firstName.length() > 10)
						firstName = firstName.substr(0, 9).append(".");
					if (lastName.length() > 10)
						lastName = lastName.substr(0, 9).append(".");
					if (nickname.length() > 10)
						nickname = nickname.substr(0, 9).append(".");

					std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << j << "|" << std::setw(10) << std::setfill(' ') << std::right << firstName << "|" << std::setw(10) << std::setfill(' ') << std::right << lastName << "|" << std::setw(10) << std::setfill(' ') << std::right << nickname << "|" << std::endl;
				}

			}

			std::cout << "|==========|==========|==========|==========|" << std::endl << std::endl;
			
			// Prompt an id to know which contact the user is searching
			std::string	id;
			Contact *target;
			std::cout << "WHICH ONE YOU WANT TO VIEW ? ";
			
			if (std::getline(std::cin, id) && ft_isdigit(id)) {
				int _id = std::stoi(id);
				
				if (_id >= 0 && _id < 8) {
					target = phoneBook.getContact(_id);
				
					if (target) {
						std::cout << "First Name:	" << target->getFirstName() << std::endl;
						std::cout << "Last Name:	" << target->getLastName() << std::endl;
						std::cout << "NickName:	" << target->getNickName() << std::endl;
						std::cout << "Phone Number:	" << target->getPhoneNumber() << std::endl;
						std::cout << "Darkest Secret:	" << target->getDarkestSecret() << std::endl;
					}

				}
			}

		}

	}

	return 0;
}
