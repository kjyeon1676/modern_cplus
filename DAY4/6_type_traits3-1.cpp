// 6_type_traits3-1.     1번 복사해오세요.
#include <iostream>
#include <type_traits> // std::is_pointer<> 가 있습니다,
/*
template<typename T> void printv(const T& v)
{
	// 아래 처럼 만들면 if ( 조건식) 에서
	// if 문은 실행시간 조건문 이므로
	// 조건식이 컴파일 시간에 false 결정되어도 if 문의 문장이
	// "템플릿 => C++ 함수" 에 포함됩니다. 
	// 따라서 error
	if ( std::is_pointer<T>::value )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
int main()
{
	int n = 10;

	printv(n); 
	printv(&n);// ok.
}


