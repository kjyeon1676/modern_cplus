// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// �ݺ��ڸ� ��� ���
	// 1. C++98 ��Ÿ��
	// ���� : �����̳� ����� �ݺ��� Ÿ�Ե� �����ؾ� �Ѵ�.
	// std::vector<int>::iterator p1 = v.begin();
	// std::vector<int>::iterator p2 = v.end();

	// 2. C++11 ��Ÿ�� auto ���
	// auto p1 = v.begin();
	// auto p2 = v.end();		// v�� raw array �ΰ��� ���� �߻�

	// ��� �Լ� begin ���� �Ϲ��Լ� begin ���
	// => v �� STL �����̳� �Ӿƴ϶� raw array �� ��밡��
	auto p1 = std::begin(v);
	auto p2 = std::end(v);		

	// auto sz1 = v.size(); // v�� �����̳ʸ� ����
	auto sz2 = std::size(v); // v�� �����̳� �Ǵ� raw array �� ����

	//------------------------------
	// C++20 ���� ���ο� begin �� �����մϴ�.
	
	// ���� begin �� ������.
	// => �����̳ʰ� �ӽð�ü�� ��쿡 ���� ����� �Ǿ����� �ʴ�.
	auto p3 = std::begin( std::vector<int>{1, 2, 3} );
	int n = *p3; // runtime error


	// C++20 �� ���ο� begin ��
	// => �ӽð�ü�� ���ڷ� ���� ���
	// => Dangling iterator ��� ������ ��ȯ�մϴ�.
	// => Dangling iterator �� *������ ���� �ʽ��ϴ�.
	auto p4 = std::ranges::begin(std::vector<int>{1, 2, 3});

	int n = *p4; // compile error
}