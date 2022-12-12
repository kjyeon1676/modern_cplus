// 아래 코드가 왜 에러인지 생각해 보세요 ?
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;	// int 타입을 * 하므로 error
	}
};
int main()
{
	A a;
}
*/
template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10;	
	}
};

int main()
{
	A<int>  a;
	a.foo();
}
// 핵심 
// 인스턴스화      : 템플릿으로 부터 실제 C++ 함수/클래스를 만드는 과정
// 지연된인스턴스화 : 사용된 템플릿만 인스턴스화가 된다는 개념