#include <iostream>
#include <vector>

// �Ʒ� �ڵ带 �� �����غ�����
// => C++20 ���� �����ϴ� range ��� ���̺귯���� ���� �Դϴ�.
template<typename T>
class reverse_view
{
	T& rng;	// �����̳ʸ� ������ ����
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return  rng.rbegin(); }
	auto end()   { return  rng.rend(); }
};

int main()
{
	// C++17 ���� Ŭ���� ���ø� ���� ��������
//	std::vector<int> v2 = { 1,2,3 }; // C++14 ������ int�� �� �ʿ�
//	std::vector      v3 = { 1,2,3 }; // C++17 ���ʹ� int ��������
	// ��κ��� �����Ϸ��� C++14�� �⺻ ������
	// => C++17 �̻��� ����Ϸ��� C++��� �����ϼž� �մϴ�.


	std::vector<int> v = { 1,2,3,4,5 };

	reverse_view rv(v); // C++17 ���ʹ� Ŭ���� ���ø���
						// ���ø� ���� ���������մϴ�.

	//for (auto& e : v )
	//for (auto& e : rv)
	for (auto& e : reverse_view(v) )
	{
		std::cout << e << ", ";
	}
}















