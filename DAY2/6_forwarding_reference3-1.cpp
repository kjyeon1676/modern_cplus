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
	f4<int>(5 );	// T=int		T&&=int&&		생성된함수:f4(int&&)
	f4<int&>(n);	// T=int&		T&&=int& &&		생성된함수:f4(int&)
	f4<int&&>(5);   // T=int&&		T&&=int&& &&	생성된함수:f4(int&&)

	// 2. 타입을 명시적으로 전달하지 않은 경우
	// => 함수 인자를 보고, 함수를 생성할수 있도록 T의 타입을 결정

	f4(n);	// T=int 로 결정하면 f4(int&&) 함수 생성하므로 error
			// T=int&로 결정하면 f4(int&) 함수 생성.. ok.. 
			// 그래서 이순간 T=int&로 결정.  f4(int&) 함수 생성

	f4(5);	// T=int 로 결정, 생성된 함수는  f4(int&&) 함수 생성
}