#include <algorithm>

struct Less   { inline bool operator()(int a, int b) const { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) const { return a > b; }};
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ ǥ���� std::sort()�� ��� ���ڰ� template �Դϴ�.
	// => ����ڰ� �����ϴ� ������ ����� ���� �Լ��� �����մϴ�.

	// 1. �� ��å���� �Ϲ��Լ��� �����ϴ� ���
	std::sort(x, x + 10, cmp1);
	std::sort(x, x + 10, cmp2);
}