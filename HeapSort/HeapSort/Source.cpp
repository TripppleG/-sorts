#include <iostream>

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heapify(int* arr, int n, int i)
{
	int smallest = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;

	if (l < n && arr[l] < arr[smallest])
	{
		smallest = l;
	}
	if (r < n && arr[r] < arr[smallest])
	{
		smallest = r;
	}
	if (smallest != i)
	{
		Swap(arr[i], arr[smallest]);
		Heapify(arr, n, smallest);
	}
}

void Sort(int* arr, int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
	{
		Heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		Swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

int main()
{
	int arr[10] = { 5, 12, 9, -1, 312, 19, 4, -45, 74, 0 };
	Sort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}