#include <iostream>

// auto 와 람다 표현식
int main()
{
//	Point pt = Point(1, 2);
			// 1. 1,2 로 초기화된 임시객체를 만들고..
			// 2. pt 에 복사(정확히는 move 생성자)됩니다.
			
			// 그런데, 복사 생성자(move 생성자)가 제거되는 최적화가
			// 적용됩니다. 따라서 위 한줄은 아래 한줄과 완전히 같습니다.
//	Point pt(1, 2);
	//-------------------------------------------

	// 핵심 1. 람다표현식의 최종 결과는 임시객체 입니다.
	// 핵심 2. 람다표현식을 auto  변수에 담아서 함수 처럼 사용가능합니다.

	auto f = [](int a, int b) { return a + b; };
			// class xxx{ operator(){}}; xxx();
			// xxx f;

	int n1 = f(1, 2);
	int n2 = f.operator()(1, 2); // 이렇게도 사용가능합니다.

	// 핵심 3. 람다 표현식은 임시객체 rvalue 입니다.

	auto a1 = [](int a, int b) { return a + b; }; // ok

	auto& a2 = [](int a, int b) { return a + b; }; // error
	
	const auto& a3 = [](int a, int b) { return a + b; }; // ok
	
	auto&& a4 = [](int a, int b) { return a + b; }; // ok
	// T&& 와 같습니다. 따라서, forwarding reference 

	// 위 4줄에서는 1번이 가장 좋습니다.
//	CompilerGeneratedName a1 = CompilerGeneratedName();
		//  위 코드는 결국 아래 코드와 동일하게 됩니다.
//	CompilerGeneratedName a1;
}

