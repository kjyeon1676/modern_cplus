// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

// 함수 인자로
// int& : int 타입의 lvalue 만 받겠다는 것
// int&&: int 타입의 rvalue 만 받겠다는 것
// 
// T& : 임의 타입의 lvalue 만 받겠다는 의미


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 5;

	// 1. 사용자가 타입을 명시적으로 전달하는 경우
	f3<int>(n );	// T=int	T&=int&		생성된함수:f3(int& a)
	f3<int&>(n );	// T=int&	T&=int& &	생성된함수:f3(int& a)
	f3<int&&>(n );	// T=int&&	T&=int&& &	생성된함수:f3(int& a)

	// 2. 사용자가 타입을 전달하지 않으면 
	// => 컴파일러는 함수 인자를 보고 함수를 생성하려고 노력합니다.
	f3(10);	// T=int, int&, int&& 등으로 해도 모두 10을 받을수 없다
			// 컴파일 에러!
	f3(n);	// T=int 로 결정.!
}











template<typename T> void f4(T&& a)
{
}
