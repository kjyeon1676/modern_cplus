// 5_람다표현식5
#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{ operator();}; xxx();		

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{ operator();}; yyy();

	// 핵심 1. 모든 람다 표현식은 다른 타입입니다.

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// 핵심 2. 람다 표현식으로 초기화된 auto 변수는 변경될수 없습니다.

	auto f3 = [](int a, int b) { return a + b; };	
				// class zzz{}; zzz();
				// zzz f3; 

	f3 = [](int a, int b) { return a + b; }; // error
			// class kkk{}; kkk();
			// 즉, f3 과 우변은 다른 타입입니다.


	// 핵심 3. 중요!!!
	int x[3] = { 1,2,3 };
	
	// 동일한 람다 표현식이 여러번 사용될때

	// 1. 아래 처럼 사용하면 각각의 람다표현식이 다른 타입이므로
	// => 3개의 for_each 가 생성됩니다.

	std::for_each(x, x + 3, [](int n) { std::cout << n; });
	std::for_each(x, x + 3, [](int n) { std::cout << n; });
	std::for_each(x, x + 3, [](int n) { std::cout << n; });

	// 2. 동일람다표현식이 여러번 사용되면 auto에 담아서 사용하는것이
	// 효율적 입니다.
	auto show = [](int n) { std::cout << n; };

	std::for_each(x, x + 3, show );
	std::for_each(x, x + 3, show);
	std::for_each(x, x + 3, show);
}





