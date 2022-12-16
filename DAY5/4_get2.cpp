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

int main()
{
//	tuple<>
//	tuple<		       short>					// 2 보관
//	tuple<	   double, short>					// 3.4 보관
	tuple<int, double, short> t3(1, 3.4, 2);	// 1 보관

	std::cout << t3.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t3).value << std::endl; // 3.4 나오게 해보세요

	std::cout << static_cast<tuple<short>&>(t3).value << std::endl; // 2 나오게 해보세요.

	// get 을 생각해 봅시다.
	double d = get<1>(t3); 
}
template<int N, typename T>
튜플인 T 타입의 N 번재 요소의 타입&
get(T& tp)
{
	return static_cast<T의 N번째 부모 타입&>(tp).value;
}
// 결국 get 을 완성하려면
// => 임의의 tuple 타입 T의 N번째 요소의 타입 구하기
// => 임의의 tuple 타입 T의 N번째 기반클래스 타입 구하기
// 입니다.










