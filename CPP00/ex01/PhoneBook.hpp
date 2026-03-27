#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
private:
	Contact contacts[8];
	int total_contacts;
	int current_index;

public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
	int getTotalContacts() const;
};

#endif