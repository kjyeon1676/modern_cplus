#include <iostream>
#include <type_traits>


// std::enable_if<조건, 타입>::type  에서 "::type" 은
// 
// => 조건이 true  이면 "타입"
// => 조건이 flase 이면 "::type" 은 없습니다.
//    => SFINAE 규칙에 의해서 "::type" 이 없을때 에러가 아니라
//		 후보에서 빠지게 됩니다.

// 의미 : 조건이 true 이면 사용하고!!
//		  조건이 false 이면 사용하지 않겠다는 의도(에러가 아닌 후보제외)
template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T>::type 

std::enable_if_t< std::is_integral_v<T>, T>   // C++14 버전

gcd(T a, T b)
{
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
	gcd(3.1, 5.4);	
	gcd(3.1f, 5.4f);
}