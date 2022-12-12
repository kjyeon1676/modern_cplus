#include <iostream>
#include <vector>

// 아래 코드를 잘 생각해보세요
// => C++20 에서 등장하는 range 라는 라이브러리의 원리 입니다.
template<typename T>
class reverse_view
{
	T& rng;	// 컨테이너를 참조로 보관
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return  rng.rbegin(); }
	auto end()   { return  rng.rend(); }
};

int main()
{
	// C++17 부터 클래스 템플릿 인자 생략가능
//	std::vector<int> v2 = { 1,2,3 }; // C++14 까지는 int가 꼭 필요
//	std::vector      v3 = { 1,2,3 }; // C++17 부터는 int 생략가능
	// 대부분의 컴파일러는 C++14가 기본 컴파일
	// => C++17 이상을 사용하려면 C++언어 변경하셔야 합니다.


	std::vector<int> v = { 1,2,3,4,5 };

	reverse_view rv(v); // C++17 부터는 클래스 템플릿도
						// 템플릿 인자 생략가능합니다.

	//for (auto& e : v )
	//for (auto& e : rv)
	for (auto& e : reverse_view(v) )
	{
		std::cout << e << ", ";
	}
}















