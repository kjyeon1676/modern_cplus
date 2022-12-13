// 후위반환 - 73 page 아래 부분
#include <iostream>

// 아래 코드에서 ? 는 어떻게 채워야 할까요 ?
/*
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// 방법 1. auto 추론 사용
// => return "표현식" 에서 "표현식"을 보고 리턴 타입을 추론해 달라는것
// 특징 1. return 문장이 한개인 경우만 가능
// 특징 2. return "표현식" 에서 표현식이 참조로 결정되어도
//         auto 추론 이므로 리턴 타입을 값 타입.
/*
template<typename T1, typename T2>
auto Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// 방법 2. decltype(auto) 반환
// 특징 1. return "표현식" 에서 "표현식"이 참조로 결정되면 
//         반환 타입도 참조 사용 ( auto 와 다른 점)
// 특징 2. return  문장이 2개라면 에러..
/*
template<typename T1, typename T2>
decltype(auto) Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// 방법 3. 반환 타입을 직접 표기
// => return "표현식" 을 보고 추론하지 말고 "a*b" 로 추론해 달라고 명시한것
// => 리턴 타입을 직접 표기했으므로 return 문장이 여러개라도 사용가능
// => 그런데, 아래 코드는 에러. 
//    a, b 변수가 선언전에 사용되는 코드
/*
template<typename T1, typename T2>
decltype( a * b ) Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// 방법 4. C++11에서 추가된 후위 반환 타입으로 반환 타입 명시!!
/*
//int add(int a, int b)
auto  add(int a, int b) -> int
{
	return a + b;
}
*/
// => return 문장이 여러개 있어도 가능하고
// => a*b 가 참조로 결정되면 반환 타입도 참조.. !
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

