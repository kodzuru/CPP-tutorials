#include "Stack.h"

using namespace std;

Stack::Stack()
{
	next = NULL;
}
Stack::~Stack()
{
	while (next != NULL)
	{
		List *pv = next;
		next = next->next;
		delete pv;
	}
}


void Stack::push(A1 d)
{
	List* pv = new List;
	pv->a.key = d.key;
	pv->next = next;
	next = pv;
}
int Stack::pop() {
	int temp = next->a.key;
	List* pv = next;
	next = next->next;
	return temp;
}