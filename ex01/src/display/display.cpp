// Copyright 2022 Tom Weimer

#include "class/Contact.hpp"
#include "class/PhoneBook.hpp"

// Columns header
void displayHeader(void) {
    std::cout << " ------------------------------------------- \n";
    std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|\n";
    std::cout << " ------------------------------------------- \n";
}

// Useless, only for the sake of beauty
void displayFooter(void) {
    std::cout << " ------------------------------------------- \n";
}

// Shrink info to fit MAX_WIDTH and add a '.'
std::string shrinkInfo(std::string info) {
    std::string copy;

    copy = info;
    copy.resize(MAX_WIDTH - 1);
    //copy.shrink_to_fit();
    copy.insert(copy.length(), 1, '.');
    return (copy);
}

// Enlarge info with space to reach MAX_WIDTH
std::string enlargeInfo(std::string info) {
    std::string copy;

    copy.insert(0, MAX_WIDTH - info.length(), ' ');
    copy += info;
    return (copy);
}

// Check if the size is bigger than the MAX_WIDTH(10)
std::string getInfo(std::string info) {
    if (info.length() > 10)
    return (shrinkInfo(info));
    else
    return (enlargeInfo(info));
}

// Select an available index
int selectIndex(int nb_contact) {
    bool end;
    int returnIndex;

    end = false;
    returnIndex = 0;
    std::cout << "Select the index of the desired contact: ";
    while (end == false) {
		returnIndex = 0;
       	std::cin >> returnIndex;
		if (std::cin.fail())
		{
			std::cout << MSG_CONTACT_INDEX << std::endl;
			std::cout << "Select the index of the desired contact: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			returnIndex = -1;
		}
		else
		{
        	if ((returnIndex >= 1 && returnIndex <= 8) && returnIndex <= nb_contact)
        		end = true;
        	if (end == false) {
        		std::cout << MSG_CONTACT_INDEX << std::endl;
				std::cout << "Select the index of the desired contact: ";
        		std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	}
		}
    }
    return (returnIndex);
}

// Select a contact and display his information
void PhoneBook::selectContact(void) {
    int contactChosen;

    contactChosen = selectIndex(this->nb_contact);
    std::cout << this->registeredContact[contactChosen - 1] << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// display the first three information of the contact in column
void displayLines(const Contact &contact, int index) {
    std::string line;

    line = "|";
    for (int i = 0; i < 9; i++)
    line += ' ';
    line += static_cast<char> (index + '0' + 1);
    line += "|";
    line += getInfo(contact.get_firstName());
    line += '|';
    line += getInfo(contact.get_lastName());
    line += '|';
    line += getInfo(contact.get_nickName());
    line += '|';
    std::cout << line << std::endl;
}

// Manage the outup of the contacts informations
void PhoneBook::displayContacts(void) {
    displayHeader();
    for (int i = 0; i < this->nb_contact; i++) {
        displayLines(this->registeredContact[i], i);
    }
    displayFooter();
    this->selectContact();
}
