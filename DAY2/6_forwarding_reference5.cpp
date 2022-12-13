#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법 => 생성되는 함수이름을 출력해 보는것이 제일
	// 좋습니다.
	std::cout << __FUNCSIG__ << std::endl;	
}

int main()
{
	int n = 10;

	foo(n);  //	T=int&   T&&=int&
	foo(10); // T=int    T&&=int&&
}




