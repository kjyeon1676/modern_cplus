#include <iostream>
#include <vector>
#include <algorithm>

// 아래와 유사하게 만들어진 것이 C언어의 "qsort" 입니다
// => 결국 비교 함수를 다시 호출하게 되므로 느립니다.
// => 데이타량이 많은 경우는 사용하지 마세요..

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
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

//	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
	
	for (auto e : x)
		std::cout << e << ", ";

	std::cout << std::endl;
}

