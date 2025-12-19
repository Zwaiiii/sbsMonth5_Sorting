#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void ShellSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	ShellSort(array, 10);
}

void ShellSort(int* pNum, int num)
{
	Show(pNum, num);
	
	int gap = num / 2;
	while (true) {
		for (int i = 0; i < gap; i++) {
			for (int j = i; j < num; j += gap) {
				int sort = j + gap;
				while (sort >= 0 && sort < num && (pNum[sort - gap] > pNum[sort])) {
					SWAP(pNum[sort - gap], pNum[sort]);
					sort -= gap;
				}
			}
		}
		if (gap != 1) {
			gap /= 2;
			if (gap % 2 == 0) gap++;
		}
		else break;
	}

	Show(pNum, num);
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}

