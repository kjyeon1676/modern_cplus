#include <iostream>

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};
// _ 가 붙지 않는 모양은 모두 C++ 표준만 사용하도록 예약되었습니다.
// 개발자가 직접 만들려면 꼭 _로 시작해야 합니다.
Meter operator""_m(unsigned long long value)
{
	Meter m(static_cast<int>(value));
	return m;
}

int main()
{
	Meter m1 = 5_m;	// Meter operator""m(5)


	//	Gram  g1 = 5gram;

	double d = 3.4;
	float f = 3.4f; // 3.4f 에서 "f" 의 의미는 float 타입으로
					// 처리해 달라.
					// 5l : 5 long


}




