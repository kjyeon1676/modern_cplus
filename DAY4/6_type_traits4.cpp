// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value	 std::is_pointer<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 1. primary template 을 만들고 "using type = T" 를 넣으세요
template<typename T> struct remove_pointer
{
	using T = type;
};


int main()
{
	remove_pointer<int*>::type n2;  // int n2
}






template<typename T> void foo(T a)
{
}