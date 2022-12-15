#include <iostream>
#include <type_traits>

// std::enable_if �� ���� ���� ����ߴµ�.. �ʹ� ������ ���Դϴ�.
// => �׷��� C++20 ���� "Concept" �̶�� ���ο� ������ �����մϴ�.

template<typename T> requires std::is_pointer_v<T> 
void printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);// ok.

	std::pair<int, int> p;
}


