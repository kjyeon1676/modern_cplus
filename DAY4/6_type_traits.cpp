// 4_type_traits - 184page
#include <iostream>

// type traits : Ÿ�� T�� ���� �پ��� Ư��(Ư��)�� �����ϴ� ���

template<typename T> void printv(const T& v)
{
	if ( T �� ������ Ÿ���̸� )
		std::cout << v << " : " << *v << std::endl;
	else 
		std::cout << v << std::endl;
}


int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

