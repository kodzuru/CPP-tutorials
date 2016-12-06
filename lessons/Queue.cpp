#include "Queue.h"
using namespace std;

Queue::Queue()
{
	begin = NULL;
}

Queue::~Queue()
{
	
	while (begin != NULL)
	{
		queue *pv = begin;
		begin = begin->next;
		delete pv;
	}
	
}

void Queue::push(A2 d)
{

	queue *p = new  queue;
	p->a.key = d.key;
	p->next = NULL;


	if (begin == NULL) // создание первого элемента
	{
		begin = p; // указатель на начало
		(begin)->back = NULL; // элемент до первого не существует поэтому NULL
	}
	else // если очередь не пуста то : ...
		while (1)
		{
			if ((begin)->next == NULL) // если следующего элемента не существует
			{
				begin->next = p;
				break;
			}
			queue* temp = begin; //временный указатель на начало предыдущего элемента
			begin = (begin)->next; // указатель на следующий элемент
			(begin)->back = temp; // закидываем указатель на предыдущий элемент в поле структуры back
		}

	while (1) // возвращаемся назад
	{
		if (begin->back == NULL)
			break;
		begin = begin->back;
	}
}
int Queue::pop()
{
	int temp = begin->a.key;
	queue *pv = begin;
	begin = begin->next;
	delete pv;
	return temp;
}