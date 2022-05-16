// Copyright 2022 Tom Weimer

#include "class/PhoneBook.hpp"

// Default constructor
PhoneBook::PhoneBook() : nb_contact(0) {
    // std::cout << "Constructor called" << std::endl;
}

// Default destructor
PhoneBook::~PhoneBook() {
    // std::cout << "Destructor called" << std::endl;
}

// Add a new contact in the phoneBook
void PhoneBook::add(void) {
    int nb;

    if (this->nb_contact == 8) {
        for (int i = 0; i < 7; i++)
            this->registeredContact[i] = this->registeredContact[i + 1];
        this->registeredContact[7].setContact();
    } else {
        this->nb_contact += 1;
        nb = this->nb_contact - 1;
        this->registeredContact[nb].setContact();
    }
}

// Display contacts registered
void PhoneBook::search(void) {
    if (this->nb_contact <= 0)
        std::cout << "The phonebook is empty!"<< std::endl;
    else
        this->displayContacts();
}

// Exit the programm
void PhoneBook::exit(void) {
    this->~PhoneBook();
}
