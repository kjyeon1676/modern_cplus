#include <iostream>

int main()
{
	// 아래 코드의 원리는 ()연산자가 템플릿이고
	// => "2개의 인자가 서로 다른 템플릿" 입니다.
	auto f1 = [](auto a, auto b) { return a + b; };


	auto swap1 = [](auto& a, auto& b) { auto tmp = std::move(a);
										a = std::move(b);
										b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	swap1(n, d); // 되는것이 좋을까요 ? 안되는게 좋을까요 ?


}

