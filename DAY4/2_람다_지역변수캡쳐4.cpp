#include <iostream>
#include <vector>
#include <algorithm>

struct People
{
	// name, addr
	int age;
	People(int a) : age(a) {}
};

int main()
{
	std::vector<People> v;
	v.emplace_back(10); // v.push_back(People(10)) �ǹ�.
	v.emplace_back(20);
	v.emplace_back(15);

	// ���̰� 15���� ����� ã�� �ʹ�. ?
	auto ret = std::find_if(v.begin(), v.end(),
		[](const People& p) { return p.age == 15; });

	// ���̰� k�� �� ����� ã�� �ʹ�. ?
	int k = 15;
	auto ret2 = std::find_if(v.begin(), v.end(),
						[k](const People& p) { return p.age == k;} );

	// �� �ڵ嵵 �ᱹ, std::find_if �ȿ� �����Լ��� �����ϴµ�..

	// "�����Լ� �� �ƴ϶� �������� k" �� ���� �����ϴ� �ڵ� �Դϴ�.
	// ��, Ŭ���� �Դϴ�.

	// ���� ǥ���ĵ� �ᱹ �Լ� ��ü�� ����� ǥ����̹Ƿ�
	// "Ŭ����" �� �ɼ� �ֽ��ϴ�.!!!
	// => Ŭ���� ������ �� ������ ������..
}







