#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void MergeSort(int* pNum, int left, int right);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 4,2,8,6,0,5,1,7,3,9 };
	Show(array, 10);
	MergeSort(array, 0, 9);
	Show(array, 10);
}

void MergeSort(int* pNum, int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right) {
		MergeSort(pNum, left, mid);
		MergeSort(pNum, mid + 1, right);
		int* temp = new int[right - left + 1];
		int l = left;
		int r = mid + 1;
		for (int i = 0; i <= right - left; i++) {
			if (l <= mid && r <= right) {
				if (pNum[l] < pNum[r]) {
					temp[i] = pNum[l];
					l++;
				}
				else {
					temp[i] = pNum[r];
					r++;
				}
			}
			else if (l > mid) {
				temp[i] = pNum[r];
				r++;
			}
			else {
				temp[i] = pNum[l];
				l++;
			}
		}
		for (int i = 0; i < right - left + 1; i++) pNum[left + i] = temp[i];	
	}

}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}

