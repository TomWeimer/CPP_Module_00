// Copyright 2022 Tom Weimer

#ifndef    EX01_INCLUDES_CLASS_PHONEBOOK_HPP_
#define    EX01_INCLUDES_CLASS_PHONEBOOK_HPP_
# define   MAX_WIDTH 10
# include  "class/Contact.hpp"

class PhoneBook {
 private:
    int      nb_contact;
    class    Contact registeredContact[8];

 public:
    PhoneBook();
    void    add(void);
    void    search(void);
    void    exit(void);
    void    displayContacts();
    void    selectContact(void);
    ~PhoneBook();
};

#endif  // EX01_INCLUDES_CLASS_PHONEBOOK_HPP_
