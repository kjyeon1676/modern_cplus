#include <iostream>
#include <type_traits>

// C++ ǥ�ؿ� remove_all_pointer �� �����ϴ�.
// remove_pointer ���� �����ؼ�.. remove_all_pointer ����� ������


int main()
{
	remove_all_pointer<int***>::type n; 

	std::cout << typeid(n).name() << std::endl; // int
}
