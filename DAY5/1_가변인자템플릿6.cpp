#include <iostream>

// 233 page �Դϴ�.

// �ٽ� : �Լ��� ��� ���ڸ� �������ڷ� ���� ����
//        1��° ���ڸ� �������� �̸��� ���

void foo() {} // recursive ���� �ڵ��� ���Ḧ ���ؼ�!!
				// C++14 ������ �̷��� �߽��ϴ�.
				// C++17 ���ʹ� �Ʒ� main ó��.. 

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int cnt = 0;
	++cnt;
	std::cout << value << " : " << cnt << std::endl; // cnt�� �׻� 1

	if constexpr (sizeof...(args) > 0)
		foo(args...);

//	foo(args...); // foo(3.4, 'A')
				  // foo('A');
				  // foo()
}

int main()
{
	foo(1, 3.4, 'A'); 
}





