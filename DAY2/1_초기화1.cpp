// 초기화 - 55 page
#include <iostream>

int x = 10;

class Test
{
	// C++11 부터 멤버 데이타를 만들때 직접 초기값을 지정할수 있습니다.
	// => 쉬워 보이지만 원리가 중요합니다.
	int value1 = 0;		// 이렇게 0으로 초기화 하는 것은 좋지만
	int value2 = ++x;	// 절대, 이런 코드는 사용하지 마세요..!
public:	
	Test() {}
	Test(int n) : value2(n) {}
};
/*
// 위 코드의 원리!!!
// => 멤버 초기값을 생성자의 초기화 리스트로 옮기게 됩니다.
// => 아래 코드 참고
class Test
{
	int value1;// = 0;
	int value2;// = ++x;
public:
	Test()      : value1(0), value2(++x) {}
	Test(int n) : value1(0), value2(n) {}
};
*/
int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // 예측해보세요. ? 11
}