#include <cassert>

// assert : 실행시간에 표현식의 유효성을 조사
// static_assert : 컴파일 시간 assert - C++11
//				   컴파일 시간의 유효성 조사
//				   키워드. include 필요 없음

// 주의 1. 표현식은 반드시 컴파일시간에 조사가능해야 합니다.
// 2. 함수 안 또는 밖에 만들수 있습니다.
static_assert( sizeof(int*) >= 8, "error, not 64bit");


void foo(int age)
{
	// 함수 인자를 바로 사용하지 말고.. 
	// 인자값의 유효성을 확인하는 것이 안전합니다.
	assert( age > 0 );

	// 아래 처럼 할수 없습니다.
	// 변수값을 컴파일시간에 조사하는 것은 안됩니다.
	static_assert(age > 0, "error, not 64bit");


	// age > 0 이라고 가정하고 수십줄의 코드 작성
	int* p = new int[age];

	delete[] p;
}

int main()
{
	foo(10);
	//foo(-10);
}