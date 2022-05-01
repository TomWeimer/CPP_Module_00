#ifndef MAIN_H
# define MAIN_H

# define NONE	0
# define ADD	10
# define SEARCH	11
# define EXIT	12
# define MSG_WAITING "Enter an action: "
# define MSG_NONE	"No action correspond to this"

# include <iostream>
using namespace std;

# include "Contact.hpp"
# include "PhoneBook.hpp"
# include "Queue.hpp"
void selectContact(class Queue *record);
void print(const char *message, char separator = '\n');
void printContact(Contact *info, int index);
int main(void);
void PhoneBookLoop(PhoneBook phoneBook);
int getAction(void);
void manageAction(int action, PhoneBook phonebook);
void clearAll(Queue	*record);

#endif