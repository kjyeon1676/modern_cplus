#include <iostream>

// �Լ� ���ڷ� auto ����� "C++20" ���� ���� �մϴ�.
// void foo(auto n) {} 


int main()
{
	// generic lambda
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2); // ������ �ƴ�����
							// ����� 6
	
	// �ٽ� 1. Generic lambda
	// => C++14 ���� ���� ǥ������ ���ڷ� auto ��밡���մϴ�
	// => �Ϲ��Լ��� C++20 ���� ���ڷ� auto ��밡���մϴ�.
	auto f1 = [](auto a, auto b) { return a + b; };

	std::cout << f1(1, 2) << std::endl;		// operator(int, int)����
	std::cout << f1(1.1, 2.1) << std::endl; // operator(double, double)����
	std::cout << f1(1,   2.1) << std::endl; // operator(int, double)����
	std::cout << f1(1.1, 2 ) << std::endl;
}

// generic ���� ǥ������ ���� 
// => operator() �� �Լ� ���ø����� ����� ���°�
// => 2���� ���ڰ� ���� �ٸ� ���ø� �Ķ���� ���
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};