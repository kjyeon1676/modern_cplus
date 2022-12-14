// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional> // 이 안에 C++ 표준에 less<> 와 greater<> 가 있습니다.
					  // C++98
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	
	// 1. 비교 정책을 전달하지 않으면 - 오름 차순 정렬
	// std::sort(v.begin(), v.end()); 

	// 2. 비교정책으로 일반함수 사용 - 비교 정책이 인라인 치환 안됨
	//std::sort(v.begin(), v.end(), cmp1); 

	// 3. 비교정책으로 함수 객체 사용
	// => 이미 C++ 표준의 <functional> 헤더에 제공됨.(C++98 부터)
	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>() ); // 임시객체로 전달
	std::sort(v.begin(), v.end(), std::less()); // C++17 부터 가능.


	// 4. C++11 부터는 람다 표현식 사용가능
	
	std::sort( v.begin(), v.end(), [](int a, int b) { return a < b; }); 

	// 람다 표현식의 원리... 
	// 컴팡일러가 함수 객체를 생성하는 것. 

	// 위 한줄을 보고 컴파일러가 아래 코드를 생성..
	class CompilerGeneratedName
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};
	std::sort(v.begin(), v.end(), CompilerGeneratedName() );

}





