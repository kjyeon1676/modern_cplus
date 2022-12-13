// 4_rvalue - 87 page
int x = 0;
int  foo() { return x;}
int& goo() { return x; }

// lvalue : 등호의 왼쪽, 오른쪽에 모두 놓일수 있다.
//			이름(id)이 있고, 단일 문장을 벗어나서도 사용가능
//			주소연산자로 주소를 구할수 있다.
//			참조를 반환하는 함수
// 
// rvalue : 등호의 오른쪽에 놓일수 있다.
//			이름(id)이 없고, 단일 문장에서만 사용가능
//			주소연산자로 주소를 구할수 없다.
//			값을 반환하는 함수
//			정수/실수형 리터럴(0, 10, 3.4), 임시객체 

int main()
{
	int v1 = 10, v2 = 10;
	
	v1 = 10;	// "v1" : lvalue,   "10" : rvalue
	10 = v1;
	v2 = v1;

	int* p1 = &v1; // ok
	int* p2 = &10; // error

	foo() = 10; // error
	goo() = 10; // ok 
}









