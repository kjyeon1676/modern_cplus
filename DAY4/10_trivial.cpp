#include <iostream>
#include <type_traits>

// Trivial : �ϴ����� "�ڸ��ϴ�" �� �ǹ��� �ܾ�
//			 => Ư�� �Լ��� ����ڰ� ������ �ʰ�
//           => �����Ϸ��� ������� Ư�� �Լ��� �ϴ����� �θ� �˷��� ��� �����Ѵ�.
// 
// Trivial Constructor : �����ڰ� �ϴ� ���� ����!
// Trivial Destructor  : �Ҹ��ڰ� �ϴ� ���� ����!
// Trivial Copy Constructor  : ��� ����� ���� ���� �Ҷ�.

class A {};

class B 
{
public:
	virtual void foo() {}
};

int main()
{
	// B�� �����ڴ� trivial �ұ�� ?
}