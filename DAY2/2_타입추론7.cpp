// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// decltype(exp) : 괄호 안의 표현식(exp)을 보고 타입을 결정
	// 규칙 1. () 안에 심볼의 이름만 있는 경우
	// => 해당 심볼의 선언을 보고 동일한 타입으로 결정
	decltype(n) d1; // int d1;
	decltype(r) d2; // int& d2;		초기값이 없으므로 컴파일 에러
	decltype(c) d3; // const int d3;초기값이 없으므로 컴파일 에러
	decltype(p) d4; // int* d4;

	// auto vs decltype
	decltype(r) d5; // int& d5
	auto a = r;		// int  a		우변의 참조 버림
}