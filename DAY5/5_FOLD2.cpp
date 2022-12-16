// 9_FOLD - 237 page

#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}


template<typename ... Types>
void Show(Types ... args)
{
	// �ٽ� 1. std::cout �� �ʱⰪ�̰�, << �� ���� ������
	// (I op ... op args )
	//(std::cout << ... << args); 
		// ((((( std::cout << 1) << 2 ) << 3) << 4  .... 

	// �ٽ� 2. "pack�̸�" �� �ƴ϶� "pack�̸��� ����ϴ� ����" �� �־ �˴ϴ�.
	// => , �� ���� ������ �Դϴ�.
	(printv(args), ...);
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



