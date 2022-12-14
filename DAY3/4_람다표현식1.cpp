// 2_람다표현식1 - 127 page

int add(int a, int b) { return a + b; }


// foo : 인자로 함수 포인터(주소)를 요구합니다
void foo(  int(*f)(int, int) )
{
}

int main()
{
	foo(add); // ok 

	// 람다 표현식 
	// => 익명의 함수를 만드는 문법
	// => 함수이름(주소)가 필요한 곳에 함수의 구현자체를 사용하는 문법

	// [] : lambda introducer. 람다 표현식이 시작됨을 알리는 기호. 

	foo( [](int a, int b) { return a + b; } ); // ok 
}