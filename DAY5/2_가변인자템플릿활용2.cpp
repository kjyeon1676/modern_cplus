#include <iostream>

int f(int, double, char) { return 0; }

// 이번에는 "리턴 타입" 이 아닌 "인자의 타입"을 구해 봅시다.
template<int N, typename T> struct argument
{
	using type = T;
};


// N 번째 인자의 타입을 구할수 있도록 부분 특수화를 만들어야 합니다.
// => 이 부분이 핵심!!!
// => 아래 처럼 하면 N번째 인자의 타입을 구할수는 없습니다.
// => 부분 특수화가 잘못된 경우 입니다.
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
	// "R(A, Types...)" 함수의 N  번째 인자 타입은
	// "R(Types...)"    함수의 N-1번째 인자 타입입니다.

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