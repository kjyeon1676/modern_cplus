#include <iostream>

void foo(int* p) {}
void goo(char* p) {}

// nullptr 을 직접 만들어 봅시다.
struct xnullptr_t
{
	// 아래 같은 함수가 "변환 연산자" 함수 입니다.
	// operator int* () { return 0; }
	// operator char* () { return 0; }

	template<typename T>
	operator T*() { return 0; }
};
xnullptr_t xnullptr;

int main()
{
	foo(xnullptr);	// xnullptr => int* 로의 암시적 형변환 필요
					// => xnullptr.operator int*()
	goo(xnullptr);
}
// nullptr 의 역사
// 1. C++11 이 나오기 전에 boost 라는 라이브러리에서 위 처럼 만들어서
//    제공했습니다.
// 2. C++11 에서 표준에 추가되었고, 지금은 nullptr 이 객체가 아닌
//   키워드 입니다.