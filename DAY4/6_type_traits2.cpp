#include <iostream>
#include <type_traits>


// T�� ������ ���� �����ϴ� ���
template<typename T> struct is_pointer
{
	enum { value = false }; 
};


template<typename T> void foo(const T& a)
{
	if ( is_pointer<T>::value  )

		std::cout << "������" << std::endl;
	else
		std::cout << "������ �ƴ�" << std::endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}