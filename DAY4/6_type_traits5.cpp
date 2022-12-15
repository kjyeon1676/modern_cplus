#include <iostream>
#include <type_traits>

// C++ 표준에 remove_all_pointer 는 없습니다.
// remove_pointer 구현 참고해서.. remove_all_pointer 만들어 보세요

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	using type = typename remove_all_pointer<T>::type;
};

int main()
{
	remove_all_pointer<int***>::type n; 

	std::cout << typeid(n).name() << std::endl; // int
}
