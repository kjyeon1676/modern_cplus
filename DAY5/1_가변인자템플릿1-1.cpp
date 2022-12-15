// 1_가변인자템플릿1-1

// 타입 인자가 한개인 함수 템플릿
// => 인자가 한개인 함수를 생성할때 사용하는 틀.. 
template<typename T> void foo(T arg)
{
}

// 가변 인자 함수 템플릿
// => ... 의 위치 정확히 알아 두세요..
// => 인자가 N개인 함수를 생성할수 있는 템플릿
template<typename ... Types> void goo(Types ... arg)
{
}

int main()
{
	foo(1);		// foo(int) 생성
	foo(3.4);	// foo(double) 생성

	goo(1);      // goo(int)
	goo(3.4);	 // goo(double) 생성
	goo(1, 3.4); // goo(int, double) 생성
	goo();		 // goo() 생성..
}