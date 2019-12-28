#include <iostream>
#include <vector>

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heapify(std::vector<int>& arr, int n, int i)
{
	int largest = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < n && arr[right] < arr[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		Swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void Sort(std::vector<int>& arr, int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
	{
		Heapify(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		Swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

int main()
{
	std::vector<int> arr = { 5, 12, 9, -1, 312, 19, 4, -45, 74, 0 };
	Sort(arr, arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}