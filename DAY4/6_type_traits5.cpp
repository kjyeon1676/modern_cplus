#include <iostream>
#include <type_traits>

// C++ ǥ�ؿ� remove_all_pointer �� �����ϴ�.
// remove_pointer ���� �����ؼ�.. remove_all_pointer ����� ������

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
