// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

// 함수 인자로
// int& : int 타입의 lvalue 만 받겠다는 것
// int&&: int 타입의 rvalue 만 받겠다는 것
// 
// T& : ?


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 5;

	// 1. 사용자가 타입을 명시적으로 전달하는 경우
	f3<int>(? );	// T=?		T&=?		생성된함수:f3(? a)
	f3<int&>(? );	// T=?		T&=?		생성된함수:f3(? a)
	f3<int&&>(? );	// T=?		T&=?		생성된함수:f3(? a)
}











template<typename T> void f4(T&& a)
{
}
