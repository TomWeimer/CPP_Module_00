#include "main.hpp"

int main(void)
{
	PhoneBook	phoneBook;

	PhoneBookLoop(phoneBook);
	clearAll(phoneBook.record);
}

void PhoneBookLoop(PhoneBook phoneBook)
{
	int	action;

	do
	{
		action = getAction();
		if (action != EXIT)
			manageAction(action, phoneBook);
	}
	while (action != EXIT);
}

int getAction(void)
{
	string buffer;

	print(MSG_WAITING);
	cin >> buffer ;
	if (buffer.compare("ADD") == 0)
		return (ADD);
	else if (buffer.compare("SEARCH") == 0)
		return (SEARCH);
	else if (buffer.compare("EXIT") == 0)
		return (EXIT);
	return (NONE);
	
}

void manageAction(int action, PhoneBook phonebook)
{
	if (action == ADD)
		phonebook.ft_add(phonebook.record);
	else if (action == SEARCH)
		phonebook.ft_search(phonebook.record);
	else if (action == NONE)
		print(MSG_NONE);
}

void clearAll(Queue	*record)
{
	QNode *actual;
	QNode *to_delete;

	actual = (*record).front;
	while (actual != NULL)
	{
		to_delete = actual;
		actual = actual->next;
		delete(to_delete->item);
		delete(to_delete);
	}
	delete(record);
}
