#include <iostream>

// �Լ��� Ÿ���� �ֽ��ϴ�.
// => �Լ� ���� ���� �̸��� �����ϸ� Ÿ���Դϴ�.
// => "int(int, double)" �� �Ʒ� �Լ� f�� Ÿ���Դϴ�

int f(int a, double b) { return 0; }

// �Լ��� ���� Ÿ���� �˾Ƴ��� result<> �� ����� ���ô�.
template<typename T> struct result
{
	using type = T;
};
// �κ� Ư��ȭ ����� ����ؼ� ���ϴ� Ÿ���� ������ �ֵ���
// Ÿ���� ���� �մϴ�.
// "int(int, double)" => "int" �� ������ ��ҵ�� ����
// �Ʒ� �κ� Ư��ȭ�� ������ ���ڰ� 2���� ��츸 �˴ϴ�.
/*
template<typename R, typename A1, typename A2> 
struct result< R(A1, A2) >
{
	using type = R;
};
*/
// ��� �Լ��� ��ȯ Ÿ���� ���ϵ��� ���������� �غ��ϴ�.
template<typename R, typename ... Types>
struct result< R(Types...) >
{
	using type = R;
};



template<typename T> void foo(T& a) 
{
	// T : int(int, double)
	typename result<T>::type n;		

	std::cout << typeid(n).name() << std::endl; // int
}

int main()
{
	foo(f);
}