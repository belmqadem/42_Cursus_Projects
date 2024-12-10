#include "../inc/PhoneBook.hpp"

// Setters
bool Contact::SetFirstName(const std::string name) {
	FirstName = name;
	if (name.empty())
	{
		std::cerr << RED "Error: Contact fields cannot be empty." RESET << std::endl;
		return false;
	}
	return true;
}
bool Contact::SetLastName(const std::string name) {
	LastName = name;
	if (name.empty())
	{
		std::cerr << RED "Error: Contact fields cannot be empty." RESET << std::endl;
		return false;
	}
	return true;
}
bool Contact::SetNickname(const std::string name) {
	Nickname = name;
	if (name.empty())
	{
		std::cerr << RED "Error: Contact fields cannot be empty." RESET << std::endl;
		return false;
	}
	return true;
}
bool Contact::SetPhoneNumber(const std::string number) {
    for (size_t i = 0; i < number.length(); ++i) {
        if (!std::isdigit(number[i]) && number[i] != ' ' && number[i] != '\t' && number[i] != '-' && number[i] != '+') {
            std::cerr << RED "Error: Phone number can only contain digits." RESET << std::endl;
            return false;
        }
    }
	if (number.empty())
	{
		std::cerr << RED "Error: Contact fields cannot be empty." RESET << std::endl;
		return false;
	}
    PhoneNumber = number;
	return true;
}
bool Contact::SetDarkestSecret(const std::string secret) {
	DarkestSecret = secret;
	if (secret.empty())
	{
		std::cerr << RED "Error: Contact fields cannot be empty." RESET << std::endl;
		return false;
	}
	return true;
}

// Getters
std::string Contact::GetFirstName() const { return (FirstName); }
std::string Contact::GetLastName() const { return (LastName); }
std::string Contact::GetNickname() const { return (Nickname); }
std::string Contact::GetPhoneNumber() const { return (PhoneNumber); }
std::string Contact::GetDarkestSecret() const { return (DarkestSecret); }
