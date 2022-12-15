#include <iostream>
#include <type_traits>

// static_assert : 조건을 만족하지 않으면 항상 에러!!
// 필요한것       : 조건을 만족하지 후보에서 제외할수 없을까 ?
//					=> 다른 함수가 있다면 다름 함수를 사용할수 있게 된다.
// 
// 2 정수의 최대 공약수를 구하는 함수를 생각해 봅시다.
template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>,
						"Error T is not Integer");
	return 0;
}

double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);	// double 버전 사용
	gcd(3.1f, 5.4f);// float 이므로 T 버전 사용.
					// 정수가 아니므로 error.
}