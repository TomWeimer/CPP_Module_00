#include "main.hpp"

QNode::QNode(void)
{
	item = new Contact();
	next = NULL;
}

Queue::Queue(void)
{
	front = NULL;
	rear = NULL;
	size = 0;
}

void Queue::enQueue(void)
{
	QNode *temp;

	temp = new QNode();
	if (rear == NULL)
	{
		front = temp;
		rear = temp;
		size = 1;
		cout << "New node at end: " << temp->item << endl << "size: " << size << endl;
		return ;
	}
	rear->next = temp;
	rear = temp;
	size++;
	cout << "New node at end: " << temp->item << endl << "size: " << size << endl;
}

void Queue::deQueue(void)
{
	QNode *temp;

	if (front == NULL)
		return ;
	temp = front;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	size--;
	cout << "First node deleted:" << temp->item << endl << "size: " << size << endl;
	delete(temp->item);
	delete(temp);
	
}
