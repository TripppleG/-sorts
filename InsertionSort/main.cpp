#include <iostream>

void InsertionSort(int* arr, int len)
{
	for (int i = 1; i < len; i++)
	{
		int element = arr[i];
		int index = i - 1;
		while (index >= 0 && arr[index] > element)
		{
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = element;
	}
}


int main()
{
	int arr[10] = { 14, 36, 435, 6, 43, 1, 53, -45, 0, 65 };
	InsertionSort(arr, 10);
}