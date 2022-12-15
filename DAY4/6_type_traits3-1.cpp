// 6_type_traits3-1.     1�� �����ؿ�����.
#include <iostream>
#include <type_traits> // std::is_pointer<> �� �ֽ��ϴ�,
/*
template<typename T> void printv(const T& v)
{
	// �Ʒ� ó�� ����� if ( ���ǽ�) ����
	// if ���� ����ð� ���ǹ� �̹Ƿ�
	// ���ǽ��� ������ �ð��� false �����Ǿ if ���� ������
	// "���ø� => C++ �Լ�" �� ���Ե˴ϴ�. 
	// ���� error
	if ( std::is_pointer<T>::value )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
int main()
{
	int n = 10;

	printv(n); 
	printv(&n);// ok.
}


