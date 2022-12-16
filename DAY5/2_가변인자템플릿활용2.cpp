#include <iostream>

int f(int, double, char) { return 0; }

// �̹����� "���� Ÿ��" �� �ƴ� "������ Ÿ��"�� ���� ���ô�.
template<int N, typename T> struct argument
{
	using type = T;
};


// N ��° ������ Ÿ���� ���Ҽ� �ֵ��� �κ� Ư��ȭ�� ������ �մϴ�.
// => �� �κ��� �ٽ�!!!
// => �Ʒ� ó�� �ϸ� N��° ������ Ÿ���� ���Ҽ��� �����ϴ�.
// => �κ� Ư��ȭ�� �߸��� ��� �Դϴ�.
/*
template<int N, typename R, typename ... Types> 
struct argument<N, R(Types...) >
{
	using type = T;
};
*/
// N == 0
template<typename R, typename A, typename ... Types>
struct argument<0, R(A, Types...) >
{
	using type = A;
};

// N != 0
template<int N, typename R, typename A, typename ... Types>
struct argument<N, R(A, Types...) >
{
	// "R(A, Types...)" �Լ��� N  ��° ���� Ÿ����
	// "R(Types...)"    �Լ��� N-1��° ���� Ÿ���Դϴ�.

	using type = typename argument<N - 1, R(Types...)>::type;
};




template<typename T> void foo(T& t)
{
	// T : int(int, double, char)
	typename argument<1, T>::type n;

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}