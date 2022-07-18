// Copyright 2022 Tom Weimer

#include "class/Contact.hpp"
#include "class/PhoneBook.hpp"

int main() {
    PhoneBook      phoneBook;
    std::string   input;
    bool           end;

    end = false;
    while (end == false) {
        std::cout << "Enter a command:";
        getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nexit" << std::endl;
			std::exit(EXIT_FAILURE);
		}
        if (input.compare("ADD") == 0)
            phoneBook.add();
        else if (input.compare("SEARCH") == 0)
            phoneBook.search();
        else if (input.compare("EXIT") == 0)
           end = true;
        else
           std::cout <<"No command found: \"" << input <<"\""<< std::endl;
    }
    phoneBook.exit();
    return (0);
}
