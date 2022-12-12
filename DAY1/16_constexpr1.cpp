// 16_constexpr1
int main()
{
	int n = 10;
	const int c1 = 10; // 컴파일 시간 상수
						// c1의 값을 컴파일러가 알수 있다.
	const int c2 = n;	// 실행시간 상수
						// c2의 값을 컴파일 시간에는 알수 없다.

	// 다음중 에러를 모두 고르세요
	int arr1[10]; // ok
	
	int arr2[n ]; // C89 : 배열의 크기는 컴파일시간에 알아야 한다.
				  // C99 : 배열의 크기로 변수도 가능.				
				  // g++ : 배열의 크기로 변수 가능
				  // VC  : 배열의 크기로 변수 안됨.
					// error.

	int arr3[c1]; // ok. 
	int arr4[c2]; // error. 
}
