#include <iostream>

// tuple5.cpp ���� tuple 2�� ���� �� ������..
template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple< Types...>
{
	using base = tuple< Types...>;

	T value;

	tuple() = default;
	tuple(const T& n, const Types& ... args)
		: value(n), base(args...) {}

	static constexpr int N = base::N + 1;
};
//==================================================

template<int N, typename TP> struct tuple_element
{
	using type = TP;
};

// N == 0 �϶��� ���� �κ� Ư��ȭ
/*
template<typename TP> struct tuple_element<0, TP>
{
	// ���� �κ� Ư��ȭ�δ� Ʃ���� TP �� 0��° ��� Ÿ���� ���Ҽ� ����.
};
*/
/*
template<typename ... Types> 
struct tuple_element<0, tuple<Types...> > 
{
	// ���� �κ� Ư��ȭ�δ� 0��° ��� Ÿ���� ���Ҽ� ����.
	// 0��° ��Ұ� Types �ȿ� ���ԵǾ� �ִ�.
};
*/
// ����. 
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

// ��ó�� N == 0 �� �ϼ��Ŀ�
// N != 0 �� ���� ��ͷ� ó��
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple< Types...>>::type;
};


template<typename TP> void foo(TP& tp)
{
	// TP : tuple<int, double, char>

	typename tuple_element<1, TP>::type n;

	std::cout << typeid(n).name() << std::endl; // double
}


int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');

	foo(t3);
}
