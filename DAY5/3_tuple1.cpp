// 8_tuple1 - 245 page
#include <tuple>
#include <iostream>

int main()
{
	// pair : ���� �ٸ� Ÿ�� 2���� ���� - C++98
	std::pair<int, double> p(1, 2.3);

	// pair �� 3���� �����Ҽ��� �ֽ��ϴ�
	std::pair<int, std::pair<int, double>> p2(1, { 1, 2.3 });


	// C++11 ���� tuple �� ����ϸ�
	// ���δٸ� Ÿ�� N ���� �����Ҽ� �ֽ��ϴ�.
	std::tuple<int, double, char> tp(1, 3.4, 'A');

	// ����� ������ std::get ���� �մϴ�
	std::get<0>(tp) = 99;

	std::cout << std::get<0>(tp) << std::endl;
}