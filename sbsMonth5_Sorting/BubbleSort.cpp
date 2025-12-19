#include<iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void BubbleSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,6,9 };
	BubbleSort(array, 10);
}

void BubbleSort(int* pArray, int num)
{
	Show(pArray, num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if(pArray[j] > pArray[j + 1]) SWAP(pArray[j], pArray[j + 1]);
		}
	}
	Show(pArray, num);
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}

