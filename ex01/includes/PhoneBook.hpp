#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "main.hpp"

class PhoneBook
{
	public:
	void	ft_add(class Queue *queue_);
	void	ft_search(class Queue *queue_);
	void	ft_exit(class Queue *queue_);
	class	Queue	*record;
	PhoneBook();
};
#endif