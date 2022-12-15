#include <iostream>
// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// 멤버 데이타 캡쳐 ?
		//auto f = [](int a) { return a + data; }; // error


		// auto f = [data](int a) { return a + data; }; // error
				// => data 는 멤버 변수 이지, 지역변수는 아닙니다.


		// 핵심 1. this 를 캡쳐하면 멤버 데이타를 접근 할수있습니다.
		// => 실제 캡쳐한것은 data 가 아닌 this 인데
		//    "this->data" 처럼 사용하지 않고, "data" 로만 사용합니다.
		// => "data=0" 같이 수정도 가능합니다. 원본이 변경됩니다.
		auto f = [this](int a) { data = 15; return a + data; }; // ok

		f(0);

		std::cout << data << std::endl; // 15


		// C++17 부터 *this 캡쳐도 지원 합니다.
		// => 이 경우는 "data=15" 처럼 수정하려고 하면 에러 입니다.
		auto f2 = [*this](int a) { //data = 15; 
									return a + data; }; 
	}
};

int main()
{
	Test t;
	t.foo(); 
}

