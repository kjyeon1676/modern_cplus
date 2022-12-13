#include <iostream>

// decltype() 규칙을 이해하기 위해 알아야 하는 선수 지식

int x = 0;

int  f1() { return x; }	// x의 값인 "0"을 반환
int& f2() { return x; } // x의 별명을 반환

int main()
{
	f1() = 20;	// error. "0 = 20" 의 의미
	f2() = 20;  // ok..   "x = 20" 의 의미

	// 핵심 : 함수가 참조를 반환하면 함수 호출을 등호의 왼쪽에 놓을수
	//        있습니다.(흔히, "lvalue 가 될수 있다" 라고 합니다.)
}