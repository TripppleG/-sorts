#include <iostream>
#include <vector>
void InsertionSort(std::vector<int>& arr, int len)
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
	std::vector<int> arr = { 14, 36, 435, 6, 43, 1, 53, -45, 0, 65 };
	InsertionSort(arr, arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}