#include <iostream>
#include <type_traits>

// ���� C++�� "Ư�� Ÿ��" �� ���� �Լ� �����ε���
// ���� �մϴ�.
void foo(int)    {}
void foo(double) {}

// "Ÿ��"�� �ƴ� "Ư�� ������ �����ϴ� Ÿ�Ե�"�� ���� �����ε��� ������
// ���� ������� ?
//void goo(�����Լ����ִ�Ŭ������) {}
//void goo(�����Լ�������Ŭ������) {}

template<typename T>
void goo(T arg)
{
	std::cout << "�����Լ��� �ִ� Ÿ��" << std::endl;
}
template<typename T>
void goo(T arg)
{
	std::cout << "�����Լ��� ���� Ÿ��" << std::endl;
}
class Object
{
public:
	virtual void f() {}
};
int main()
{
	Object obj;
	goo(obj);
}