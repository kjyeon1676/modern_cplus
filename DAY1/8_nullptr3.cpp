//8_nullptr3
#include <iostream>

void foo(int)    { std::cout << "int" << std::endl; }
void foo(double) { std::cout << "double" << std::endl; }
void foo(bool)   { std::cout << "bool" << std::endl; }
void foo(char*)  { std::cout << "char*" << std::endl; }

int main()
{
	foo(0);		// int,  0은 정수형 리터럴
	foo(0.0);	// double, 0.0 은 실수형 리터럴
	foo(false);	// bool
	foo(nullptr); // nullptr 은 포인터형 "리터럴입니다."
				  // C++에서 변수가 아닌 리터럴로 구분합니다.

	// nullptr 의 데이타 타입은 std::nullptr_t 라는 타입입니다.
	std::nullptr_t arg = nullptr;

	// std::nullptr_t 타입은 모든 종류의 포인터로 암시적 형변환 됩니다.
	int* p1 = arg;
	char* p2 = arg;
}



