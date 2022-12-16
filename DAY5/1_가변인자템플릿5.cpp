#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면
	// args : 1, 2, 3 이 있습니다.!!
	// args 안에서 2번째 요소를 꺼내고 싶다!!!
	// => 한번에 할수 있는 방법은 없습니다.  
	// 방법 1. pack expansion
	// 방법 2. recursive 와 유사한 함수 구현
	// 방법 3. fold expression - C++17

	// 방법 1. pack expansion
	// 1. 요소의 타입의 동일 함을 보장할수 있다면
	//    배열이나 initializer_list 등에 담아서 사용
	int x[] = { args... };	// 단, 이경우 args 가 empty 라면에러!
	std::initializer_list<int> e[] = { args... }; // ok


	// 2. 요소의 타입이 다른 경우 tuple 이라는 타입에 담으면 됩니다.
	std::tuple<Types...> tp(args...);

	// tp 에 0번째 요소 접근.
	std::cout << std::get<0>(tp) << std::endl; 

}

int main()
{
	foo(1, 2, 3);	// foo(int, int, int)
}

