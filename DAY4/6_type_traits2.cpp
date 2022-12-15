#include <iostream>
#include <type_traits>


// ����� ���
// 1. primary template �� ����� false ���� ( value = false ��� �ǹ�)
// 2. ������ �����ϴ� �κ� Ư��ȭ�� �ۼ��ϰ� true ����(value=true)

// T�� ������ ���� �����ϴ� ���
template<typename T> struct is_pointer
{
	// �� enum ����� �ϳ��� ?
//	bool value = false;		// 1. C++98 ������ �̷��� �ʱ�ȭ �Ҽ� ����
							// 2. ����, �̷��� �ϸ� value �� �����Ͻð���
							//    �˼� �ִ� ���� �ƴմϴ�.

//	enum { value = false }; // �׷��� C++98 �������� �� ����� �����߽��ϴ�.
							// ����, "enum hack" �̶� �Ҹ��� ��� �Դϴ�.

	// C++11 ���� ���ʹ� enum �� ������� �ʰ� �Ʒ� ó�� ����� �˴ϴ�.
	// => enum ���� �ϸ� value �� int Ÿ���ε�
	// => �Ʒ� ó�� �ϸ� value �� bool Ÿ���� �˴ϴ�.
	static constexpr bool value = false;
};


template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};


template<typename T> void foo(const T& a)
{
	// T : int, int*
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