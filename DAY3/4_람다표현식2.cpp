#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// v���� 3�� ã�� �ʹ�.
	auto p1 = std::find(v.begin(), v.end(), 3);

	std::cout << *p1 << std::endl;


	// v���� 1��° ������ "3�� ���"�� ã�� �ʹ�.?
	
	// std::find    : ��  �˻�, ������ ���ڷ� "��" ����
	// std::find_if : ���� �˻�, ������ ���ڷ� "�Լ�" ����

	auto p2 = std::find_if(v.begin(), v.end(), foo ); // C++98 ��Ÿ��

	auto p3 = std::find_if(v.begin(), v.end(),  
				[](int n) { return n % 3 == 0; }); // C++11 ��Ÿ��

}


