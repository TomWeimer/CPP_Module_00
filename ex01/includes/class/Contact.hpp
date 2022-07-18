// Copyright 2022 Tom Weimer
#ifndef EX01_INCLUDES_CLASS_CONTACT_HPP_
#define EX01_INCLUDES_CLASS_CONTACT_HPP_

# include <iostream>
# include <ios>
# include <limits>
# include <string>
#include <cstdlib>

# define MSG_CONTACT_INDEX "No contact has this index, please try again."

class Contact {
 private:
    std::string   firstName_;
    std::string   lastName_;
    std::string   nickName_;
    std::string   phoneNumber_;
    std::string   darkestSecret_;

 public:
  // Constructors
    Contact();
    Contact(const Contact&);
  // operators
    Contact &operator=(const Contact &);
  // getters
    std::string   get_firstName(void)const   { return (this->firstName_);}
    std::string   get_lastName(void)const    { return (this->lastName_);}
    std::string   get_nickName(void)const    { return (this->nickName_);}
    std::string   get_phoneNumber(void)const { return (this->phoneNumber_);}
    std::string   get_secret(void)const      { return (this->darkestSecret_);}
  // functions
    Contact    &setContact(void);
    void       writeInfo(std::string&);
  // destructors
    ~Contact();
};

std::ostream    &operator<<(std::ostream &out, Contact const &contact);

#endif  // EX01_INCLUDES_CLASS_CONTACT_HPP_
