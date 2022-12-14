#include <algorithm>

struct Less   { inline bool operator()(int a, int b) const { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) const { return a > b; }};
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준의 std::sort()는 모든 인자가 template 입니다.
	// => 사용자가 전달하는 인자의 모양을 보고 함수를 생성합니다.

	// 1. 비교 정책으로 일반함수를 전달하는 경우
	std::sort(x, x + 10, cmp1);
	std::sort(x, x + 10, cmp2);
}