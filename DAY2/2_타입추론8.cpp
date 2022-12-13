// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	decltype(p)		d1; // 규칙1. 적용
						// int* d1;
	
	// 규칙 2. () 안에 "심볼이름과 연산자등을 포함한 표현식이 있을때"
	// => 해당 표현식이 
	// 등호의 왼쪽에 올수 있다면(lvalue) : 참조 타입
	// 등호의 왼쪽에 올수 없다면(rvalue) : 값 타입
	decltype(*p)	d2;		// "*p = 0" 표현식이 문제 없다.
							// int& d2;		초기값 없어서 에러.

	decltype(x[0])	d3;		// "x[0] = 0" 은 문제 없다.
							// int& d3;		초기값 없어서 에러.

	decltype(n) d;		// "n = 10" 처럼 왼쪽에 올수 있지만
						// 이 경우는 심볼의 이름만 있으므로 "규칙 1"
						// int d;
					

	decltype(n + n) d4;	// "n + n = 10" 은 안됩니다.
						// int d4;

	decltype(++n)   d5; // "++n = 10" 은 됩니다.
						// int& d5
						
						
	decltype(n++)   d6; // "n++ = 10" 은 안됩니다.
						// int d6;

	// auto vs decltype
	int y[3] = { 1,2,3 };

	decltype(y[0]) d7;	// int& d7;
	auto a = y[0];		// int a,   
						// y[0]은 참조 타입인데
						// auto 는 우변의 참조를 버리고 타입을 결정
						// 하므로!
			
}

