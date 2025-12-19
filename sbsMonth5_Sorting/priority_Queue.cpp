#include "priority_Queue.h"

void priority_Queue::insert(int priority, int data)
{
	heap.push_back(make_pair(priority, data));
	size++;
	int end = size - 1;
	while (end != 1) {
		if (heap[end / 2].first < heap[end].first) {
			SWAP(heap[end / 2], heap[end]);
			end = end / 2;
		}
		else break;
	}
}

void priority_Queue::pop()
{
	cout << heap[1].second << "\n";
	SWAP(heap[1], heap[size - 1]);
	heap.pop_back(); size--;

	int it = 1;
	while (it * 2 < size) {
		if (it * 2 < size && it * 2 + 1 <= size) {
			if (heap[it * 2].first < heap[it * 2 + 1].first)
			{
				if (heap[it].first < heap[it * 2 + 1].first) {
					SWAP(heap[it], heap[it * 2 + 1]);
					it = it * 2 + 1;
				}
				else break;
			}
			else
				if (heap[it].first < heap[it * 2].first) {
					SWAP(heap[it], heap[it * 2]);
					it = it * 2;
				}
				else break;
		}
		else if (it * 2 <= size) {
			if (heap[it].first < heap[it * 2].first) {
				SWAP(heap[it], heap[it * 2]);
				it = it * 2;
			}
			else break;
		}
	}
}

void priority_Queue::front()
{
	cout << heap[1].second << "\n";
}

priority_Queue::priority_Queue()
{
	heap.resize(1);
}

priority_Queue::~priority_Queue()
{
}
