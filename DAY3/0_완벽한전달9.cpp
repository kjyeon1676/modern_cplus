#include <iostream>

void f0() {}
void f1(int) {}
void f3(int a, double d, int& r) {}

// ���ڰ� �Ѱ� �� �ƴ϶� �������� �Ϻ��� ������ �ǰ� �Ϸ���
// �������� ���ø��� ����ϸ� �˴ϴ�.(�ݿ���)
template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f( std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	
	chronometry(f0);
	chronometry(f1, 10);
	chronometry(f3, 10, 3.4, n);

}
