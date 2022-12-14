#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

// 일반함수는 "클로져"가 될수 없지만
// 함수객체는 "클로져"가 될수 있습니다.
struct IsDivide
{
	int value;	
	IsDivide(int n) : value(n) {}

	bool operator()(int n) const {	return n % value == 0;	}
};



int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k);	// f 는 내부적으로 k값을 보관하게 됩니다.
					// 흔히, 캡쳐 한다고 표현합니다.
	int ret = f(6); // 6 % k  즉, 단항함수 인데, 캡쳐된 k값 사용

	auto p1 = std::find_if(v.begin(), v.end(), f);
	auto p2 = std::find_if(v.begin(), v.end(), IsDivide(k) );
			// => IsDivide 라는 단항함수 객체를 전달하는데..
			// => k라는 지역변수의 값을 같이 전달하는 효과!!
			// => 문맥이 속한 지역변수를 캡쳐하는 기능을 가진 일급객체
}


