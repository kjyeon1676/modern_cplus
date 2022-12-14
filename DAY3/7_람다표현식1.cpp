// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional> // �� �ȿ� C++ ǥ�ؿ� less<> �� greater<> �� �ֽ��ϴ�.
					  // C++98
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort �ϰ� �ʹٸ�
	
	// 1. �� ��å�� �������� ������ - ���� ���� ����
	// std::sort(v.begin(), v.end()); 

	// 2. ����å���� �Ϲ��Լ� ��� - �� ��å�� �ζ��� ġȯ �ȵ�
	//std::sort(v.begin(), v.end(), cmp1); 

	// 3. ����å���� �Լ� ��ü ���
	// => �̹� C++ ǥ���� <functional> ����� ������.(C++98 ����)
	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>() ); // �ӽð�ü�� ����
	std::sort(v.begin(), v.end(), std::less()); // C++17 ���� ����.


	// 4. C++11 ���ʹ� ���� ǥ���� ��밡��
	
	std::sort( v.begin(), v.end(), [](int a, int b) { return a < b; }); 

	// ���� ǥ������ ����... 
	// �����Ϸ��� �Լ� ��ü�� �����ϴ� ��. 

	// �� ������ ���� �����Ϸ��� �Ʒ� �ڵ带 ����..
	class CompilerGeneratedName
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};
	std::sort(v.begin(), v.end(), CompilerGeneratedName() );

}





