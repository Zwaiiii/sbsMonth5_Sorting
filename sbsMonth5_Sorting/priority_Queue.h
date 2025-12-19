#pragma once
#include <vector>
#include <iostream>
#define SWAP(a,b) {pair<int, int> temp; temp = a; a = b; b = temp;}

using namespace std;

class priority_Queue
{
private:
	vector<pair<int,int>> heap;
	int size = 0;
public:
	void insert(int priority, int data);
	void pop();
	void front();
public:
	priority_Queue();
	~priority_Queue();
};

