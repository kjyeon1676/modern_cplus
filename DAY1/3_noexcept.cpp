// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept 키워드의 2가지 용도
// 1. 함수가 예외가 있는지 조사
// 2. 함수가 예외가 없음을 알릴때 사용

void foo()	// 예외가 발생할 가능성이 있음.
{
}
void goo() noexcept  // 예외 발생가능성이 없음을 컴파일러에게 알린다
{	
}

int main()
{
	// 함수가 예외가 있는지 조사하는 방법
	// => noexcept(함수호출식)
	// => 실제로 함수를 호출하는 것은 아니고,
	// => 함수를 호출했을때 예외의 가능성이 있는지만 조사
	// => 결국, 함수 선언뒤에 noexcept 가 있는지 조사하는 것!
	bool b1 = noexcept(foo());	// false
	bool b2 = noexcept(goo());  // true
}




