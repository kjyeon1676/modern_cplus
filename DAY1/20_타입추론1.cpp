// 20_타입추론1 - 69 page
// 타입 추론 문법

int main()
{
	int x[3] = { 1,2,3 };

	auto n = x[0]; // "int n = x[0]"


	const int c = 10;

	auto a = c; // 1. int		=> int
				// 2. const int

	// type deduction(type inference 라고도 합니다.)
	// => 타입 추론, 타입 연역
	// => 표현식의 보고 컴파일러가 타입을 추론하게 되는 경우
	// 
	// 1. template
	// 2. auto
	// 3. decltype 

	// => 1, 2가 동일한 규칙을 사용합니다.
}