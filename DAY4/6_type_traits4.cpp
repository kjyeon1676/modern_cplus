// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits �� ����
// 1. Ÿ������ : is_xxx<T>::value	 std::is_pointer<T>::value
// 2. ����Ÿ�Ծ�� : xxx<T>::type

// 1. primary template �� ����� "using type = T" �� ��������

template<typename T> struct remove_pointer
{
	using type = T;
};
// 2. ���ϴ� Ÿ���� ������ �ֵ���
//    �κ� Ư��ȭ ������ ����ؼ� Ÿ���� ���� �մϴ�.
//    int* => int �� * �� ����
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
	// remove_pointer ���� ���� ����

	remove_pointer<int*>::type n1;
			// => dependent name �ƴմϴ�. typename �ʿ� �����ϴ�.

	remove_pointer<T>::type n2;
			// => �ݵ�� typename ����� �մϴ�.
}