#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "../inc/colors.hpp"

class Contact {
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		bool SetFirstName(const std::string name);
		bool SetLastName(const std::string name);
		bool SetNickname(const std::string name);
		bool SetPhoneNumber(const std::string number);
		bool SetDarkestSecret(const std::string secret);
		std::string GetFirstName(void) const;
		std::string GetLastName(void) const;
		std::string GetNickname(void) const;
		std::string GetPhoneNumber(void) const;
		std::string GetDarkestSecret(void) const;
};

#endif
