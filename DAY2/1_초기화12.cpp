#include <vector>

template<typename T, int N> struct array
{
	T buff[N];
	
	// array 는 반드시 = {} 초기화를 지원해야 합니다.
	// 1. std::initializer_list 가지는 생성자 제공하거나
	// 2. 어떠한 생성자도 만들지 말거나(+가상함수도)
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 }; // 모든 요소가 힙에!!
	array<int, 5> arr = { 1,2,3,4,5 }; // 모든 요소가 스택에 .
}