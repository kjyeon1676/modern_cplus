#include <iostream>

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

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
	using tupleType = tuple<T, Types...>;
};

template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple< Types...>>::type;
	using tupleType = typename tuple_element<N - 1, tuple< Types...>>::tupleType;
};
//=================================================
// get2 에서 한글로된  get 복사해오세요

template<int N, typename T>
typename tuple_element<N, T>::type &
get(T& tp)
{
	return static_cast<typename tuple_element<N, T>::tupleType&>(tp).value;
}

int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');

	get<0>(t3) = 99;

	std::cout << get<0>(t3) << std::endl; // 99
	std::cout << get<1>(t3) << std::endl; // 3.4
	std::cout << get<2>(t3) << std::endl; // 'A'
}
