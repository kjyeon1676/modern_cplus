#include <iostream>
#include <vector>

// �Ʒ� �ڵ带 �� �����غ�����
// => C++20 ���� �����ϴ� range ��� ���̺귯���� ���� �Դϴ�.
template<typename T>
class reverse_view
{
	T& rng;
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return  rgn.rbegin(); }
	auto end()   { return  rgn.rend(); }
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	reverse_view rv(v); // C++17 ���ʹ� Ŭ���� ���ø���
						// ���ø� ���� ���������մϴ�.

	//for (auto& e : v )
	for (auto& e : rv)
	{
		std::cout << e << ", ";
	}
}















