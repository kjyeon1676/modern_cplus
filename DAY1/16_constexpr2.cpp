// modern C++ 에서 constexpr 은 3가지 용도 입니다.
// 1. constexpr 상수
// 2. constexpr 함수
// 3. constexpr if 

// constexpr 함수 : 인자의 값을 컴파일 시간에 알수 있고,
//				    함수호출식이 놓인 곳이 컴파일 시간에 값을 요구하면
//                  함수호출을 컴파일 시간에 실행
constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}
int main()
{
	int n = 5;

	int arr1[Factorial(5)]; // ok.. 컴파일 시간에 함수 호출까지 완료
							// 컴파일 하면 "int arr1[120]" 이 됨. 

//	int arr2[Factorial(n)]; // error. 인자가 변수 이므로 
							// 컴파일 시간에 함수를 수행할수 없음.
						
	int s2 = Factorial(n);  // ok.. 실행시간에 수행.

	int s3 = Factorial(3);  // ? 컴파일 시간 ? 실행시간 ?
							// 표준에 정의되어 있지 않음. 
							// 컴파일러마다 다를수 있음.		

	const int s4 = Factorial(3); // 위 와 마찬가지.

	constexpr int s5 = Factorial(3); // 반드시 컴파일 할때 해달라는 의미.
}

// 참고 C++20 에는 consteval function 이 등장합니다.
// => 컴파일 할때만 실행가능.
//consteval int square(int a) { return a * a; }

//square(3); // ok
//square(n); // error. 변수 안됨.