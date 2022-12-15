#include <iostream>
#include <type_traits>

// static_assert : ������ �������� ������ �׻� ����!!
// �ʿ��Ѱ�       : ������ �������� �ĺ����� �����Ҽ� ������ ?
//					=> �ٸ� �Լ��� �ִٸ� �ٸ� �Լ��� ����Ҽ� �ְ� �ȴ�.
// 
// 2 ������ �ִ� ������� ���ϴ� �Լ��� ������ ���ô�.
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
	gcd(3.1,  5.4);	// double ���� ���
	gcd(3.1f, 5.4f);// float �̹Ƿ� T ���� ���.
					// ������ �ƴϹǷ� error.
}