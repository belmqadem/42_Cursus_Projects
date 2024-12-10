#include "../inc/PhoneBook.hpp"

int	main(int ac, char **av)
{
	PhoneBook	phonebook;
	Contact		contact;

	if (ac != 1 || !(*av))
	{
		std::cout << RED "Usage: ./phonebook" RESET << std::endl;
		return (1);
	}
	while (1)
	{
		std::string	command;
		std::cout << BOLD_CYAN "Enter a command: " RESET;
		if (!std::getline(std::cin, command))
				break ;
		if (command == "ADD") {
			std::string	input;
			do {
				std::cout << "First Name: ";
				if (!std::getline(std::cin, input)) {
					exit(0) ;
				}
			} while (!contact.SetFirstName(input));
			do {
				std::cout << "Last Name: ";
				if (!std::getline(std::cin, input)) {
					exit(0) ;
				}
			} while (!contact.SetLastName(input));
			do {
				std::cout << "Nickname: ";
				if (!std::getline(std::cin, input)) {
					exit(0) ;
				}
			} while (!contact.SetNickname(input));
			do {
				std::cout << "Phone Number: ";
				if (!std::getline(std::cin, input)) {
					exit(0) ;
				}
			} while (!contact.SetPhoneNumber(input));
			do {
				std::cout << "Darkest Secret: ";
				if (!std::getline(std::cin, input)) {
					exit(0) ;
				}
			} while (!contact.SetDarkestSecret(input));
			phonebook.AddContact(contact);
			std::cout << GREEN "++ Contact added successfully ++" RESET << std::endl;
		}
		else if (command == "SEARCH") {
			if (!phonebook.DisplayContacts())
				continue;
			else {
				int index;
				std::string indexInput;
				while (true) {
					std::cout << MAGENTA "Enter index of contact to display: " RESET;
					if (!std::getline(std::cin, indexInput)) {
						exit(0) ;
					}
					std::istringstream iss(indexInput);
					if (iss >> index) {
						if (index >= 0 && index < phonebook.GetContactCount()) {
							phonebook.DisplayContact(index);
							break;
						} else {
							std::cout << RED "Invalid index." RESET << std::endl;
						}
					} else {
							std::cout << RED "Invalid index." RESET << std::endl;
					}
				}
			}
		}
		else if (command == "EXIT") {
			std::cout << BLUE "Exiting..." RESET << std::endl;
			break ;
		}
		else {
			std::cout << RED "Invalid input." RESET << std::endl;
		}
	}
	return (0);
}
