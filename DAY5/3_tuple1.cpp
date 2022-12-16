// 8_tuple1 - 245 page
#include <tuple>
#include <iostream>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	// pair 로 3개를 보관할수도 있습니다
	std::pair<int, std::pair<int, double>> p2(1, { 1, 2.3 });


	// C++11 부터 tuple 을 사용하면
	// 서로다른 타입 N 개를 보관할수 있습니다.
	std::tuple<int, double, char> tp(1, 3.4, 'A');

	// 요소의 접근은 std::get 으로 합니다
	std::get<0>(tp) = 99;

	std::cout << std::get<0>(tp) << std::endl;
}