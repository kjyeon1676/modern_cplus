// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits �� ����
// 1. Ÿ������ : is_xxx<T>::value	 std::is_pointer<T>::value
// 2. ����Ÿ�Ծ�� : xxx<T>::type

// 1. primary template �� ����� "using type = T" �� ��������
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