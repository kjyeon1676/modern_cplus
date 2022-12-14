#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

// �Ϲ��Լ��� "Ŭ����"�� �ɼ� ������
// �Լ���ü�� "Ŭ����"�� �ɼ� �ֽ��ϴ�.
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

	IsDivide f(k);	// f �� ���������� k���� �����ϰ� �˴ϴ�.
					// ����, ĸ�� �Ѵٰ� ǥ���մϴ�.
	int ret = f(6); // 6 % k  ��, �����Լ� �ε�, ĸ�ĵ� k�� ���

	auto p1 = std::find_if(v.begin(), v.end(), f);
	auto p2 = std::find_if(v.begin(), v.end(), IsDivide(k) );
			// => IsDivide ��� �����Լ� ��ü�� �����ϴµ�..
			// => k��� ���������� ���� ���� �����ϴ� ȿ��!!
			// => ������ ���� ���������� ĸ���ϴ� ����� ���� �ϱް�ü
}


