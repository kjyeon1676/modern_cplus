#include <iostream>
#include <type_traits>

// C++ 표준에 remove_all_pointer 는 없습니다.
// remove_pointer 구현 참고해서.. remove_all_pointer 만들어 보세요


int main()
{
	remove_all_pointer<int***>::type n; 

	std::cout << typeid(n).name() << std::endl; // int
}
