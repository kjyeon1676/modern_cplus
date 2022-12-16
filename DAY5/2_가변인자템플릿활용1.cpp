#include <iostream>

// 함수도 타입이 있습니다.
// => 함수 선언 에서 이름만 제거하면 타입입니다.
// => "int(int, double)" 가 아래 함수 f의 타입입니다

int f(int a, double b) { return 0; }

// 함수의 리턴 타입을 알아내는 result<> 를 만들어 봅시다.
template<typename T> struct result
{
	using type = T;
};
// 부분 특수화 기술을 사용해서 원하는 타입을 얻을수 있도록
// 타입을 분할 합니다.
// "int(int, double)" => "int" 와 나머지 요소들로 분할
template<typename R, typename A1, typename A2> 
struct result< R(A1, A2) >
{
	using type = R;
};



template<typename T> void foo(T& a) 
{
	// T : int(int, double)
	typename result<T>::type n;		

	cout << typeid(n).name() << endl; // int
}

int main()
{
	foo(f);
}