#include <iostream>
#include <vector>

void Merge(std::vector<int>& arr, int from, int mid, int to)
{
	std::vector<int> A, B;
	for (int i = from; i <= mid; i++)
	{
		A.push_back(arr[i]);
	}
	for (int i = mid + 1; i <= to; i++)
	{
		B.push_back(arr[i]);
	}
	int i = 0;
	int j = 0;
	int pos = from;
	while (i < A.size() && j < B.size())
	{
		if (A[i] <= B[j])
		{
			arr[pos++] = A[i++];
		}
		else
		{
			arr[pos++] = B[j++];
		}
	}
	while (i < A.size())
	{
		arr[pos++] = A[i++];
	}
	while (j < B.size())
	{
		arr[pos++] = B[j++];
	}
}

void MergeSort(std::vector<int>& arr, int from, int to)
{
	if (from < to)
	{
		int mid = (from + to) / 2;
		MergeSort(arr, from, mid);
		MergeSort(arr, mid + 1, to);
		Merge(arr, from, mid, to);
	}
}

int main()
{
	std::vector<int> arr = { 3, 4, 6, 1, 9, 2, 10, 5, 8, 7 };
	MergeSort(arr, 0, arr.size() - 1);
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}