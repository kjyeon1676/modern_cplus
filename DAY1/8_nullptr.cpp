// 8_nullptr - 29page

int main()
{
	// C++98 시절
	int  n1 = 0;
	int* p1 = 0;	// 0 은 정수지만 포인터로 암시적 형변환 됩니다.

	int* p2 = n1;	// error. 리터럴 0만 포인터로 암시적 형변환됩니다.
					// 0으로 초기화된 변수는 포인터 초기화에 사용안됩니다.
	int* p3 = 10;   // error. 리터럴 0만 포인터로 변환 가능.

	// C++11 부터는 0 대신 nullptr 사용하세요
	int* p4 = 0;		// bad
	int* p5 = nullptr;	// good

	// 장점 1. 가독성이 좋다.
	auto ret = foo();
	if (ret == 0) {} // ret 가 정수 인지 ? 포인터 인지 알수 없다.
	if (ret == nullptr) {} // ret 는 포인터!
}