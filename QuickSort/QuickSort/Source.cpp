#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[10] = { 1, 10, -3, 5, 0, -7, 15, 18, 9, -4 };
	QuickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}