#include <iostream>
#include <vector>
#include <algorithm>

// �Լ���ü�� ���� 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };


	// �־��� �������� "3�� ���"�� ã�� �ʹ�. 
	// => 3��° ���ڷ� ���޵Ǵ� �Լ��� "�����Լ�" �̾�� �մϴ�.
	//auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;
	std::cin >> k;

	// �־��� �������� "k�� ���"�� ã�� �ʹ�. 
	auto p1 = std::find_if(v.begin(), v.end(), 
						"foo + ��������k");
}

// �ϱ� ��ü ( first class object )
// => �Լ� ���ڷ� ���� ������ ��ü 
// => C/C++ �� �Ϲ� �Լ��� ��� �ϱ� ��ü �Դϴ�.


// Ŭ����( Closure )
// => �ڽ��� ���� ������ ���������� ĸ���Ҽ� �ִ� �ϱ� ��ü

