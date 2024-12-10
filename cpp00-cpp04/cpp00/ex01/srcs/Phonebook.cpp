#include "../inc/PhoneBook.hpp"

// Constructor using initializer list
PhoneBook::PhoneBook() : Count(0), Index(0) {}

// Add a contact to the phone book, replace older if necessary
void PhoneBook::AddContact(const Contact contact) {
	Contacts[Index] = contact;
	Index = (Index + 1) % 8;
	if (Count < 8) Count++;
}

// Display all contacts in the phone book (truncated to 10 characters)
bool PhoneBook::DisplayContacts() const {
	if (Count == 0) {
		std::cout << RED "Phonebook is empty." RESET << std::endl;
		return false;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < Count; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << Truncate(Contacts[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << Truncate(Contacts[i].GetLastName()) << "|";
		std::cout << std::setw(10) << Truncate(Contacts[i].GetNickname()) << std::endl;
	}
	return true;
}

// Display a contact in the phone book
void PhoneBook::DisplayContact(int index) const {
	if (index < 0 || index >= Count) {
		std::cout << RED "Please enter a valid index (digits only)." RESET << std::endl;
		return ;
	}
	std::cout << "First Name: " << Contacts[index].GetFirstName() << std::endl;
	std::cout << "Last Name: " << Contacts[index].GetLastName() << std::endl;
	std::cout << "Nickname: " << Contacts[index].GetNickname() << std::endl;
	std::cout << "Phone Number: " << Contacts[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << Contacts[index].GetDarkestSecret() << std::endl;
}

// Truncate a string to 10 characters
std::string PhoneBook::Truncate(const std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

// Return Contact Count
int	PhoneBook::GetContactCount(void) const { return Count; }
