#include <list>

// STL �����̳ʿ��� ��� �޴� ���� �������� �ʽ��ϴ�.
class MyList : public std::list<int>
{
public:
	using std::list<int>::list;

	void dump() {}
};

int main()
{
	// MyList �� STL list ó�� ����ϰ� �ͽ��ϴ�.
	MyList st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList st2(10);
	MyList st3 = { 1,2,3,4,5 };
}




