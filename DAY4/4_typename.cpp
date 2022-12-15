// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
//	Test::data  * p;	// 곱하기의 의미 ( 0 * 0 )
//	Test::DWORD * p; 	// 포인터 변수 p를 선언하는 모양
						// *의 의미는 곱하기가 아니라 포인터 연산자

	// "클래스이름::이름" 의 표기법에서 "이름"의 의미는
	// 1. 값 일수 있고		: static 멤버 데이타, enum 상수
	// 2. 타입 일수 있습니다.	: typedef 또는 using 등.. 

	// 아래 코드를 생각해 보세요.. 
	T::data  * p;
	T::DWORD * p;
}




int main()
{
	Test t;
	foo(t);
}



