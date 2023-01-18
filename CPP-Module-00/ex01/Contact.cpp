#include "Contact.hpp"

void Contact::setFirstName(const std::string _firstName) { firstName = _firstName; }
void Contact::setLastName(const std::string _lastName) { lastName = _lastName; }
void Contact::setNickName(const std::string _nickname) { nickname = _nickname; }
void Contact::setPhoneNumber(const std::string _phoneNumber) { phoneNumber = _phoneNumber; }
void Contact::setDarkestSecret(const std::string _darkestSecret) { darkestSecret = _darkestSecret; }

std::string Contact::getFirstName() { return firstName; }
std::string Contact::getLastName() { return lastName; }
std::string Contact::getNickName() { return nickname; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getDarkestSecret() { return darkestSecret; }
