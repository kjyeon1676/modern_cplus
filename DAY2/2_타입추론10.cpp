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
// 방법 1. auto 사용
// => return "표현식" 에서 "표현식"을 보고 리턴 타입을 추론해 달라는것
// 특징 1. return 문장이 한개인 경우만 가능
// 특징 2. return "표현식" 에서 표현식이 참조로 결정되어도
//         auto 추론 이므로 리턴 타입을 값 타입.

template<typename T1, typename T2>
auto Mul(T1 a, T2 b)
{
	return a * b;
}


int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

