#include <iostream>

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple< Types...>
{
	using base = tuple< Types...>;

	T value;

	tuple() = default;
	tuple(const T& n, const Types& ... args)
		: value(n), base(args...) {}

	static constexpr int N = base::N + 1;
};

int main()
{
//	tuple<>
//	tuple<		       short>					// 2 ����
//	tuple<	   double, short>					// 3.4 ����
	tuple<int, double, short> t3(1, 3.4, 2);	// 1 ����

	std::cout << t3.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t3).value << std::endl; // 3.4 ������ �غ�����

	std::cout << static_cast<tuple<short>&>(t3).value << std::endl; // 2 ������ �غ�����.

	// get �� ������ ���ô�.
	double d = get<1>(t3); 
}
template<int N, typename T>
Ʃ���� T Ÿ���� N ���� ����� Ÿ��&
get(T& tp)
{
	return static_cast<T�� N��° �θ� Ÿ��&>(tp).value;
}
// �ᱹ get �� �ϼ��Ϸ���
// => ������ tuple Ÿ�� T�� N��° ����� Ÿ�� ���ϱ�
// => ������ tuple Ÿ�� T�� N��° ���Ŭ���� Ÿ�� ���ϱ�
// �Դϴ�.










