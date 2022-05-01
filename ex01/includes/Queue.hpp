#ifndef QUEUE_H
# define QUEUE_H

# include "main.hpp"
class QNode
{
	public:
	class Contact	*item;
	class QNode		*next;
	QNode();
};

class Queue
{
	public:
	int			size;
	class QNode	*front;
	class QNode	*rear;
	void	enQueue(void);
	void	deQueue(void);
//	contructor:
	Queue();
};
#endif

