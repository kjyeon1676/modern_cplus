#include <iostream>

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

Meter operator""m(unsigned long long value)
{
	Meter m(static_cast<int>(value));
	return m;
}

int main()
{
	Meter m1 = 5m;	// Meter operator""m(5)


	//	Gram  g1 = 5gram;

	double d = 3.4;
	float f = 3.4f; // 3.4f 에서 "f" 의 의미는 float 타입으로
					// 처리해 달라.
					// 5l : 5 long


}




