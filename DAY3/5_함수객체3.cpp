#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };


	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	// => 3번째 인자로 전달되는 함수는 "단항함수" 이어야 합니다.
	//auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	auto p1 = std::find_if(v.begin(), v.end(), 
						"foo + 지역변수k");
}

// 일급 객체 ( first class object )
// => 함수 인자로 전달 가능한 객체 
// => C/C++ 의 일반 함수는 모두 일급 객체 입니다.


// 클로져( Closure )
// => 자신이 속한 문맥의 지역변수를 캡쳐할수 있는 일급 객체

