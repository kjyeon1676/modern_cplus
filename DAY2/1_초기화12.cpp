#include <vector>

template<typename T, int N> struct array
{
	T buff[N];
	
	// array �� �ݵ�� = {} �ʱ�ȭ�� �����ؾ� �մϴ�.
	// 1. std::initializer_list ������ ������ �����ϰų�
	// 2. ��� �����ڵ� ������ ���ų�(+�����Լ���)
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 }; // ��� ��Ұ� ����!!
	array<int, 5> arr = { 1,2,3,4,5 }; // ��� ��Ұ� ���ÿ� .
}