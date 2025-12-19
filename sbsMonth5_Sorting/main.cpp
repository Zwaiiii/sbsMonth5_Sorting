#include "priority_Queue.h"

int main()
{
	priority_Queue pq;
	pq.insert(3, 3);
	pq.insert(5, 5);
	pq.insert(1, 2);
	pq.insert(7, 6);
	pq.insert(6, 4);

	pq.front();
	pq.pop();
	pq.front();
}
