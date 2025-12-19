#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void QuickSort(int* pNum, int left, int right);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	Show(array, 10);
	QuickSort(array, 0, 9);
	Show(array, 10);
}

void QuickSort(int* pNum, int _left, int _right)
{
	int pivot = _left;
	int left = _left + 1, right = _right;
	int check = 0;
	while (left <= right) {
		while (left <= right && pNum[pivot] <= pNum[right]) right--;
		while (left <= right && pNum[pivot] >= pNum[left]) left++;

		if (left < right) SWAP(pNum[left], pNum[right]);
	}
	SWAP(pNum[pivot], pNum[right]);
	pivot = right;
	if(_left < pivot - 1) QuickSort(pNum, _left, pivot - 1);
	if(_right > pivot + 1) QuickSort(pNum, pivot + 1, _right);
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}

