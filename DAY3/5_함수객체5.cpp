#include <iostream>
#include <vector>
#include <algorithm>

void Sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[i] > arr[j])
				std::swap(arr[i], arr[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10);
	
}

