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

	// 장점 : 비교 정책을 여러번 교체 해도 생성된 sort() 함수는 한개이다.
	//        코드 메모리 증가 안함.
	// 
	// 단점 : 비교 정책이 인라인 치환 될수 없다.. 느리다.

	std::sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int)) 모양의 함수생성
	std::sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int)) 모양의 함수생성


	// 2. 비교 정책으로 함수객체를 전달하는 경우

	// 장점 : 비교 정책함수 객체의 operator() 연산자가 인라인 치환 될수있다
	//        빠르다.

	// 단점 : 비교 함수객체를 교체한 횟수 만큼의 sort() 기계어 코드 생성
	//        코드 메모리 증가
	Less f1;
	Greater f2;

	std::sort(x, x + 10, f1); // sort(int*, int*, Less) 모양의 함수 생성
	std::sort(x, x + 10, f2); // sort(int*, int*, Greater) 모양의 함수 생성
}