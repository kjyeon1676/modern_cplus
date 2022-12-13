// 함수 인자로
// int& : int 타입의 lvalue 만 받겠다는 것
// int&&: int 타입의 rvalue 만 받겠다는 것
// 
// T& : 임의 타입의 lvalue 만 받겠다는 의미


template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 5;

	// 1. 타입을 명시적으로 전달하는 경우
	f4<int>(? );	// T=?			T&&=?			생성된함수:f4(?)
	f4<int&>(? );	// T=?			T&&=?			생성된함수:f4(?)
	f4<int&&>(? );  // T=?			T&&=?			생성된함수:f4(?)

	// 2. 타입을 명시적으로 전달하지 않은 경우
}