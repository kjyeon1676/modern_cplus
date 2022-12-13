// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

// list	  : 떨어진 메모리, 모든 요소 힙
// vector : 연속된 메모리, 모든 요소 힙
// initializer_list : 연속된 메모리, 모든 요소가 스택,
//					  시작주소와 갯수(또는 마지막 주소)로 관리
//				      초기화를 위해 특별히 정의된 문법이 적용됨.

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// C++11 에서 초기화를 돕기위해 만든 타입
	// => 내부적으로 "포인터 2개(vc)" 또는 "포인터 한개+갯수(g++)"로 관리
	// => 데이타 자체는 아래 처럼 함수 안에 만든경우 stack 에..

	std::initializer_list<int> e = { 1,2,3,4,5 };

	auto p1 = e.begin();
	auto p2 = e.end();

	foo(e);
	foo({ 1,2,3,4,5 });
	foo({ 1,2,3,4,5,6,7,8,9,10 });
}

