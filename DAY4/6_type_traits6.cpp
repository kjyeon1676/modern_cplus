// 4_type_traits3 - 210 page
#include <iostream>

// 핵심 1. 표준  traits 를 사용하려면 필요한 헤더.
#include <type_traits>

// C++14 부터 아래 코드가 표준에 도입됩니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T> void foo(T a)
{
	// 핵심 2. 타입의 특성을 조사하려면
	bool b1 = std::is_pointer<T>::value;	// C++11 버전
	bool b2 = std::is_pointer_v<T>;			// C++17 버전



	// 핵심 3. 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1;	// C++11버전
	std::remove_pointer_t<T> n2;				// C++14버전
}




int main()
{
	int n = 0;
	foo(&n);
}
