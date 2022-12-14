// 3_함수객체4 -  137 page 제일 윗부분내용

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }


// 핵심 1. 인라인 치환은 "컴파일 시간"에 이루어 집니다.
// 핵심 2. 인라인 함수라도, 함수 포인터에 담아서 사용하면
//         인라인 치환 될수 없습니다.
int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 기계어 코드 치환, 


	int(*f)(int, int) = &Add2;

//	if (사용자입력 == 1) f = &Add1;

	f(1, 2); // 치환 ? 호출 ?
}

