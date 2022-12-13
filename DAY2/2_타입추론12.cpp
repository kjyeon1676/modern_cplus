// 2_타입추론12

// 결론
// 배열을 템플릿에 인자로 보내거나, auto 로 가르킬때
// 1. 값으로 받으면 포인터로 변경되어서 받게 됩니다.
//    => "decay" 라고 합니다.
// 
// 2. 참조로 받으면 변화 없이 배열로 받게 됩니다.


template<typename T> void f1(T  a, T  b){ }
template<typename T> void f2(T& a, T& b){ }

int main()
{
	f1("orange", "apple"); // ok
	// => 배열을 전달하는 데, 값으로 받고 있으므로 포인터로 받게 됩니다.
	// => "orange" const char[7] => const char*
	// => "apple"  const char[6] => const char*
	// 따라서, 2개의 인자가 같은 타입이어야 한다는 조건을 만족!! 에러 아님.

	f2("orange", "apple"); // error. 왜 에러일까요 ?
	// => 배열을 참조로 받으면 T도 배열 입니다.
	// => 같은 타입을 전달해야 하는데
	// => "orange" 와 "apple" 은 다른 타입이므로 error


	// 핵심 1. 문자열 리터럴의 타입
	// "orange" : const char[7]
	// "apple"  : const char[6]
	// => 즉, "orange" 와 "apple" 는 다른 타입 입니다.
}