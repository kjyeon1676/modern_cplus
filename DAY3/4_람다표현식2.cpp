#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// v에서 3을 찾고 싶다.
	auto p1 = std::find(v.begin(), v.end(), 3);

	std::cout << *p1 << std::endl;


	// v에서 1번째 나오는 "3의 배수"를 찾고 싶다.?
	
	// std::find    : 값  검색, 마지막 인자로 "값" 전달
	// std::find_if : 조건 검색, 마지막 인자로 "함수" 전달

	auto p2 = std::find_if(v.begin(), v.end(), foo ); // C++98 스타일

	auto p3 = std::find_if(v.begin(), v.end(),  
				[](int n) { return n % 3 == 0; }); // C++11 스타일

}


