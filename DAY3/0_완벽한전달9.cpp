#include <iostream>

void f0() {}
void f1(int) {}
void f3(int a, double d, int& r) {}

// 인자가 한개 뿐 아니라 여러개를 완벽한 전달이 되게 하려면
// 가변인자 템플릿을 사용하면 됩니다.(금요일)
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
