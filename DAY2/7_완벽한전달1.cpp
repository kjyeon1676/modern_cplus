// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding : 받은 인자를 다른 함수에 전달하는 것
// 
// perfect forwarding(완벽한 전달)
// => 받은 인자를 다른 함수에 전달할때 
//    어떠한 변환도 없이 원본 그대로 전달하는 기술

// 인자로 전달된 함수의 성능(수행시간)을 측정하는 함수
template<typename F, typename T>
void chronometry(F f, const T& arg)
{
	// 시간을 구한후 보관
	f(arg);	// 함수 호출
	// 다시 시간을 구한후, 소요시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
