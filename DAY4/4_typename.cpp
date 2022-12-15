// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> typename T::DWORD foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
//	Test::data  * p;	// 곱하기의 의미 ( 0 * 0 )
//	Test::DWORD * p; 	// 포인터 변수 p를 선언하는 모양
						// *의 의미는 곱하기가 아니라 포인터 연산자

	// "클래스이름::이름" 의 표기법에서 "이름"의 의미는
	// 1. 값 일수 있고		: static 멤버 데이타, enum 상수
	// 2. 타입 일수 있습니다.	: typedef 또는 using 등.. 

	// 아래 코드를 생각해 보세요.. 
	// 의존이름(dependent name)
	// => "T::이름" 처럼 템플릿 인자에 의존한 이름
	// => 컴파일러는 기본 적으로 "이름"을 "값으로 해석"
	// => 의존이름을 값이 아닌 타입으로 해석되게 하려면 typename 필요
	T::data  * p;
	//T::DWORD * p; // error. 단 VC등에서 에러가 발생하지 않을수 있지마
					// C++ 문법상 에러 입니다.
	typename T::DWORD* p;

	return 0;
}





int main()
{
	Test t;
	foo(t);
}



