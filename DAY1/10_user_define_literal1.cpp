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
	float f = 3.4f; // 3.4f ���� "f" �� �ǹ̴� float Ÿ������
					// ó���� �޶�.
					// 5l : 5 long


}




