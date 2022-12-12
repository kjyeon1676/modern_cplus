// 16_constexpr1-1

int main()
{
	int n = 10;
	
	const int c1 = 10; // ok
	const int c2 = n;  // ok

	// C++11 constexpr : 컴파일 시간 상수를 만드는 키워드
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error. 변수값으로 초기화 안됨


}