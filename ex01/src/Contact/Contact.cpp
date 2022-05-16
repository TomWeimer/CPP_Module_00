// Copyright 2022 Tom Weimer

#include "class/Contact.hpp"

// Default constructor
Contact::Contact() {
    std::cout << "Constructor called" << std::endl;
    this->firstName_ = "";
    this->lastName_ = "";
    this->nickName_ = "";
    this->phoneNumber_ = "";
    this->darkestSecret_ = "";
}

// Copy constructor
Contact::Contact(const Contact &origin) {
    std::cout << "Copy constructor called" << std::endl;
    this->firstName_ = origin.get_firstName();
    this->lastName_ = origin.get_lastName();
    this->nickName_ = origin.get_nickName();
    this->phoneNumber_ = origin.get_phoneNumber();
    this->darkestSecret_ = origin.get_secret();
}

// Assignement operator
Contact& Contact::operator=(const Contact& origin) {
    std::cout << "Assignement operator called" << std::endl;
    if (this == &origin)
        return (*this);
    this->firstName_ = origin.get_firstName();
    this->lastName_ = origin.get_lastName();
    this->nickName_ = origin.get_nickName();
    this->phoneNumber_ = origin.get_phoneNumber();
    this->darkestSecret_ = origin.get_secret();
    return (*this);
}

// Check if the str is contain only space or tab
bool isEmpty(std::string const &str) {
    if (str.find_first_not_of(' ') != std::string::npos) {
        if (str.find_first_not_of('\t') != std::string::npos)
            return (false);
    }
    return (true);
}

// Get str from the user
std::string getStr(const char *message) {
    std::string str;

    str = "";
    if (message != NULL)
        std::cout << message;
    while (isEmpty(str)) {
        getline(std::cin, str);
    }
    return (str);
}

// Set the information of the contact
Contact &Contact::setContact(void) {
    std::cout << "Please, enter the contact information:" << std::endl;
    this->firstName_ = getStr("first name: ");
    this->lastName_ = getStr("last name: ");
    this->nickName_ = getStr("nick name: ");
    this->phoneNumber_ = getStr("phone number: ");
    this->darkestSecret_ = getStr("secret: ");
    return (*this);
}

// Default destructor
Contact::~Contact() {
    std::cout << "Destructor called" << std::endl;
}

// << operator
std::ostream    &operator<<(std::ostream &out, Contact const &contact) {
    out << "first name: "<< contact.get_firstName() << std::endl;
    out << "last name: " << contact.get_lastName() << std:: endl;
    out << "nick name: " << contact.get_nickName() << std::endl;
    out << "phone number: " << contact.get_phoneNumber() << std::endl;
    out << "darkest secret: " << contact.get_secret() << std::endl;
    return (out);
}
