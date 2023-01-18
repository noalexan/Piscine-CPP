
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

	public:
		Contact() {}

		void setFirstName(const std::string _firstName);
		void setLastName(const std::string _lastName);
		void setNickName(const std::string _nickname);
		void setPhoneNumber(const std::string _phoneNumber);
		void setDarkestSecret(const std::string _darkestSecret);

		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

};

#endif
