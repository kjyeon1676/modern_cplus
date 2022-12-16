#include <iostream>

// tuple5.cpp 에서 tuple 2개 복사 해 오세요..
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

// N == 0 일때를 위한 부분 특수화
/*
template<typename TP> struct tuple_element<0, TP>
{
	// 현재 부분 특수화로는 튜플인 TP 의 0번째 요소 타입을 구할수 없다.
};
*/
/*
template<typename ... Types> 
struct tuple_element<0, tuple<Types...> > 
{
	// 현재 부분 특수화로는 0번째 요소 타입을 구할수 없다.
	// 0번째 요소가 Types 안에 포함되어 있다.
};
*/

// 정답. 
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	// tuple<T, Types...> 의 
	// 0번째 요소의 타입 : T
	// 0번째 요소를 저장하는 튜플 타입 : tuple<T, Types...>

	using type = T;	
	using tupleType = tuple<T, Types...>;
};

// 위처럼 N == 0 을 완성후에
// N != 0 의 경우는 재귀로 처리
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type      = typename tuple_element<N-1, tuple< Types...>>::type;
	using tupleType = typename tuple_element<N-1, tuple< Types...>>::tupleType;
};


template<typename TP> void foo(TP& tp)
{
	// TP : tuple<int, double, char>

	typename tuple_element<1, TP>::type n; // double. 요소의 타입
	typename tuple_element<1, TP>::tupleType t; // 
										// tuple<double, char>

	std::cout << typeid(n).name() << std::endl; // double
	std::cout << typeid(t).name() << std::endl; // double
}


int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');

	foo(t3);
}
