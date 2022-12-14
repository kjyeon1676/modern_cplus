#include <iostream>
#include <vector>
#include <algorithm>

void Sort(int* arr, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
		//	if (arr[i] > arr[j])


			if( cmp(arr[i], arr[j]) == true )
				std::swap(arr[i], arr[j]);
		}
	}
}
//----------------------------------
bool cmp1(int a, int b) { return a > b; }
bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

//	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
	
	for (auto e : x)
		std::cout << e << ", ";

	std::cout << std::endl;
}

