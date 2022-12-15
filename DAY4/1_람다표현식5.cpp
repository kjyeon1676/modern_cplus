// 143 
#include <functional>

int main()
{
	// 람다표현식을 담는 방법
	// 1. auto 변수
	auto f1 = [](int a, int b) { return a + b; };

	// 2. 함수 포인터
	int(*f2)(int, int) = [](int a, int b) { return a + b; };

	// 3. std::function
	std::function<int(int,int)> f3 = [](int a, int b) { return a + b; };

	// f2 와 f3은 변경될수 있습니다.
	// f2 = &add;  // 이런식으로..

	f1(1, 2);	// 함수 주소를 가지고 호출하는 것이 아니라.
				// f1.operator()(1,2) 로 호출됩니다.
				// 즉, 타입정보를 사용한 호출.
				// 인라인치환 됩니다.

	f2(1, 2);	// f2에 담긴 함수의 주소를 가지고 호출 됩니다.
				// 언제라도 f2가 가진 주소는 실행할때 변경될수 있습니다.
				// 인라인 치환안됨. 
	f3(1, 2);	// ""

}