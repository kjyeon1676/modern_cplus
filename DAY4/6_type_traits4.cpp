// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value	 std::is_pointer<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 1. primary template 을 만들고 "using type = T" 를 넣으세요

template<typename T> struct remove_pointer
{
	using type = T;
};
// 2. 원하는 타입을 얻을수 있도록
//    부분 특수화 문법을 사용해서 타입을 분할 합니다.
//    int* => int 와 * 로 분할
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};

int main()
{
	remove_pointer<int*>::type n2;  // int n2

	std::cout << typeid(n2).name() << std::endl;
}


template<typename T> void foo(T a)
{
	// remove_pointer 사용시 주의 사항

	remove_pointer<int*>::type n1;
			// => dependent name 아닙니다. typename 필요 없습니다.

	typename remove_pointer<T>::type n2;
			// => 반드시 typename 적어야 합니다.
}