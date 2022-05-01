#include "main.hpp"

//contructor
PhoneBook::PhoneBook()
{
	record = new Queue;
}

void PhoneBook::ft_add(class Queue *record)
{
	if (record->size < 8)
	{
		record->enQueue();
	}
	else
	{
		record->deQueue();
		record->enQueue();
	}
}

void PhoneBook::ft_search(class Queue *queue_)
{
	QNode *actual;
	int index;

	index = 0;
	actual = queue_->front;
	if (queue_->size > 0)
	{
		cout << " -------------------------------------------" << endl;
		cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << endl;
		cout << " -------------------------------------------" << endl;

		while (actual != NULL)
		{
			index++;
			printContact(actual->item, index);
			actual = actual->next;
		}
		cout << " -------------------------------------------\n" << endl;
		selectContact(queue_);
	}
	else
		cout << "NO contact!" << endl;
}

void PhoneBook::ft_exit(class Queue *queue_)
{
	while (queue_->size > 0)
	{
		queue_->deQueue();
	}
	delete queue_;
	return ;
}

