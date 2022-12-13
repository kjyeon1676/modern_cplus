int main()
{
	int x[3] = { 1,2,3 };

	auto a = x[0];		// int a;
	decltype(x[0]) d;	// int& d;


	// 배열과 타입 추론
	// 현재 x의 타입은 "int[3]" 입니다.

	auto a1 = x;	// 1. int a1[3] = x; 로 추론, 그런데, 에러
					// 2. int* a1 = x; 로 추론하면 에러 아님. 
					// 답은 2번.  따라서
					// auto : int*

	auto& a2 = x;	// int(&a2)[3] = x; 로 추론되는데. 에러 아님.
					// 따라서 이 경우
					// auto : int[3];
					// a2   : int(&)[3]

	decltype(x) d; // int d[3]; ...  ok.. 
}

