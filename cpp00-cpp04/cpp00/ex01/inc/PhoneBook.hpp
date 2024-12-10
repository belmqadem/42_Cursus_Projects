#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact		Contacts[8];
		int			Count;
		int			Index;
		std::string	Truncate(const std::string str) const;
	public:
		PhoneBook();
		void	AddContact(const Contact contact);
		bool	DisplayContacts(void) const;
		void	DisplayContact(int index) const;
		int		GetContactCount(void) const;
};

#endif
